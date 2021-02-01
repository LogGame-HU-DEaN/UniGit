#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i, n = 10;
  FILE *fp = NULL;
  fp = fopen("szamFajl", "w");
  for (i = 1; i <= n; i++) {
    fprintf(fp, "%d\n", i);
  }
  fflush(fp);
  fclose(fp);
  return 0;
}
