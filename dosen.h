#ifndef DOSEN_H_INCLUDED
#define DOSEN_H_INCLUDED
//#include "relasi.h"
//#include <stdio.h>
#include <iostream>

using namespace std;

#define first(L) L.first
#define next(P) (P)-> next
#define info(P) (P)-> info
#define nil NULL
struct dosen {
    string nama;
    string no_telp;
};
typedef struct dosen infotypedosen;
typedef struct elmlist_dosen *adr_dosen;
struct elmlist_dosen{
    infotypedosen info;
    adr_dosen next;
};
struct List_dosen{
    adr_dosen first;
};


void createListdosen(List_dosen &L);
adr_dosen alokasidosen(infotypedosen dosen);
void dealokasidosen(adr_dosen &P);
void insertDosen(List_dosen &L, adr_dosen P);
void insertFirstdosen(List_dosen &L, adr_dosen P);
void insertAfterdosen(List_dosen &L, adr_dosen Prec, adr_dosen P);
void insertLastdosen(List_dosen &L, adr_dosen P);
void deleteFirstdosen(List_dosen &L);
void deleteLastdosen(List_dosen &L);
void deleteAfterdosen(List_dosen &L, adr_dosen Prec);
void deleteDosen(List_dosen &L, infotypedosen D);
void printdosen(List_dosen L);
adr_dosen searchdosen(List_dosen L, infotypedosen P);

adr_dosen finddosen(List_dosen L, infotypedosen P);
#endif // DOSEN_H_INCLUDED
