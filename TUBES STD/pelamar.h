#ifndef PELAMAR_H_INCLUDED
#define PELAMAR_H_INCLUDED

#include <iostream>
using namespace std;

#define nextP(P) P->nextP
#define infoP(P) P->infoP
#define first(L) ((L).first)
#define nil NULL

struct pelamar {
    string namaP, jenisK, jabatan;
    int umurP;
};

typedef pelamar infoP;
typedef struct elmP *adrPelamar;

struct elmP {
    infoP infoP;
    adrPelamar nextP;
};

struct listP {
    adrPelamar first;
};

void createListPelamar(listP &LP);
adrPelamar elmPelamar(infoP iP);
void insertLastPelamar(listP &LP, adrPelamar iP);
void deleteLastPelamar(listP &LP, adrPelamar &iP);
void showPelamar(listP LP);
adrPelamar findPelamar(listP &LP, string namaP);
infoP inputPelamar(infoP &input);
bool cekPelamar(listP LP, string nama, string jabatan, int umur);

#endif // PELAMAR_H_INCLUDED
