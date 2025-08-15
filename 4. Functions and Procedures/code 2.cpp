#include <iostream>
using namespace std;

int SelisihWaktu(int hh1, int mm1, int ss1, int hh2, int mm2, int ss2){
    int total1, total2, temp, selisih;
    total1 = hh1 * 3600 + mm1 * 60 + ss1;
    total2 = hh2 * 3600 + mm2 * 60 + ss2;
    
    if(total1 < total2){
        temp = total1;
        total1 = total2;
        total2 = temp;
    }
    selisih = total1 - total2;
    return selisih;
}

void FormatWaktu(int hh, int mm, int ss){
    if(hh < 10){
        cout << "0" << hh;
    }else{
        cout << hh;
    }
    cout << ":";
    if(mm < 10){
        cout << "0" << mm;
    }else{
        cout << mm;
    }
    cout << ":";
    if(ss < 10){
        cout << "0" << ss;
    }else{
        cout << ss;
    }
}

int main() {
    int hh1, hh2, mm1, mm2, ss1, ss2;
    int durasi;
    int jam, menit, detik, sisa;
    cout << "Waktu pertama" << endl;
    cout << "masukkan jam: "; cin >> hh1;
    cout << "masukkan menit: "; cin >> mm1;
    cout << "masukkan detik: "; cin >> ss1;
    cout << "Waktu kedua" << endl;
    cout << "masukkan jam: "; cin >> hh2;
    cout << "masukkan menit: "; cin >> mm2;
    cout << "masukkan detik: "; cin >> ss2;
    
    durasi = SelisihWaktu(hh1, mm1, ss1, hh2, mm2, ss2);
    
    jam = durasi / 3600;
    sisa = durasi % 3600;
    menit = sisa / 60;
    detik = sisa % 60;
    
    cout << endl;
    cout << "Waktu Pertama: ";
    FormatWaktu(hh1, mm1, ss1);
    cout << endl;
    cout << "Waktu Kedua: ";
    FormatWaktu(hh2, mm2, ss2);
    cout << endl;
    cout << "Selisihnya adalah ";
    FormatWaktu(jam, menit, detik);
    
    return 0;
}