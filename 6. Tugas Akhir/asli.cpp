#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Akun{
    string nomorRekening;
    string pin;
    double saldo;
    int salahPin;
    bool blokir;
    time_t waktuBlokir;
};
vector<Akun> akun;

bool ValidasiDigit(string input, int panjang){
    if(input.length() != panjang){
        return false;
    }
    for(int i = 0; i < input.length(); i ++){
        if(input[i] < '0' || input[i] > '9'){
            return false;
        }
    }
    return true;
}

bool ValidasiKelipatan(int jumlah){
    if(jumlah < 0 || jumlah % 50000 != 0){
        return false;
    }
    return true;
}

bool Login(string nomorRekening, string pin, int &index){
    if(!ValidasiDigit(nomorRekening, 10)){
        cout << "Nomor rekening harus 10 digit angka" << endl;
        return false;
    }
    
    if(!ValidasiDigit(pin, 6)){
        cout << "PIN harus 6 digit angka" << endl;
        return false;
    }

    for(int i = 0; i < akun.size(); i++){
        if(akun[i].nomorRekening == nomorRekening){
            if(akun[i].blokir){
                time_t sekarang = time(0);
                double detikBerlalu = difftime(sekarang, akun[i].waktuBlokir);
                if(detikBerlalu < 180){
                    cout << "Akun masih diblokir. Tunggu " << (180 - detikBerlalu) << " detik lagi." << endl;
                    return false;
                }else{
                    akun[i].blokir = false;
                    akun[i].salahPin = 0;
                    akun[i].waktuBlokir = 0;
                }
            }
            
            if(akun[i].pin == pin){
                akun[i].salahPin = 0;
                index = i;
                return true;
            }else{
                akun[i].salahPin += 1;
                if(akun[i].salahPin >= 3){
                    akun[i].blokir = true;
                    akun[i].waktuBlokir = time(0);
                    cout << "Akun diblokir" << endl;
                }else{
                    cout << "PIN salah. Sisa " << (3 - akun[i].salahPin) << " percobaan" << endl;
                }
                return false;
            }
        }
    }
    return false;
}

void Daftar(){
    Akun newAkun;
    string nomorRekening, pin;
    
    while(true){
        cout << "\n========== Daftar Akun ==========" << endl;
        cout << "Masukkan Nomor Rekening (10 digit angka): ";
        cin >> nomorRekening;
        if(nomorRekening == "batal"){
            cout << "=================================" << endl;
            cout << "Pendaftaran dibatalkan" << endl;
            cout << "=================================" << endl;
            return;
        }

        cout << "Masukkan PIN (6 digit angka): ";
        cin >> pin;
        if(pin == "batal"){
            cout << "=================================" << endl;
            cout << "Pendaftaran dibatalkan" << endl;
            cout << "=================================" << endl;
            return; 
        }

        bool cekNomorRekening = ValidasiDigit(nomorRekening, 10);
        bool cekPin = ValidasiDigit(pin, 6);
        bool cekRekening = true;

        for(int i = 0; i < akun.size(); i++){
            if(akun[i].nomorRekening == nomorRekening){
                cekRekening = false;
                break;
            }
        }

        if(!cekNomorRekening || !cekRekening|| !cekPin){
            cout << "=================================" << endl;
            if(!cekNomorRekening){
                cout << "Nomor rekening harus 10 digit angka" << endl;
            }
            if(!cekPin){
                cout << "PIN harus 6 digit angka" << endl;
            }
            if(!cekRekening){
                cout << "Nomor rekening sudah terdaftar" << endl;
            }
            cout << "=================================" << endl;
            cout << "Silakan coba lagi atau ketik 'batal' untuk keluar" << endl;
            cout << "=================================" << endl;
            continue;
        }

        newAkun.nomorRekening = nomorRekening;
        newAkun.pin = pin;
        newAkun.salahPin = 0;
        newAkun.blokir = false;
        newAkun.waktuBlokir = 0;
        break;
    }

    do{
        cout << "Masukkan Saldo Awal: ";
        cin >> newAkun.saldo;
        if(cin.fail() || newAkun.saldo <= 0){
            cout << "Saldo awal tidak valid" << endl;
        }else{
            break;
        }
    }while(true);

    akun.push_back(newAkun);
    cout << "=================================" << endl;
    cout << "Akun berhasil didaftarkan" << endl;
    cout << "=================================" << endl;
}

