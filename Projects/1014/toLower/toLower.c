#include <stdio.h>
#include <stdlib.h>

void changeUpLow(char *string) {
  int i = 0;
  while (string[i] != 0) {
    if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] += ' ';
    } else if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] -= ' ';
    }
    i++;
  }
}

int main(int argc, char const *argv[]) {
  char string[1];
  scanf("%[^\n]", string);
  printf("Eredeti szoveg: %s\n", string);
  changeUpLow(string);
  printf("Forditott szoveg: %s\n", string);
  return 0;
}
