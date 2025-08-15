#include <iostream>
using namespace std;

class Waktu {
public:
    int hh, mm, ss;

    void InputWaktu() {
        cout << "masukkan jam: "; cin >> hh;
        cout << "masukkan menit: "; cin >> mm;
        cout << "masukkan detik: "; cin >> ss;
    }

    void FormatWaktu() {
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

    int TotalDetik() {
        return hh * 3600 + mm * 60 + ss;
    }
};

class Selisih {
public:
    int SelisihDetik(Waktu w1, Waktu w2) {
        int total1 = w1.TotalDetik();
        int total2 = w2.TotalDetik();
        int temp;
        if (total1 < total2){
            temp = total1;
            total1 = total2;
            total2 = temp;
        }
        return total1 - total2;
    }

    void TampilkanSelisih(int detikSelisih) {
        Waktu waktu;
        int jam = detikSelisih / 3600;
        int sisa = detikSelisih % 3600;
        int menit = sisa / 60;
        int detik = sisa % 60;

        waktu.hh = jam;
        waktu.mm = menit;
        waktu.ss = detik;
        waktu.FormatWaktu();
    }
};

int main() {
    Waktu w1, w2;
    Selisih selisih;

    cout << "Waktu pertama" << endl;
    w1.InputWaktu();
    cout << "Waktu kedua" << endl;
    w2.InputWaktu();

    int durasi = selisih.SelisihDetik(w1, w2);

    cout << endl;
    cout << "Waktu Pertama: ";
    w1.FormatWaktu();
    cout << endl;

    cout << "Waktu Kedua: ";
    w2.FormatWaktu();
    cout << endl;

    cout << "Selisihnya adalah ";
    selisih.TampilkanSelisih(durasi);

    return 0;
}
