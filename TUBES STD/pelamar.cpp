#include "pelamar.h"

void createListPelamar(listP &LP){
    first(LP) = nil;
}

adrPelamar elmPelamar(infoP iP){
    adrPelamar adrP;
    adrP = new elmP;
    infoP(adrP).namaP = iP.namaP;
    infoP(adrP).jenisK = iP.jenisK;
    infoP(adrP).jabatan = iP.jabatan;
    infoP(adrP).umurP = iP.umurP;
    nextP(adrP) = nil;

    return adrP;
}

void insertLastPelamar(listP &LP, adrPelamar iP){
    if(first(LP) == nil){
        first(LP) = iP;
    }else{
        adrPelamar adrP;
        adrP = first(LP);
        while(nextP(adrP) != nil){
            adrP = nextP(adrP);
        }
        nextP(adrP) = iP;
    }
}

void deleteLastPelamar(listP &LP, adrPelamar &iP){
    if(first(LP) == nil){
        cout<<"List Kosong";
    }else{
        adrPelamar adrP;
        adrP = first(LP);
        while(nextP(nextP(adrP)) != nil){
            adrP = nextP(adrP);
        }
        iP = nextP(adrP);
        nextP(adrP) = nil;
    }
}

void showPelamar(listP LP){
    if (first(LP) == nil){
        cout<<"Data Pelamar Kosong"<<endl;
    }else{
        adrPelamar adrP;
        adrP = first(LP);
        while(adrP != nil){
            cout<<"Nama Pelamar: "<<infoP(adrP).namaP<<endl;
            cout<<"Umur Pelamar: "<<infoP(adrP).umurP<<endl;
            cout<<"Jenis Kelamin: "<<infoP(adrP).jenisK<<endl;
            cout<<"Jabatan Yang Ingin Di Lamar: "<<infoP(adrP).jabatan<<endl;
            cout<<endl;
            adrP = nextP(adrP);
        }
    }
}

adrPelamar findPelamar(listP &LP, string namaP){
    if (first(LP) == nil){
        cout<<"Data Pelamar Kosong"<<endl;
    }else{
        adrPelamar adrP;
        adrP = first(LP);
        while(adrP != nil){
            if(infoP(adrP).namaP == namaP){
                return adrP;
                break;
            }
            adrP = nextP(adrP);
        }

    }
    return nil;
}

infoP inputPelamar(infoP &input){
    cout<<"Nama: ";
    cin>>input.namaP;
    cout<<"Umur: ";
    cin>>input.umurP;
    cout<<"Jenis Kelamim: ";
    cin>>input.jenisK;
    cout<<"Melamar Sebagai: ";
    cin>>input.jabatan;
    cout<<endl;

    return input;
}

bool cekPelamar(listP LP, string nama, string jabatan, int umur) {
    adrPelamar adrP;
    adrP = first(LP);
    while (adrP != nil) {
        if(infoP(adrP).namaP == nama && infoP(adrP).jabatan == jabatan &&infoP(adrP).umurP == umur) {
            return true;
            break;
        }
        else {
            return false;
        }
        adrP = nextP(adrP);
    }
}
