#include "LowonganKerja.h"

void newListPelamar(listPelamar &listP) {
    first(listP) = NULL;
}

void newListLowongan(listLowongan &listL) {
    first(listL) = NULL;
}

adrPelamar newNodePelamar(string nama, string asal, string pendidikanTerakhir, int usia, float ipk) {
    adrPelamar newPelamar = new nodePelamar();

    info(newPelamar).nama = nama;
    info(newPelamar).asal = asal;
    info(newPelamar).pendidikanTerakhir = pendidikanTerakhir;
    info(newPelamar).usia = usia;
    info(newPelamar).ipk = ipk;

    next(newPelamar) = NULL;
    child(newPelamar) = NULL;

    return newPelamar;
}

adrLowongan newNodeLowongan(string jabatan, int gaji, string tanggal) {
    adrLowongan newLowongan = new nodeLowongan();

    info(newLowongan).jabatan = jabatan;
    info(newLowongan).gaji = gaji;
    info(newLowongan).tanggal = tanggal;

    next(newLowongan) = NULL;

    return newLowongan;
}

adrChild newNodeChild(adrLowongan lowongan) {
    adrChild newChild = new nodeChild();

    info(newChild) = lowongan;
    next(newChild) = NULL;

    return newChild;
}

void insertPelamar(listPelamar &listP, adrPelamar newPelamar) {
    if(first(listP) == NULL) {
        first(listP) = newPelamar;
    } else {
        adrPelamar current = first(listP);

        while(next(current) != NULL) {
            current = next(current);
        }
        next(current) = newPelamar;
    }
}

void insertLowongan(listLowongan &listL, adrLowongan newLowongan) {
    if(first(listL) == NULL) {
        first(listL) = newLowongan;
    } else {
        next(newLowongan) = first(listL);
        first(listL) = newLowongan;
    }
}

void pelamarInsertLowongan(adrPelamar &pelamar, adrChild newLamaran) {
    if(child(pelamar) == NULL) {
        child(pelamar) = newLamaran;
    } else {
        next(newLamaran) = child(pelamar);
        child(pelamar) = newLamaran;
    }
}

adrPelamar cariPelamar(listPelamar listP, string namaPelamar) {
    adrPelamar current = first(listP);
    adrPelamar found = NULL;

    while(current != NULL) {
        if(info(current).nama == namaPelamar) {
            found = current;
        }
        current = next(current);
    }

    return found;
}

adrLowongan cariLowongan(listLowongan listL, string jabatan) {
    adrLowongan current = first(listL);
    adrLowongan found = NULL;

    while (current != NULL) {
        if(info(current).jabatan == jabatan) {
            found = current;
        }
        current = next(current);
    }

    return found;
}

adrChild cariChild(adrPelamar dataPelamar, string namaLamaran) {
    adrChild currentC = child(dataPelamar);
    adrChild found = NULL;

    while(currentC != NULL) {
        if(info(info(currentC)).jabatan == namaLamaran) {
            found = currentC;
        }
        currentC = next(currentC);
    }

    return found;
}

void cariPelamarLowongan(listPelamar listP, adrLowongan dicari) {
    adrPelamar current = first(listP);

    adrChild currentL;
    while (current != NULL) {
        currentL = child(current);
        while(currentL != NULL) {
            if(info(currentL) == dicari) {
                cout << "- "<< info(current).nama << endl;
            }
            currentL = next(currentL);
        }
        current = next(current);
    }

}

void printListPelamar(listPelamar listP) {
    adrPelamar current = first(listP);

    while(current != NULL) {
        cout << endl;
        cout << "Nama : " << info(current).nama << endl;
        cout << "Asal : " << info(current).asal << endl;
        cout << "Usia : " << info(current).usia << endl;
        cout << "Pendidikan Terakhir : " << info(current).pendidikanTerakhir << endl;
        cout << "IPK : " << info(current).ipk << endl;

        current = next(current);
    }
}

