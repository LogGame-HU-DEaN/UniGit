#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i, meret = 0, *tomb;
  char fajlNev[30], k;

  FILE *fp = NULL;
  printf("Allomany neve: ");
  scanf("%s", fajlNev);
  fp = fopen(fajlNev, "r");
  while ((k = fgetc(fp)) != EOF) {
    if (k == '\n') {
      meret++;
    }
  }
  tomb = (int *)malloc(meret * sizeof(int));
  rewind(fp);
  for (i = 0; i < meret; i++) {
    fscanf(fp, "%d", &tomb[i]);
    printf("%d. elem: %d\n", i + 1, tomb[i]);
  }

  fclose(fp);
  return 0;
}
