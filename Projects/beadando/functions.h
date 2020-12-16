#include <stdio.h>
#include <stdlib.h>

#ifndef _DONOR_H_
#define _DONOR_H_

typedef struct {
  int id;
  char name[20];
  char btype[4];
  char email[20];
  int times;
  char ldate[11];
} donor;

#endif

int beolvas(donor **u, char *fName, int *l);
int bkeres(donor *u, int l);
int datumBe(char date[11]);
int emailHelyes(char *eTemp);
int keres(donor *u, int l, char *nev);
void kilep(donor *u, char *fName, int l);
void lista(donor *u, int l);
void masol(char *innen, char *ide);
int menu();
int retry();
int stringHossz(char *n);
int szovegHossz(char *k);
int ujDonor(donor **u, int *l);
int stringCompare(char num1[], char num2[]);
