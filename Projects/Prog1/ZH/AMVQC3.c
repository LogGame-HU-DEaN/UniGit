#include <stdio.h>
#include <stdlib.h>

/*1. feladat eleje*/
void max(float db2) {
  int temp, max;

  printf("1. szam: ");
  scanf("%d", &temp);
  max = temp;

  for (int i = 2; i <= db2; i++) {
    printf("%d. szam: ", i);
    scanf("%d", &temp);
    if (temp > max) {
      max = temp;
    }
  }
  printf("Legnagyobb szam: %d\n", max);
}
/*1. feladat vége*/

/*2. feladat eleje*/
void tombFel(int *tomb, int meret) {
  for (int i = 0; i < meret; i++) {
    printf("%d. ertek: ", i + 1);
    scanf("%d", &tomb[i]);
  }
}

void csere(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void buborek(int tomb[], int szam) {
  int i, j, cserelt;

  for (i = 0; i < szam - 1; i++) {
    cserelt = 0;
    for (j = 0; j < szam - i - 1; j++) {
      if (tomb[j] > tomb[j + 1]) {
        csere(&tomb[j], &tomb[j + 1]);
        cserelt = 0;
      }
    }
    if (cserelt == 1) {
      break;
    }
  }
}

void kiiras(int tomb[], int meret) {
  int i;

  for (i = 0; i < meret; i++) {
    printf("%d \n", tomb[i]);
  }
}
/*2. feladat vége*/

int main(int argc, char const *argv[]) {
  /*1. feladat eleje*/
  printf("Legnagyobb szam:\n");

  int db;

  printf("DB: ");
  scanf("%d", &db);

  max(db);
  /*1. feladat vége*/

  /*2. feladat eleje*/
  printf("\nBuborek rendezes:\n");

  int meret = 5, tomb[meret];

  printf("DB: ");
  scanf("%d", &meret);

  tombFel(tomb, meret);
  buborek(tomb, meret);
  printf("\nRendezett tomb: \n");
  kiiras(tomb, meret);

  return 0;
  /*2. feladat vége*/
}
