#include <stdio.h>
#include <stdlib.h>

typedef struct donor {
  int id;
  char name[20];
  char btype[3];
  char email;
  int times;
  char ldate[11];
} donor;

char datecheck(char *ldate[]) {
  for (int i = 0; *ldate[i] != '\0'; ++i) {
    if (i != 5 && i != 8 && i != 11) {
      if (*ldate[i] < '0' && *ldate[i] > '9') {
        return printf("Hibas datum!\n");
      }
    } else if (i == 5 || i == 8 || i == 11) {
      if (*ldate[i] != '.') {
        return printf("Hibas datum formatum!\n");
      }
    }
  }
  return **ldate;
}

char emailcheck(char *email[]) {
  for (int i = 0; *email[i] != '\0'; ++i) {
  }
  return **email;
}

void read(donor *d, int length) {
  for (int i = 0; i < length; i++) {
    printf("Nev: ");
    scanf("%s", d[i].name);
    printf("Vercsoport: ");
    scanf("%s", d[i].btype);
    printf("Email: ");
    scanf("%s", &d[i].email);
    printf("Donaciok: ");
    scanf("%d", &d[i].times);
    printf("Utolso: ");
    scanf("%s", d[i].ldate);
  }
}

void write(donor *d, int length) {
  for (int i = 0; i < length; i++) {
    printf("Nev: %s\t", d[i].name);
    printf("Vercsoport: %s\t", d[i].btype);
    printf("Email: %s\n", &d[i].email);
    printf("Donaciok: %d\n", d[i].times);
    printf("Utolso: %s\n", d[i].ldate);
  }
}

int main(int argc, char const *argv[]) {
  int n = 6;
  donor donors[n];
  read(donors, n);
  write(donors, n);
  return 0;
}
