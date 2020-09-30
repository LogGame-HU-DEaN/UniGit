#include <stdio.h>
#include <stdlib.h>

float szazalekErtek(float a, float l) {
  float szertek;
  szertek = a * l / 100;
  return szertek;
}

int main(int argc, char const *argv[]) {
  float ertek, lab, alap;

  printf("alap: ");
  scanf("%f", &alap);
  printf("lab: ");
  scanf("%f", &lab);

  ertek = szazalekErtek(alap, lab);

  printf("%f %f szazaleka = %f\n", alap, lab, ertek);
  return 0;
}
