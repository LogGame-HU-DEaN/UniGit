#include <stdio.h>
#include <stdlib.h>

typedef struct ugyfel {
  char nev[20];
  int penz;
  float klab;
} ugyfel;

void beolvas(ugyfel *u, int hossz) {
  for (int i = 0; i < hossz; i++) {
    printf("Nev: ");
    scanf("%s", u[i].nev);
    printf("Penz: ");
    scanf("%d", &u[i].penz);
    printf("Kamatlab: ");
    scanf("%f", &u[i].klab);
  }
}

void kiiras(ugyfel *u, int hossz) {
  for (int i = 0; i < hossz; i++) {
    printf("Nev: %s\t", u[i].nev);
    printf("Penz: %d\t", u[i].penz);
    printf("Kamatlab: %f\n", u[i].klab);
  }
}

int szovegHossz(char *k) {
  int i = 0;
  while (k[i] != 0) {
    i++;
  }
  return i;
}

int keres(ugyfel *u, int hossz) {
  int j, nevHossz;
  char who[20];
  printf("Keresett nev: ");
  scanf("%s", who);
  nevHossz = szovegHossz(who);
  for (int i = 0; i < hossz; i++) {
    if (nevHossz == szovegHossz(u[i].nev)) {
      j = 0;
      while (who[j] && who[j] == u[i].nev[j]) {
        j++;
      }
      if (j == nevHossz) {
        return i;
      }
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int n = 3, keresettIndex;
  ugyfel ugyfelek[n];
  beolvas(ugyfelek, n);
  kiiras(ugyfelek, n);
  if ((keresettIndex = keres(ugyfelek, n)) == -1) {
    printf("Nincs talalat.\n");
  } else {
    printf("Nev: %s\t", ugyfelek[keresettIndex].nev);
    printf("Penz: %d\t", ugyfelek[keresettIndex].penz);
    printf("Kamatlab: %f\n", ugyfelek[keresettIndex].klab);
  }
  return 0;
}

/*for (int i = 0; i < n; i++) {
  printf("%s\n", szoveg[i]);
}*/
/*int v = 3, w = 5;
int *p0;
int **p1;
p0 = &v;
*p0 = 4;
printf("%d\n", *p0);
p1 = &p0;
*p1 = &w;
printf("%d\n", *p0);*/
