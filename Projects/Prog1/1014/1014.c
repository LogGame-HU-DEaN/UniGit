#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLength(char *string) {
  int i = 0;
  while (string[i] != 0) {
    i++;
  }
  return i;
}

void copy(char *to, char *from) {
  int i = 0;
  while (from[i] != 0) {
    to[i] = from[i];
    i++;
  }
  to[i] = from[i];
}

int main(int argc, char const *argv[]) {
  char size = 20, string[size];
  // char *fixString = "SUPErcAlifRAGIListICeXPiAlIdoCiOUS";

  // copy(string, fixString);
  // toLower(string);
  // scanf("%s", string);
  printf("%s\n", string);

  /*fixString = fix;
  printf("%s\n", fixString);*/

  /*  scanf("%s", string);
    printf("%s\n", string);

    length = stringLength(string);
    printf("\"%s\" szoveg hossza: %d\n", string, length);*/
  /*string[0] = 'A';
  string[1] = 'B';
  string[2] = 'B';
  string[3] = 'A';
  string[4] = '\0';
  printf("%s\n", string);

  while (string[i] != 0) {
    printf("Betu (karakter): %c, ASCII kodja: %d\n", string[i], string[i]);
    i++;
  }*/
  return 0;
}
