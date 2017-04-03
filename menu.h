#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "dosen.h"
#include "matakuliah.h"
#include "relasi.h"
#include <stdlib.h>
#include <conio.h>

void clearscreen();
int inputmenu();
int inputsubmenu();
void menu(int menu, int sub, List_dosen &LD, List_matkul &LM, List_r &LR);
void tampilmenu();
void inputdosen(List_dosen &L);
void inputmatkul(List_matkul &LM,List_r &LR,List_dosen LD);
void inputrelasi(List_r &LR,List_dosen LD,List_matkul LM);
void deletedosen(List_dosen &D,List_r &R);
void deletematkul(List_matkul &M,List_r &R);
void deleterelasi(List_r &LR,List_dosen LD,List_matkul LM);
void printDosen();
void printMatkul();
void printRelasi();
void findDosen(List_dosen &L);
void findMatkul(List_matkul &L);
void findRelasi(List_r &LR,List_dosen LD,List_matkul LM);
void printmat(List_r LR, List_matkul LM);
void printRel(List_dosen LD,List_matkul LM,List_r LR);
void printmatkuldaridosentertentu(List_r &LR);
void printdosendarimatkultertentu(List_r &LR);
int Hitungmatkuldaridosen(List_r L, infotypedosen D);
int Hitungdosendarimatkul(List_r L, infotypematkul M);
void Matkuldgnmaksdosen(List_r LR, List_matkul LM);
void MatkuldgnMindosen(List_r LR, List_matkul LM);
void printdosenmatkul (List_dosen &LD, List_r &LR);
#endif // MENU_H_INCLUDED
