#include <iostream>
using namespace std;

int main() {
    int jam, menit, detik, biaya, sisa, detikSisa, jamLebih;
    
    cout << "Masukkan waktu parkir dalam detik: ";
    cin >> detik;
    
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
        biaya = 1000 + (jamLebih - 1) * 2000;
    }
    
    cout << "Waktu parkir: " << jam << " jam, " << menit << " menit, " << detikSisa << " detik" << endl;
    cout << "Total biaya parkir: Rp " << biaya;
    return 0;
}