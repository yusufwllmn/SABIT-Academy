#include <iostream>
using namespace std;

void JumlahBilanganGenap(int n){
    int jumlah = 0;
    for(int i = 0; i < n; i++){
        jumlah += i * 2;
    }
    cout << "Jumlah " << n << " bilangan genap pertama adalah " << jumlah;
}

int main() {
    int n;
    cout << "Berapa bilangan genap yang ingin dijumlahkan: ";
    cin >> n;
    JumlahBilanganGenap(n);
}