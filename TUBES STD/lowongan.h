#ifndef LOWONGAN_H_INCLUDED
#define LOWONGAN_H_INCLUDED

#include <iostream>
using namespace std;
#include "pelamar.h"

#define next(P) P->next
#define infoL(P) P->infoL
#define first(L) ((L).first)
#define child(P) P->child
#define nil NULL

struct lowongan {
    string namaPerusahaan, jabatan;
    int umurL;
};

typedef lowongan infoL;
typedef struct elmL *adrLowongan;
typedef struct elmR *adrRelasi;

struct listR {
    adrRelasi first;
};

struct elmL {
    infoL infoL;
    adrLowongan next;
    listR child;
};

struct elmR {
    adrRelasi next;
    adrPelamar infoP;
};

struct listL {
    adrLowongan first;
};

void createListLowongan(listL &LL);
adrLowongan elmLowongan(infoL iL);
void insertLastLowongan(listL &LL, adrLowongan iL);
void deleteLastLowongan(listL &LL, adrLowongan &iL);
void showLowongan(listL LL);
adrLowongan findLowongan(listL &LL,string namaPerusahaan);
infoL inputLowongan(infoL &input);
void showAll(listL semuaL);
void hapusLowongan(listL &LL, string namaPerusahaan, string jabatan, int umurL);
bool cekLowongan(listL LL, string namaPerusahaan, string jabatan, int umurL);
int hitungPelamar(listL LL, string namaP);

void createRelasi(listR &LR);
adrRelasi elmRelasi(adrPelamar relasip);
void insertLastRelasi(listR &LR, adrRelasi iR);
void tambahDataR(string &namaL, string &jabatan, int &umur, string &nama);
void maxLowongan(listL LL);
void minLowongan(listL LL);
int menuProject();

#endif // LOWONGAN_H_INCLUDED