int Menu(int index){
    int pilihan;
    
    cout << "\n============= Menu ==============" << endl;
    cout << "Rekening saat ini : " << akun[index].nomorRekening << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Setor Tunai" << endl;
    cout << "3. Tarik Tunai" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. Keluar" << endl;
    while(true){
        cout << "pilih Menu: ";
        if(cin >> pilihan){
            break;
        }else{
            cout << "Input harus angka bulat" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return pilihan;
}

void CekSaldo(int index){
    cout << "\n============= Saldo =============" << endl;
    cout << "Saldo anda: Rp" << akun[index].saldo << endl;
    cout << "=================================" << endl;
}

void SetorTunai(int index){
    int jumlah;

    cout << "\n========== Setor Tunai ==========" << endl;
    cout << "Minimal Setor Rp50000 dengan kelipatan Rp50000" << endl;
    while(true){
        cout << "Masukkan nominal setoran: ";
        if(cin >> jumlah){
            break;
        }else{
            cout << "Input harus angka bulat" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    
    if(jumlah >= 50000 && ValidasiKelipatan(jumlah)){
        akun[index].saldo += jumlah;
        cout << "=================================" << endl;
        cout << "Setor Tunai berhasil" << endl;
        cout << "Saldo Anda sekarang Rp" << akun[index].saldo << endl;
    }else{
        cout << "=================================" << endl;
        cout << "Nominal Setoran tidak valid (minimal Rp50000 dengan kelipatann Rp50000)"<< endl;
    }
    cout << "=================================" << endl;
}

int MenuInstant(){
    int pilihan;
    
    cout << "Pilih nominal transaksi:" << endl;
    cout << "1. Rp50000" << endl;
    cout << "2. Rp100000" << endl;
    cout << "3. Rp200000" << endl;
    cout << "4. Rp500000" << endl;
    cout << "5. Rp1000000" << endl;
    cout << "6. Nominal lain" << endl;
    while(true){
        cout << "pilih Opsi: ";
        if(cin >> pilihan){
            break;
        }else{
            cout << "Input harus angka bulat" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return pilihan;
}

void TarikTunai(int index){
    int jumlah;
    int pilihan;
    
    cout << "\n========== Tarik Tunai ==========" << endl;
    pilihan = MenuInstant();
    if(pilihan == 1){
        jumlah = 50000;    
    }else if(pilihan == 2){
        jumlah = 100000;  
    }else if(pilihan == 3){
        jumlah = 200000;
    }else if(pilihan == 4){
        jumlah = 500000;     
    }else if(pilihan == 5){
        jumlah = 1000000; 
    }else if(pilihan == 6){
        cout << "Minimal penarikan Rp50000 dengan kelipatan Rp50000: " << endl;
        while(true){
            cout << "Masukkan nominal penarikan: ";
            if(cin >> jumlah){
                break;
            }else{
                cout << "Input harus angka bulat" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }else{
        cout << "=================================" << endl;
        cout << "Opsi Tidak Valid" << endl;
        cout << "=================================" << endl;
        return;
    }
    
    if(jumlah >= 50000 && ValidasiKelipatan(jumlah) &&jumlah <= akun[index].saldo){
        akun[index].saldo -= jumlah;
        cout << "=================================" << endl;
        cout << "Penarikan Tunai berhasil" << endl;
        cout << "Saldo Anda sekarang Rp" << akun[index].saldo << endl;
    }else{
        cout << "=================================" << endl;
        cout << "Nominal penarikan tidak valid (minimal Rp50000 dengan kelipatan RP50000) atau saldo tidak cukup" << endl;
    }
    cout << "=================================" << endl;
}

void Transfer(int index){
    string rekeningTujuan;
    int jumlah;
    int indexTujuan = -1;
    int pilihan;

    
    cout << "\n============ Transfer ===========" << endl;
    while(true){
        cout << "Masukkan nomor rekening tujuan (ketik 'batal' untuk keluar): ";
        cin >> rekeningTujuan;

        if(rekeningTujuan == "batal"){
            cout << "=================================" << endl;
            cout << "Transfer dibatalkan" << endl;
            cout << "=================================" << endl;
            return;
        }

        if(!ValidasiDigit(rekeningTujuan, 10)){
            cout << "=================================" << endl;
            cout << "Nomor rekening tujuan harus 10 digit angka" << endl;
            cout << "=================================" << endl;
            continue;
        }

        if(rekeningTujuan == akun[index].nomorRekening){
            cout << "=================================" << endl;
            cout << "Tidak dapat transfer ke rekening sendiri" << endl;
            cout << "=================================" << endl;
            continue;
        }

        for(int i = 0; i < akun.size(); i++){
            if(akun[i].nomorRekening == rekeningTujuan){
                indexTujuan = i;
                break;
            }
        }

        if(indexTujuan == -1){
            cout << "=================================" << endl;
            cout << "Nomor rekening tujuan tidak ditemukan" << endl;
            cout << "=================================" << endl;
            continue;
        }
        break;
    }
    cout << endl;
    pilihan = MenuInstant();
    if(pilihan == 1){
        jumlah = 50000;    
    }else if(pilihan == 2){
        jumlah = 100000;  
    }else if(pilihan == 3){
        jumlah = 200000;
    }else if(pilihan == 4){
        jumlah = 500000;     
    }else if(pilihan == 5){
        jumlah = 1000000; 
    }else if(pilihan == 6){
        while(true){
            cout << "Masukkan nominal transfer: ";
            if(cin >> jumlah){
                break;
            }else{
                cout << "Input harus angka bulat" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }else{
        cout << "=================================" << endl;
        cout << "Opsi Tidak Valid" << endl;
        cout << "=================================" << endl;
        return;
    }
    if(jumlah > 0 && jumlah <= akun[index].saldo){
        akun[index].saldo -= jumlah;
        akun[indexTujuan].saldo += jumlah;
        cout << "=================================" << endl;
        cout << "Transfer berhasil" << endl;
        cout << "Saldo Anda sekarang Rp" << akun[index].saldo << endl;
    }else{
        cout << "=================================" << endl;
        cout << "Nominal transfer tidak valid atau saldo tidak cukup" << endl;
    }
    cout << "=================================" << endl;
}


int main() {
    int pilihan;
    string nomorRekening, pin;
    int index = -1;

    cout << "======== Selamat Datang =========" << endl;
    do{
        
        cout << "\n============== ATM ==============" << endl;
        cout << "1. Login Akun" << endl;
        cout << "2. Daftar Akun" << endl;
        cout << "3. Keluar" << endl;
        while(true){
            cout << "pilih Menu: ";
            if(cin >> pilihan){
                break;
            }else{
                cout << "Input harus angka bulat" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        if(pilihan == 1){
            cout << "\n============= Login =============" << endl;
            cout << "Masukkan Nomor Rekening: ";
            cin >> nomorRekening;
            cout << "Masukkan PIN: ";
            cin >> pin;
            if(Login(nomorRekening, pin, index)){
                cout << "=================================" << endl;
                cout << "Login berhasil" << endl;
                cout << "=================================" << endl;
                do{
                    pilihan = Menu(index);
                    if(pilihan == 1){
                        CekSaldo(index);    
                    }else if(pilihan == 2){
                        SetorTunai(index);  
                    }else if(pilihan == 3){
                        TarikTunai(index);
                    }else if(pilihan == 4){
                        Transfer(index);     
                    }else if(pilihan == 5){
                        cout << "=================================" << endl;
                        cout << "Keluar dari Akun" << endl;
                        break;
                    }else{
                        cout << "=================================" << endl;
                        cout << "Opsi Tidak Valid" << endl;
                        cout << "=================================" << endl;
                    }
                }while(pilihan != 5);
            }else{
                cout << "=================================" << endl;
                cout << "Nomor Rekening atau PIN salah" << endl;
                cout << "=================================" << endl;
            }
        }else if(pilihan == 2){
            Daftar();
        }else if(pilihan == 3){
            cout << "=================================" << endl;
            cout << "Keluar dari ATM" << endl;
            cout << "=================================" << endl;
            break;
        }else{
            cout << "=================================" << endl;
            cout << "Opsi tidak valid" << endl;
            cout << "=================================" << endl;
        }
    }while(pilihan != 3);
    cout << "\n=================================" << endl;
    cout << "========= Terima Kasih ==========" << endl;
    cout << "=================================" << endl;
    cin.ignore(10000, '\n');
    cin.get();
    return 0;
}