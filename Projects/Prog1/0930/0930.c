#include <stdio.h>
#include <stdlib.h>

void primeTest(int num) {
  int i = 2;
  while (i < num && num % i++)
    ;
  if (i == num) {
    printf("%d", num);
  }
}

int main(int argc, char const *argv[]) {
  int num;
  printf("Szam: ");
  scanf("%d", &num);
  primeTest(num);
  return 0;
}

/*void csere(int first, int second) {
  int temp;
  if (first > second) {
    temp = first;
    first = second;
    second = temp;
  }
  printf("a: %d, b: %d\n", first, second);
}*/

/*void max(float db2) {
  int temp, min, max, sum;

  printf("1. szam: ");
  scanf("%d", &temp);
  max = temp;
  min = temp;
  sum = temp;

  for (int i = 2; i <= db2; i++) {
    printf("%d. szam: ", i);
    scanf("%d", &temp);
    sum += temp;
    if (temp > max) {
      max = temp;
    }
    if (temp < min) {
      min = temp;
    }
  }
  // printf("Legnagyobb szam: %d\nLegkisebb szam: %d\n", max, min);
  // printf("Max diff: %d\n", max - min);
  printf("Atlag: %f", sum / db2);
}*/

/*int main(int argc, char const *argv[]) {
  int db;
  printf("DB: ");
  scanf("%d", &db);
  max(db);
  int a, b;

  printf("a: ");
  scanf("%d", &a);

  printf("b: ");
  scanf("%d", &b);

  csere(a, b);
  return 0;
}*/
