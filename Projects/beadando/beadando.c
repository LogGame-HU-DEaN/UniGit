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

char ldate(char *ldate[]) {
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

int main(int argc, char const *argv[]) {
  int n = 6;
  donor donors[n];
  return 0;
}
