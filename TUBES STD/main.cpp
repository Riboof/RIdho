#include <iostream>
#include "lowongan.h"
#include "pelamar.h"

using namespace std;

int main()
{
    listL LL;
    listP LP;

    adrLowongan adrL;
    adrPelamar adrP;
    adrRelasi adrR;
    infoL infoL;
    infoP infoP;
    char kembali;
    int menu;
    int angka, i;

    string namaP, jenis;
    int umurL, umurP;
    string namaL, jabatan;
    string pilihan;
    createListLowongan(LL);
    createListPelamar(LP);

    menu = menuProject();

    while(menu != 0){
        switch (menu){
        case 1:
            i = 1;
            cout<<"Masukan jumlah Perusahaan: ";
            cin>> angka;
            cout<<endl;

            while(i<=angka){
                cout<<"Data Perusahaan ke-"<<i<<endl;
                inputLowongan(infoL);
                adrL = elmLowongan(infoL);
                insertLastLowongan(LL, adrL);
                i++;
            }
            break;
        case 2:
            i = 1;
            cout<<"Masukan data Pelamar: ";
            cin>> angka;
            cout<<endl;

            while(i<=angka){
                cout<<"Data Pelamar ke-"<<i<<endl;
                inputPelamar(infoP);
                adrP = elmPelamar(infoP);
                insertLastPelamar(LP,adrP);
                i++;
            }
            break;
        case 3:
            i=1;
            cout<<"Input jumlah data: ";
            cin>> angka;
            cout<<endl;
            while(i<=angka){
                cout<<"Data :"<<endl;
                tambahDataR(namaL,jabatan,umurL,namaP);
                adrL = findLowongan(LL,namaL);
                adrP = findPelamar(LP,namaP);
                adrR = elmRelasi(adrP);
                insertLastRelasi(child(adrL),adrR);
                i++;

                }
                break;
        case 4:
            cout<<"Cek Data Lowongan"<<endl;
            cout<<"Nama : ";
            cin>>namaL;
            cout<<"Jabatan Yang Dibutuhkan : ";
            cin>>jabatan;
            cout<<"Batasan Umur : ";
            cin>>umurL;
            cout<<endl;

            if(cekLowongan(LL,namaL,jabatan,umurL)){
                cout<<"Lowongan "<<namaL<<" Data tersedia"<<endl;
            }else{
                cout<<"Lowongan "<<namaL<<" Tidak tersedia"<<endl;
            }
        break;
        case 5:
            cout<<"Hapus Data Lowongan"<<endl;
            cout<<"Nama Perusahaan : ";
            cin>>namaL;
            cout << "Jabatan yang dibutuhkan :";
            cin >> jabatan;
            cout<<"Batasan Umur : ";
            cin>>umurL;

            hapusLowongan(LL,namaL,jabatan,umurL);

            break;

        case 6:
            cout<<"Menampilkan Data: ";
            cout<<"Silahkan Pilih Data Lowongan / Pelamar : " << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            cout<<endl;
            if(pilihan == "lowongan" || pilihan == "Lowongan"){
                showLowongan(LL);
            }else if(pilihan == "pelamar" || pilihan == "Pelamar"){
                showPelamar(LP);
            }
            break;
        case 7:
            showAll(LL);
            break;
        case 8:
            cout<<"Menampilkan jumlah Pelamar Pada Suatu Perusahaan"<<endl;
            cout<<"Masukan Nama Perusahaan: ";
            cin>>namaL;
            cout<<hitungPelamar(LL,namaL);
            break;
            break;
        case 9:
            maxLowongan(LL);
            break;
        case 10:
            minLowongan(LL);
        }
        cout << endl<< "Kembali ke menu utama? (Y/N): ";
        cin >> kembali;

        if (kembali == 'Y' || kembali == 'y'){
            cout << endl;
            menu = menuProject();
        }
        else if (kembali == 'N' || kembali == 'n'){
            menu = 0;
            }
        }

        cout << endl<<"Program Telah Berakhir"<<endl;

    return 0;

}
