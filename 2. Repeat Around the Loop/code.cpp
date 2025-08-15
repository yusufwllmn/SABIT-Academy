#include <iostream>
using namespace std;

int main() {
    int jam, menit, detik, biaya, sisa, detikSisa, jamLebih, pilihKendaraan;
    bool lanjut = true;
    string kendaraan, pilihLanjut;
    
    cout << "=============== Selamat Datang ===============" << endl;
    do{
        cout << "Masukkan waktu parkir dalam detik: ";
        cin >> detik;
        cout << "Jenis kendaraan " << endl;
        cout << "1. Mobil" << endl;
        cout << "2. Motor" << endl;
        cout << "pilih jenis kendaraan: ";
        cin >> pilihKendaraan;
        switch(pilihKendaraan){
            case 1:
                kendaraan = "Mobil";
                break;
            case 2:
                kendaraan = "Motor";
                break;
        }
        
        jam = detik / 3600;
        sisa = detik % 3600;
        menit = sisa / 60;
        detikSisa = detik % 60;
    
        if(detik <= 3600){
            biaya = 1000;
        }else{
            jamLebih = jam;
            if(sisa > 0){
                jamLebih += 1; 
            }
            if(kendaraan == "Mobil"){
                biaya = 1000 + (jamLebih - 1) * 3000;
            }else if(kendaraan == "Motor"){
                biaya = 1000 + (jamLebih - 1) * 2000;
            }
        }
        
        cout << "----------------------------------------------" << endl;
        cout << "Jenis kendaraan: " << kendaraan << endl;   
        cout << "Waktu parkir: " << jam << " jam, " << menit << " menit, " << detikSisa << " detik" << endl;
        cout << "Total biaya parkir: Rp " << biaya << endl;
        cout << "----------------------------------------------" << endl;
        cout << "ingin lanjut?(y/n): ";
        cin >> pilihLanjut;
        if(pilihLanjut == "y" || pilihLanjut == "Y"){
            lanjut = true;
        }else if(pilihLanjut == "n" || pilihLanjut == "N"){
            lanjut = false;
        }else{
            lanjut = false;
        }
        cout << endl;
    }while(lanjut);
    cout << "================ Terima Kasih ================";
    return 0;
}