#include <stdio.h>
#include <stdlib.h>

float szazalekErtek(float szalap, float szlab) {
  float szertek;
  szertek = szalap * szlab / 100;
  return szertek;
}

float filter() {
  float num;
  do {
    printf("Nemnegativ szam: ");
    scanf("%f", &num);
  } while (num <= 0);
  return num;
}

int main(int argc, char const *argv[]) {
  float alap, lab, ertek;
  char c;
  int megint = 1;

  while ((megint = 1)) {
    printf("Alap erteke\n");
    alap = filter();

    printf("\nLab erteke\n");
    lab = filter();

    ertek = szazalekErtek(alap, lab);
    printf("\n%f %f szazaleka = %f\n", alap, lab, ertek);

    while (megint == 1 && (c != 'I' || c != 'N')) {
      printf("Megint? (I)gen / (N)em: ");
      scanf("%c", &c);
      c = getchar();
      system("cls");

      if (c == 'I') {
        break;
      } else if (c == 'N') {
        megint = 0;
        printf("Viszlat!");
        return 0;
      } else {
        printf("Hibas betu!\n");
      }
    }
  }
  return 0;
}
