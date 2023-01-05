#include "lowongan.h"

void createListLowongan(listL &LL) {
    first(LL) = nil;
}

adrLowongan elmLowongan(infoL iL) {
    adrLowongan adrL;
    adrL = new elmL;
    infoL(adrL) = iL;
    next(adrL) = nil;
    createRelasi(child(adrL));

    return adrL;
}

void insertLastLowongan(listL &LL, adrLowongan iL) {
    if(first(LL) == nil) {
        first(LL) = iL;
    }
    else {
        adrLowongan adrL;
        adrL = first(LL);
        while(next(adrL) != nil) {
            adrL = next(adrL);
        }
        next(adrL) = iL;
    }
}

void deleteLastLowongan(listL &LL, adrLowongan &iL) {
    adrLowongan adrL;
    adrL = first(LL);

    while(next(next(adrL)) != nil) {
        adrL = next(adrL);
    }
    iL = next(adrL);
    next(adrL) = nil;
}

void showLowongan(listL LL) {
    if(first(LL) == nil) {
        cout << "Data Lowongan Kosong" << endl;
    }else {
        adrLowongan adrL;
        adrL = first(LL);
        cout << "Data Lowongan" << endl;
        while (adrL != nil) {
            cout << "Nama Perusahaan : " << infoL(adrL).namaPerusahaan << endl;
            cout << "Jabatan Yang di Inginkan : " << infoL(adrL).jabatan << endl;
            cout << "Batas Umur Pekerjaan : " << infoL(adrL).umurL << " Tahun" << endl;
            cout << endl;
            adrL = next(adrL);
        }

    }
}

adrLowongan findLowongan(listL &LL,string namaPerusahaan) {
    adrLowongan adrL;
    adrL = first(LL);
    while (adrL != nil) {
        if(infoL(adrL).namaPerusahaan == namaPerusahaan) {
            return adrL;
            break;
        }
        adrL = next(adrL);
    }
    return nil;
}

infoL inputLowongan(infoL &input) {
    cout << "Nama Perusahaan : ";
    cin >>input.namaPerusahaan;
    cout << "Jabatan Yang Dibutuhkan : ";
    cin >> input.jabatan;
    cout << "Batasan Umur Bekerja : ";
    cin >> input.umurL;
    cout << endl;

    return input;
}

void showAll(listL semuaL) {
    adrLowongan l;
    adrRelasi r;

    if(first(semuaL) == nil) {
        cout << "List Kosong" << endl;
    }
    else {
        l = first(semuaL);
        while( l != nil) {
            cout << endl;
            cout << "Lowongan " << infoL(l).namaPerusahaan << endl;
            cout << "Jabatan : " << infoL(l).jabatan << endl;
            cout << "Batasan Umur : " << infoL(l).umurL << endl;
            r = first(child(l));
            while (r != nil) {
                cout << endl << "Nama Pelamar : " << infoP(infoP(r)).namaP << endl;
                cout << "Umur Pelamar : " << infoP(infoP(r)).umurP << endl;
                cout << "Jenis Kelamin : " << infoP(infoP(r)).jenisK << endl;
                cout << "Jabatan Yang Diinginkan : " << infoP(infoP(r)).jabatan << endl;
                cout<<"=================================================="<<endl;

                r = next(r);
            }
            l = next(l);
        }
    }
}


void hapusLowongan(listL &LL, string namaPerusahaan, string jabatan, int umurL) {
    adrLowongan adrLa;
    adrLowongan adrLb;
    adrLa = findLowongan(LL, namaPerusahaan);
    adrLowongan adrL1 = first(LL);

    adrLb = first(LL);
    while(next(adrLb) != nil) {
        adrLb = next(adrLb);
    }
    if(adrLa != first(LL) && adrLa != adrLb) {
        while (next(adrL1) != adrLa) {
            adrL1 = next(adrL1);
        }
        next(adrL1) = next(adrLa);
        next(adrLa) = nil;
    }
    if(adrLa == first(LL)) {
        first(LL) = next(adrLa);
        next(adrLa) = nil;
    }
    if(adrLa == adrLb) {
        while(next(adrL1) != adrLb) {
            adrL1 = next(adrL1);
        }
        next(adrL1) = nil;
        next(adrLa) = nil;
    }

}