void printListLowongan(listLowongan listL) {
    adrLowongan current = first(listL);

    while(current != NULL) {
        cout << endl;
        cout << "Jabatan : " << info(current).jabatan << endl;
        cout << "Gaji : " << info(current).gaji << endl;
        cout << "Tanggal Wawancara : " << info(current).tanggal << endl;

        current = next(current);
    }
}

void printChildPelamar(listPelamar listP) {
    adrPelamar currentP = first(listP);
    adrChild currentC;

    while(currentP != NULL) {
        cout << endl << info(currentP).nama << " : " << endl;
        currentC = child(currentP);
        while(currentC != NULL) {
            cout << "- "<< info(info(currentC)).jabatan << endl;
            currentC = next(currentC);
        }
        currentP = next(currentP);
    }
}

void deletePelamar(listPelamar &listP, adrPelamar del) {
    adrChild delChild;
    while(child(del) != NULL) {
        delChild = child(del);
        child(del) = next(child(del));
        delete delChild;
    }

    if (del == first(listP)) {
        first(listP) = next(first(listP));
        delete del;
    } else {
        adrPelamar current = first(listP);
        while(current != NULL) {
            if(next(current) == del) {
                next(current) = next(del);
                delete del;
            }
            current = next(current);
        }
    }
}

void deleteLowongan(listLowongan &listL, listPelamar &listP , adrLowongan del) {
    adrPelamar currentP = first(listP);
    adrChild currentC, after;
    adrLowongan currentL = first(listL);

    while(currentP != NULL) {
        currentC = child(currentP);

        while(currentC != NULL) {
            after = next(currentC);
            if(info(currentC) == del) {
                deleteChild(listP, currentP, currentC);
            }
            currentC = after;
        }
        currentP = next(currentP);
    }

    if(first(listL) == del) {
        first(listL) = next(first(listL));
        delete del;
    } else {
        while(currentL != NULL) {
            if(next(currentL) == del) {
                next(currentL) = next(del);
                delete del;
            }
            currentL = next(currentL);
        }
    }
}

void deleteChild(listPelamar &listP, adrPelamar parent, adrChild del) {
    if(child(parent) == del) {
        child(parent) = next(child(parent));
        delete del;
    } else {
        adrChild currentC = child(parent);

        while(currentC != NULL) {
            if(next(currentC) == del) {
                next(currentC) = next(del);
                delete del;
            }
            currentC = next(currentC);
        }
    }
}

int jumlahPelamar(listPelamar listP, adrLowongan p) {
    adrPelamar currentP = first(listP);
    adrChild currentC;
    int total = 0;

    while(currentP != NULL) {
        currentC = child(currentP);
        while(currentC != NULL) {
            if(info(currentC) == p) {
                total++;
            }
            currentC = next(currentC);
        }
        currentP = next(currentP);
    }

    return total;
}

void lowonganTerramai(listPelamar listP, listLowongan listL) {
    int n = jumlahPelamar(listP, first(listL));
    adrLowongan dataLowongan = first(listL);

    adrLowongan currentL = first(listL);
    while(currentL != NULL) {
        if(jumlahPelamar(listP, currentL) > n) {
            n = jumlahPelamar(listP, currentL);
            dataLowongan = currentL;
        }
        currentL = next(currentL);
    }

    cout << endl;
    cout << "Lowongan kerja dengan pelamar tersedikit adalah" << info(dataLowongan).jabatan << " dengan pelamar sejumah " << n << " orang" << endl;
}

void lowonganTersepi(listPelamar listP, listLowongan listL) {
    int n = jumlahPelamar(listP, first(listL));
    adrLowongan dataLowongan = first(listL);

    adrLowongan currentL = first(listL);
    while(currentL != NULL) {
        if(jumlahPelamar(listP, currentL) < n) {
            n = jumlahPelamar(listP, currentL);
            dataLowongan = currentL;
        }
        currentL = next(currentL);
    }

    cout << endl;
    cout << "Lowongan kerja dengan pelamar tersedikit adalah" << info(dataLowongan).jabatan << " dengan pelamar sejumah " << n << " orang" << endl;
}

