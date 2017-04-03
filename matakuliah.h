#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
#include <stdio.h>
#include <iostream>
#define first(L) L.first
#define next(P) (P)-> next
#define info(P) (P)-> info
#define info(P) (P)-> info
#define nil NULL
using namespace std;
struct matkul {
    string nama_matkul;
    string deskripsi;
    int nDosen;
};
typedef struct matkul infotypematkul;
typedef struct elmlist_matkul *adr_matkul;
struct elmlist_matkul{
    infotypematkul info;
    adr_matkul next;
};
struct List_matkul{
    adr_matkul first;
};

void createListmatkul(List_matkul &L);
adr_matkul alokasimatkul(infotypematkul matkul);
void dealokasimatkul(adr_matkul &P);
void insertMatkul(List_matkul &L, adr_matkul P);
void insertFirstmatkul(List_matkul &L, adr_matkul P);
void insertAftermatkul(List_matkul &L, adr_matkul Prec, adr_matkul P);
void insertLastmatkul(List_matkul &L, adr_matkul P);
void deleteFirstmatkul(List_matkul &L);
void deleteLastmatkul(List_matkul &L);
void deleteAftermatkul(List_matkul &L, adr_matkul Prec);
void deleteMatkul(List_matkul &L, infotypematkul M);
void printmatkul(List_matkul L);
adr_matkul findmatkul(List_matkul L, infotypematkul P);
#endif // MATAKULIAH_H_INCLUDED
