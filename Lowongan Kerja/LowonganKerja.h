#ifndef LOWONGANKERJA_H_INCLUDED
#define LOWONGANKERJA_H_INCLUDED

#include <iostream>
using namespace std;

#define next(L) (L)->next
#define child(L) (L)->child
#define info(L) (L)->info
#define first(L) ((L).first)
#define kantor(L) (L)->kantor

typedef struct nodePelamar *adrPelamar;
typedef struct nodeLowongan *adrLowongan;
typedef struct nodeChild *adrChild;


struct infotypePelamar {
    string nama, asal, pendidikanTerakhir;
    int usia;
    float ipk;
};

struct infotypeLowongan {
    string jabatan, tanggal;
    int gaji;
};

struct nodePelamar {
    infotypePelamar info;
    adrPelamar next;
    adrChild child;
};

struct nodeLowongan {
    infotypeLowongan info;
    adrLowongan next;
};

struct nodeChild {
    adrChild next;
    adrLowongan info;
};

struct listPelamar {
    adrPelamar first;
};

struct listLowongan {
    adrLowongan first;
};


void newListPelamar(listPelamar &listP);
void newListLowongan(listLowongan &listL);
adrPelamar newNodePelamar(string nama, string asal, string pendidikanTerakhir, int usia, float ipk);
adrLowongan newNodeLowongan(string jabatan, int gaji, string tanggal);
adrChild newNodeChild(adrLowongan lowongan);
void insertPelamar(listPelamar &listP, adrPelamar newPelamar);
void insertLowongan(listLowongan &listL, adrLowongan newLowongan);
void pelamarInsertLowongan(adrPelamar &pelamar, adrChild newLamaran);
adrPelamar cariPelamar(listPelamar listP, string namaPelamar);
adrLowongan cariLowongan(listLowongan listL, string jabatan);
adrChild cariChild(adrPelamar dataPelamar, string namaLamaran);
void cariPelamarLowongan(listPelamar listL, adrLowongan dicari);
void printListPelamar(listPelamar ListP);
void printListLowongan(listLowongan listL);
void printChildPelamar(listPelamar listP);
void deletePelamar(listPelamar &listP, adrPelamar del);
void deleteLowongan(listLowongan &listL, listPelamar &listP, adrLowongan del);
void deleteChild(listPelamar &listP, adrPelamar parent, adrChild del);
int jumlahPelamar(listPelamar listP, adrLowongan p);
void lowonganTerramai(listPelamar listP, listLowongan listL);
void lowonganTersepi(listPelamar listP, listLowongan listL);

#endif // LOWONGANKERJA_H_INCLUDED
