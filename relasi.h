#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "matakuliah.h"
#include "dosen.h"
#include <iostream>
using namespace std;
#define first(L) L.first
#define last(L) L.last
#define next(P) (P)-> next
#define prev(P) (P)-> prev
#define addressMatkul(P) (P)->info.addressMatkul
#define addressDosen(P) (P)->info.addressDosen
#define nil NULL
struct relasi{
    adr_dosen addressDosen;
    adr_matkul addressMatkul;
};
typedef struct relasi infotype_r;
typedef struct elmlist_r *adr_relasi;
struct elmlist_r{
    infotype_r info;
    adr_relasi next;
    adr_relasi prev;
};
struct List_r{
    adr_relasi first;
    adr_relasi last;
};

void createListrelasi(List_r &L);
adr_relasi alokasirelasi(infotype_r relasi);
void dealokasirelasi(adr_relasi &P);
void insertRelasi(List_r &L, adr_relasi P);
void insertFirstrelasi(List_r &L, adr_relasi P);
void insertAfterrelasi(List_r &L, adr_relasi Prec, adr_relasi P);
void insertLastrelasi(List_r &L, adr_relasi P);
void deleteFirstrelasi(List_r &L);
void deleteLastrelasi(List_r &L);
void deleteAfterrelasi(List_r &L, adr_relasi Prec);
void deleteRelasi(List_r &L, infotype_r R);
void printrelasi(List_r L);
adr_relasi findrelasi(List_r L, infotype_r P);

#endif // RELASI_H_INCLUDED
