#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int beolvas(donor **u, char *fName, int *l) {
  FILE *fp = NULL;
  char ch;
  int i;

  if (!(fp = fopen("donorok", "r"))) {
    printf("Fajl megnyitasa sikertelen.\n");
    if (retry()) {
      return 1;
    } else {
      printf("Program kilep.\n");
      return 2;
    }
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      (*l)++;
    }
  }

  if (!(*u = (donor *)malloc(*l * sizeof(donor)))) {
    printf("Nincs eleg memoria.\n");
    if (retry()) {
      return 1;
    } else {
      printf("Program kilep.\n");
      return 2;
    }
  }

  rewind(fp);

  for (i = 0; i < *l; i++) {
    fscanf(fp, "%d%s%s%s%d%s", &(*u)[i].id, (*u)[i].name, (*u)[i].btype,
           (*u)[i].email, &(*u)[i].times, (*u)[i].ldate);
  }

  fclose(fp);
  printf("Fajl beolvasva.\n");
  return 0;
}

int bkeres(donor *u, int l) {
  char type[4];
  int kereses;

  printf("Keresett vercsoport: ");
  scanf("%s", type);

  if ((kereses = keres(u, l, type)) == -1) {
    printf("Vercsoport nem talalhato.\n");
    if (retry()) {
      return 1;
    } else {
      return 0;
    }
  } else {
    for (int i = 0; i < l; i++) {
      if (stringCompare(u[i].btype, type)) {
        FILE *fp[i];
        printf("ID: %d\nNev: %s\nVercsoport: %s\nEmail: %s\nDonaciok szama: "
               "%d\nUtolso donacio: "
               "%s\n\n",
               u[i].id, u[i].name, u[i].btype, u[i].email, u[i].times,
               u[i].ldate);
        fp[i] = fopen(u[i].email, "w");
        fclose(fp[i]);
      }
    }
  }

  return 0;
}

int stringCompare(char num1[], char num2[]) {
  int i = 0, flag = 0;
  while (num1[i] != '\0' && num2[i] != '\0') {
    if (num1[i] != num2[i]) {
      flag = 1;
      break;
    }
    i++;
  }
  if (flag == 0 && num1[i] == '\0' && num2[i] == '\0')
    return 1;
  else
    return 0;
}

int datumBe(char date[11]) {
  int ev, honap, nap, datum = 0;
  printf("UDVOZLI ONT A VERADOK NYILVANTARTASAT SEGITO PROGRAM!\n\n");
  while (datum != 1) {
    printf("Adja meg a mai datumot: ");
    scanf("%d.%d.%d.", &ev, &honap, &nap);
    if (ev >= 1000 && ev <= 9999) {
      if (honap >= 1 && honap <= 12) {
        if (nap >= 1 && nap <= 30) {
          datum = 1;
        } else {
          system("cls");
          printf("Hibas nap.\n");
        }
      } else {
        system("cls");
        printf("Hibas honap.\n");
      }
    } else {
      system("cls");
      printf("Hibas ev.\n");
    }
  }
  system("cls");
  snprintf(date, 11, "%d.%d.%d.", ev, honap, nap);
  return *date;
}

int emailHelyes(char *eTemp) {
  int i = 0, dotIndex, atIndex, numberOfDots = -1, numberOfAts = -1, diff;

  while (eTemp[i]) {
    if (eTemp[i] == '.') {
      dotIndex = i;
      numberOfDots++;
    }
    if (eTemp[i] == '@') {
      atIndex = i;
      numberOfAts++;
    }
    i++;
  }

  if ((diff = dotIndex - atIndex) < 0) {
    return 1;
  }
  if (numberOfDots || numberOfAts) {
    return 1;
  }
  if (!dotIndex || !atIndex || dotIndex == i - 1 || atIndex == i - 1 ||
      diff == 1) {
    return 1;
  }

  return 0;
}

int keres(donor *u, int l, char *nev) {
  int i, j, nevHossz = stringHossz(nev);

  for (i = 0; i < l; i++) {
    if (nevHossz == stringHossz(u[i].btype)) {
      j = 0;
      while (j < nevHossz && nev[j] == u[i].btype[j]) {
        j++;
      }
      if (j == nevHossz) {
        return i;
      }
    }
  }

  return -1;
}

void kilep(donor *u, char *fName, int l) {
  FILE *fp = NULL;
  char ment;

  printf("Mentes? (I / N): ");
  scanf(" %c", &ment);

  if (ment == 'i' || ment == 'I') {
    fp = fopen("donorok", "w");
    for (int i = 0; i < l; i++) {
      printf("%d\t%-20s%-20s%-20s\t%d\t%s\n", u[i].id, u[i].name, u[i].btype,
             u[i].email, u[i].times, u[i].ldate);
      fprintf(fp, "%d %s %s %s %d %s\n", u[i].id, u[i].name, u[i].btype,
              u[i].email, u[i].times, u[i].ldate);
    }
    fflush(fp);
    fclose(fp);
  }

  free(u);

  printf("Kilepes...\n");
}

void lista(donor *u, int l) {
  int i;
  for (i = 0; i < l; i++) {
    printf("ID: %d\nNev: %s\nVercsoport: %s\nEmail: %s\nDonaciok szama: "
           "%d\nUtolso donacio: "
           "%s\n\n",
           u[i].id, u[i].name, u[i].btype, u[i].email, u[i].times, u[i].ldate);
  }
}

void masol(char *innen, char *ide) {
  int i = 0;
  while (innen[i]) {
    ide[i] = innen[i];
    i++;
  }
  ide[i] = 0;
}

int menu() {
  int opcio;

  printf("Szamuk megadasa altal, az alabbi lehetosegek kozul valaszthat:\n\n");
  printf("- 1: taglista megtekintese\n\n- 2: uj tag hozzaadasa\n\n- 3: adott "
         "vercsoport keresese\n\n- 4: program bezarasa, mentes\n\n");
  scanf("%d", &opcio);

  system("cls");

  return opcio;
}

int retry() {
  char ujra;
  printf("Megprobalja ujra? (I / N)");
  scanf(" %c", &ujra);
  if (ujra == 'i' || ujra == 'I') {
    return 1;
  } else {
    return 0;
  }
}

int stringHossz(char *n) {
  int i = 0;
  while (n[i]) {
    i++;
  }
  return i;
}

int szovegHossz(char *k) {
  int i = 0;
  while (k[i] != 0) {
    i++;
  }
  return i;
}

int ujDonor(donor **u, int *l) {
  char emailTemp[20];

  printf("Nev: ");
  scanf("%s", (*u)[*l - 1].name);

  printf("Vercsoport: ");
  scanf("%s", (*u)[*l - 1].btype);

  printf("Email: ");
  scanf("%s", emailTemp);
  if (emailHelyes(emailTemp)) {
    printf("Ervenytelen email!.\n");
    if (retry()) {
      return 1;
    } else {
      return 0;
    }
  }

  if (!(*u = (donor *)realloc(*u, ++(*l) * sizeof(donor)))) {
    printf("Nincs eleg memoria.\n");
    if (retry()) {
      return 1;
    } else {
      return 0;
    }
  }

  masol(emailTemp, (*u)[*l - 1].email);

  printf("Donaciok szama: ");
  scanf("%d", &(*u)[*l - 1].times);

  printf("Utolso donacio: ");
  scanf("%s", (*u)[*l - 1].ldate);

  (*u)[*l - 1].id = (*u)[*l - 2].id + 1;

  return 0;
}
