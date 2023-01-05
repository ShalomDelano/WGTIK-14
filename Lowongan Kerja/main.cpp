#include "LowonganKerja.h"

int main() {
    // Deklarasi list pelamar
    listPelamar listP;
    // Inisialisasi list pelamar
    newListPelamar(listP);
    // Deklarasi variable untuk menampung address pelamar
    adrPelamar newPelamar, dataPelamar;

    // Deklarasi list lowongan
    listLowongan listL;
    // Inisialisasi list lowongan
    newListLowongan(listL);
    // Deklarasi variable untuk menampung address lowongan
    adrLowongan newLowongan, dataLowongan;


    // Deklarasi variable untuk menampung address child
    adrChild newChild, dataChild, currentC;

    // Deklarasi variable untuk kebutuhan menu
    string namaPelamar, asalPelamar, pendidikanTerakhir;
    int usia;
    float ipk;

    string jabatanLowongan, tanggalLowongan;
    int gajiLowongan;

    // Looping Menu utama
    bool loopMenu = true;
    int inputUser, n;
    while(loopMenu) {
        cout << endl;
        cout << "===== Menu Utama =====" << endl;
        cout << "1. Input Pelamar" << endl;
        cout << "2. Input Lowongan Kerja" << endl;
        cout << "3. Daftarkan Pelamar ke Lowongan" << endl;
        cout << "4. Cari Pelamar" << endl;
        cout << "5. Cari Lowongan Kerja" << endl;
        cout << "6. Cari Pelamar dan Lowongan Kerjanya" << endl;
        cout << "7. Print List Pelamar" << endl;
        cout << "8. Print List Lowongan" << endl;
        cout << "9. Print Child Pelamar" << endl;
        cout << "10. Hapus Node Pelamar" << endl;
        cout << "11. Hapus Node Lowongan" << endl;
        cout << "12. Hapus Lamaran Kerja" << endl;
        cout << "13. Jumlah Pelamar setiap Lowongan" << endl;
        cout << "14. Lowongan Dengan Pelamar Terbanyak" << endl;
        cout << "15. Lowongan Dengan Pelamar Tersedikit" << endl;
        cout << "16. Keluar" << endl;

        // Input pengguna untuk memilih menu
        cout << "Input Menu User : "; cin >> inputUser;


        if (inputUser == 1) {
            // Menu "Input Pelamar"
                // Meminta input dari pengguna untuk banyaknya pelamar yang akan diinput
            cout << endl << "Banyak Pelamar yang akan diinput : "; cin >> n;

                // Looping untuk meminta input data pelamar
            for(int i = 0; i < n; i++) {
                cout << endl;
                cout << "Nama : "; cin >> namaPelamar;
                cout << "Asal : "; cin >> asalPelamar;
                cout << "Pendidikan Terakhir : "; cin >> pendidikanTerakhir;
                cout << "IPK : "; cin >> ipk;
                cout << "Usia : "; cin >> usia;

                // Alokasi node pelamar dengan info yang sudah diisikan oleh pengguna
                newPelamar = newNodePelamar(namaPelamar, asalPelamar, pendidikanTerakhir, ipk, usia);
                // Insert node yang sudah dialokasikan ke dalam list pelamar
                insertPelamar(listP, newPelamar);
            }
        } else if (inputUser == 2) {
            // Menu "Input Lowongan Kerja"
                // Meminta input dari pengguna untuk banyaknya lowongan yang akan diinput
            cout << endl << "Banyak Lowongan Kerja yang akan diinput : "; cin >> n;

                // Looping untuk meminta input data lowongan
            for(int i = 0; i < n; i++) {
                cout << endl;
                cout << "Jabatan : "; cin >> jabatanLowongan;
                cout << "Gaji : "; cin >> gajiLowongan;
                cout << "Tanggal Wawancara : "; cin >> tanggalLowongan;

                // Alokasi node lowongan dengan info yang sudah diisikan oleh pengguna
                newLowongan = newNodeLowongan(jabatanLowongan, gajiLowongan, tanggalLowongan);
                // Insert node yang sudah dialokasikan ke dalam list lowongan
                insertLowongan(listL, newLowongan);
            }
        } else if (inputUser == 3) {
            // Menu "Daftarkan Pelamar ke Lowongan"
            cout << "Pilih Pelamar yang akan Melamar" << endl;

            // Looping untuk menampilkan setiap nama pelamar di list pelamar
            dataPelamar = first(listP);
            while(dataPelamar != NULL) {
                cout << "- " << info(dataPelamar).nama << endl;
                dataPelamar = next(dataPelamar);
            }
                // Meminta input dari pengguna untuk memilih node nama untuk dipasangkan dengan suatu node lowongan kerja
            cout << "Masukkan Nama Pelamar yang akan Melamar : "; cin >> namaPelamar;
            // Variable data pelamar diisi oleh address dengan nama pelamar yang diinputkan user (jika ada) dengan bantuan function cariPelamar
            dataPelamar = cariPelamar(listP, namaPelamar);

            // Looping untuk menampilkan setiap nama jabatan di list jabatan
            dataLowongan = first(listL);
            while(dataLowongan != NULL) {
                cout << "- " << info(dataLowongan).jabatan << endl;
                dataLowongan = next(dataLowongan);
            }
                // Meminta input dari pengguna untuk memilih node jabatan untuk dipasangkan dengan node pelamar yang sudah dipi
            cout << "Masukkan Jabatan yang akan dipilih : "; cin >> jabatanLowongan;
            // Variable data pelamar diisi oleh address dengan nama jabatan yang diinputkan user (jika ada) dengan bantuan function cariLowongan
            dataLowongan = cariLowongan(listL, jabatanLowongan);

            pelamarInsertLowongan(dataPelamar, newNodeChild(dataLowongan));
        } else if (inputUser == 4) {
            // Menu "Cari Pelamar"
                // Meminta input dari pengguna untuk nama pelamar yang akan dicari datanya
            cout << endl << "Nama Pelamar yang akan dicari : "; cin >> namaPelamar;
            // Mencari data pelamar di suatu list pelamar dengan bantuan function cariPelamar
            dataPelamar = cariPelamar(listP, namaPelamar);

            if(dataPelamar != NULL) {
                // Jika node pelamar yang dicari ketemu, maka akan dioutputkan data nya
                cout << endl << "Ditemukan Pelamar dengan nama " << namaPelamar << endl;
                cout << "Nama : " << info(dataPelamar).nama << endl;
                cout << "Asal : " << info(dataPelamar).asal << endl;
                cout << "Pendidikan Terakhir : " << info(dataPelamar).pendidikanTerakhir << endl;
                cout << "IPK : " << info(dataPelamar).ipk << endl;
                cout << "Usia : " << info(dataPelamar).usia << endl;
            } else {
                // Jika node pelamar yang dicari tidak ketemu, maka akan dioutputkan "Tidak ditemukan"
                cout << endl << "Tidak ditemukan Pelamar dengan nama " << namaPelamar << endl;
            }
        } else if (inputUser == 5) {
            // Menu "Cari Lowongan Kerja"
                // Meminta input dari pengguna untuk nama jabatan yang akan dicari datanya
            cout << endl << "Nama Jabatan yang akan dicari : "; cin >> jabatanLowongan;
            // Mencari data lowongan di suatu list Lowongan dengan bantuan function cariLowongan
            dataLowongan = cariLowongan(listL, jabatanLowongan);

            if(dataLowongan != NULL) {
                // Jika node lowongan yang dicari ketemu, maka akan dioutputkan data nya
                cout << endl << "Ditemukan Lowongan dengan jabatan " << jabatanLowongan << endl;
                cout << "Jabatan : " << info(dataLowongan).jabatan << endl;
                cout << "Gaji : " << info(dataLowongan).gaji << endl;
                cout << "Tanggal Wawancara : " << info(dataLowongan).tanggal << endl;
            } else {
                // Jika node lowongan yang dicari tidak ketemu, maka akan dioutputkan "Tidak ditemukan"
                cout << endl << "Tidak ditemukan Jabatan dengan nama " << jabatanLowongan << endl;
            }

        } else if (inputUser == 6) {
            // Menu "Cari Pelamar dan Lowongan Kerja"
                // Meminta input dari pengguna untuk nama jabatan yang akan dicari pelamarnya
            cout << endl << "Nama Jabatan yang akan dicari Pelamarnya : "; cin >> jabatanLowongan;

            // Procedure cariPelamarLowongan akan mengoutputkan nama nama yang melamar di jabatan yang sudah diinputkan pengguna
            cariPelamarLowongan(listP, cariLowongan(listL, jabatanLowongan));
        } else if (inputUser == 7) {
            // Menu "Print List Pelamar"
            cout << endl << "Data List Pelamar : " << endl;
                // Procedure printListPelamar akan mengoutputkan semua data pelamar yang ada di dalam list
            printListPelamar(listP);
        } else if (inputUser == 8) {
            // Menu "Print List Lowongan"
            cout << endl << "Data List Lowongan : " << endl;
                // Procedure printListLowongan akan mengoutputkan semua data lowongan yang ada di dalam list
            printListLowongan(listL);
        } else if (inputUser == 9) {
            // Menu "Print Child Pelamar"
            cout << endl << "Data Pelamar serta Lamarannya : " << endl;
                // Procedure printChildPelamar akan mengoutptkan semua nama pelamar beserta jabatan yang di lamar
            printChildPelamar(listP);
        } else if (inputUser == 10) {
            // Menu "Hapus Node Pelamar"
                // Meminta input dari pengguna untuk nama pelamar yang akan dihapus nodenya
            cout << endl << "Nama Pelamar yang akan dihapus : "; cin >> namaPelamar;
            // deletePelamar akan menghapus node pelamar sesuai yang diinpukan pengguna
                // Address dari nama pelamar yang diinputkan pengguna dicari dengan bantuan function cariPelamar
            deletePelamar(listP, cariPelamar(listP, namaPelamar));
        } else if (inputUser == 11 ){
            // Menu "Hapus Node Lowongan"
                // Meminta input dari pengguna untuk nama jabatan yang akan dihapus nodenya
            cout << endl << "Nama Jabatan yang akan dihapus : "; cin >> jabatanLowongan;
            // deleteLowongan akan menghapus node lowongan sesuai yang diinputkan pengguna
                // Address dari nama lowongan yang diinputkan pengguna dicari dengan bantuan function cariLowongan
            deleteLowongan(listL, listP, cariLowongan(listL, jabatanLowongan));
        } else if (inputUser == 12) {
            // Menu "Hapus Lowongan Kerja"
            cout << "Pilih Nama Pelamar yang akan dihapus lamarannya" << endl;

            // Looping untuk menampilkan setiap nama di list Pelamar
            dataPelamar = first(listP);
            while(dataPelamar != NULL) {
                cout << "- " << info(dataPelamar).nama << endl;
                dataPelamar = next(dataPelamar);
            }
                // Meminta input pengguna untuk nama pelamar yang akan dihapus lamarannya
            cout << "Nama Pelamar yang akan dihapus lamarannya : "; cin >> namaPelamar;

            // Variable dataPelamar diisi dengan node yang nama pelamarnya sesuai dengan input user dengan bantuan function cariPelamar
            dataPelamar = cariPelamar(listP, namaPelamar);

            if(dataPelamar != NULL) {
            // Jika Node pelamar ditemukan maka lakukan penghapusan
                // Looping untuk menampilkan setiap lamaran yang diajukan di suatu node pelamar yang sudah dipilih
            dataChild = child(dataPelamar);
            while(dataChild != NULL) {
                cout << "- " << info(info(dataChild)).jabatan << endl;
                dataChild = next(dataChild);
            }
                // Meminta input pengguna untuk nama lamaran yang akan dihapus lamarannya
            cout << "Nama Jabatan lamaran yang akan dihapus : "; cin >> jabatanLowongan;

            // Variable dataChild diisi dengan node yang lamarannya sesuai dengan yang dipilih user
            dataChild = cariChild(dataPelamar, jabatanLowongan);

            // Procedure deleteChild dipanggil untuk penghapusan node child
            deleteChild(listP, dataPelamar, dataChild);
            } else {
            // Jika Node pelamar tidak ditemukan maka output dibawah
                cout << "Nama pelamar tidak ada" << endl;
            }
        } else if (inputUser == 13) {
            // Menu "Jumlah Pelamar setiap Lowongan"
            cout << endl << "Data Jumlah Pelamar" << endl;

            // Looping untuk menampilkan jumlah pelamar di setiap lowongan dengan bantuan function jumlahPelamarlist
            dataLowongan = first(listL);
            while(dataLowongan != NULL) {
                cout << "Pelamar di " << info(dataLowongan).jabatan << " : " << jumlahPelamar(listP, dataLowongan) << endl;
                dataLowongan = next(dataLowongan);
            }
        } else if (inputUser == 14) {
            // Menu "Lowongan Dengan Pelamar Terbanyak"
            lowonganTerramai(listP, listL);
        } else if (inputUser == 15) {
            // Menu "Lowongan Dengan Pelamar Tersedikit"
            lowonganTersepi(listP, listL);
        } else if (inputUser == 16) {
            // Menu "Keluar"
            cout << endl << "Terimakasih" << endl;
            loopMenu = false;
        } else {
            cout << endl << "Input tidak terdapat di menu" << endl;
        }
    }
    return 0;
}
