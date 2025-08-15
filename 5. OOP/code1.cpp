#include <iostream>
using namespace std;

class BilanganGenap {
public:
    int n;

    int JumlahBilanganGenap() {
        int jumlah = 0;
        for (int i = 0; i < n; i++) {
            jumlah += i * 2;
        }
        return jumlah;
    }

    void TampilkanHasil() {
        cout << "Jumlah " << n << " bilangan genap pertama adalah " << JumlahBilanganGenap() << endl;
    }
};

int main() {
    BilanganGenap bilanganGenap;
    cout << "Berapa bilangan genap yang ingin dijumlahkan: ";
    cin >> bilanganGenap.n;

    bilanganGenap.TampilkanHasil();
    return 0;
}