bool cekLowongan(listL LL, string nama, string jabatan, int umur) {
    adrLowongan adrL;
    adrL = first(LL);
    while (adrL != nil) {
        if(infoL(adrL).namaPerusahaan == nama && infoL(adrL).jabatan == jabatan &&infoL(adrL).umurL == umur) {
            return true;
            break;
        }
        adrL = next(adrL);
    }

    return false;
}


int hitungPelamar(listL LL, string namaPerusahaan) {
    adrLowongan adrL;

    adrL = findLowongan(LL, namaPerusahaan);
    listR LR;
    LR = child(adrL);

    adrRelasi adrR;
    int i = 0;
    adrR = first(LR);
    while (adrR != nil) {
        i++;
        adrR = next(adrR);
    }
    return i;
}

void createRelasi(listR &LR) {
    first(LR) = nil;
}

adrRelasi elmRelasi(adrPelamar relasip) {
    adrRelasi R = new elmR;
    infoP(R) = relasip;
    next(R) = nil;

    return R;
}

void insertLastRelasi(listR &LR, adrRelasi iR) {
    if(first(LR) == nil) {
        first(LR) = iR;
    }
    else {
        adrRelasi R;
        R = first(LR);
        while (next(R) != nil) {
            R = next(R);
        }
        next(R) = iR;
    }
}

void tambahDataR(string &namaL, string &jabatan, int &umur, string &nama) {
    cout<<"Nama Perusahaan: ";
    cin>>namaL;
    cout<<"Jabatan Yang Ingin Dilamar: ";
    cin>>jabatan;
    cout<<"Umur Maksimal Pelamar: ";
    cin>>umur;
    cout<<"Nama Pelamar: ";
    cin>>nama;
    cout<<endl;
}

void maxLowongan(listL LL) {
    int jumlah;
    int maks = 0;
    adrLowongan adrL;
    adrL = first(LL);

    while(adrL != nil){
        jumlah = hitungPelamar(LL,infoL(adrL).namaPerusahaan);
        if(maks < jumlah){
            maks = jumlah;
        }
        adrL = next(adrL);
    }
    cout<<"Data terbanyak dari Lowongan yang di lamar yaitu "<<maks << " Data" << endl;
}

void minLowongan(listL LL) {
    int jumlah;
    adrLowongan adrL;
    adrL = first(LL);
    int minm = hitungPelamar(LL,infoL(adrL).namaPerusahaan);

    while(adrL != nil){
        jumlah = hitungPelamar(LL,infoL(adrL).namaPerusahaan);
        if(minm > jumlah){
            minm = jumlah;
        }
        adrL = next(adrL);
    }
    cout<<"Data terendah dari Lowongan yang di lamar yaitu "<<minm << " Data" << endl;
}

int menuProject() {
    cout << " === ABANG ADE PROJECT MENU === " << endl;
    cout << "1. Menambahkam Data Lowongan " << endl;
    cout << "2. Menambahkan Data Pelamar " << endl;
    cout << "3. Menyambungkan Data Pelamar Ke Lowongan " << endl;
    cout << "4. Mencari Data Lowongan " << endl;
    cout << "5. Menghapus Data Lowongan " << endl;
    cout << "6. Menampilkan Data Lowongan / Pelamar " << endl;
    cout << "7. Menampilkan Data yang sudah terhubung " << endl;
    cout << "8. Menampilkan jumlah Pelamar Pada Suatu Perusahaan " << endl;
    cout << "9. Menampilkan Data Lowongan Pekerjaan yang paling banyak dilamar " << endl;
    cout << "10. Menampilkan Data Lowongan Pekerjaan yang paling sedikit dilamar " << endl;
    cout << "0. Keluar " << endl;
    cout << "Menu : ";


    int m = 0;
    cin >> m;
    cout << endl;
    return m;
}
