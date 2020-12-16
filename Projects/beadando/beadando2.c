#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  donor *donorok = NULL;
  char fajlNev[50], date[11];
  int hossz = 0, ujra;

  datumBe(date);

  while (ujra = beolvas(&donorok, fajlNev, &hossz)) {
    if (ujra == 2) {
      return 0;
    }
  }

  while (1) {
    switch (menu()) {
    case 1:
      lista(donorok, hossz);
      break;
    case 2:
      while (ujDonor(&donorok, &hossz))
        ;
      break;
    case 3:
      while (bkeres(donorok, hossz))
        ;
      break;
    case 4:
      kilep(donorok, fajlNev, hossz);
      return 0;
    default:
      printf("Kerem valasszon a negy opcio kozul.\n");
    }
  }
}
