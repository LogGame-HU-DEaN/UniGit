#include <stdio.h>
#include <stdlib.h>

void fillArray(int *numArray, int size) {
  size = 5;

  for (int i = 0; i < size; i++) {
    printf("%d. value: ", i + 1);
    scanf("%d", &numArray[i]);
  }

  printf("\nArray values:\n\n");

  for (int i = 0; i < size; i++) {
    printf("%d. value: %d\n", i + 1, numArray[i]);
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (numArray[j] < numArray[i]) {
        int sw = numArray[j];
        numArray[j] = numArray[i];
        numArray[i] = sw;
      }
    }
  }

  printf("\nOrdered array:\n\n");

  for (int i = 0; i < size; i++) {
    printf("%d. value: %d\n", i + 1, numArray[i]);
  }
}

/*int fill(const void *a, const void *b) {
  if (*(int *)a == *(int *)b)
    return 0;
  return *(int *)a < *(int *)b ? -1 : 1;
}*/

int main(int argc, char const *argv[]) {
  int size = 5, numArray[size];

  fillArray(numArray, size);
  /*qsort(numArray, size, sizeof(int), fill);*/

  return 0;
}
