#include <stdio.h>
#include <stdlib.h>

int filter() {
  int input, limit = -1;
  do {
    scanf("%d", &input);
    if (input < limit) {
      printf("Nagyobb szam kell, mint %d! ", limit);
    }
  } while (input < limit);

  return input;
}

int main(int argc, char const *argv[]) {
  int szam, again /*, i = 1, alsoH = 0, felsoH = 100*/;

  do {
    printf("Hanyszor? ");
    szam = filter();

    for (int i = 1; i <= szam; i++) {
      printf("%d. Sziasztok!\n", i);
    }
    printf("Ujra? [I]gen / [N]em: ");
    while ((again = getchar()) == '\n') {
    };
    /*again = getchar();
    if (again == '\n') {
      again = getchar();
    }*/
  } while (again == 'I' || again == 'i');

  /*if (szam <= alsoH || szam > felsoH) {
    printf("Valid intervallum: ]%d; %d]!\n", alsoH, felsoH);
  } else {
    printf("Rendben!\n");
  }*/

  /*if (szam == felsoH) {
    printf("Egyenlo!");
  }*/

  /*while (i <= szam) {
    printf("%d. Sziasztok!\n", i);
    i++;
  }*/
  return 0;
}
