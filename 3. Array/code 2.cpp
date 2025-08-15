#include <iostream>
using namespace std;

int main() {
    int A[2][3] = {{1,2,3},{4,5,6}};
    int maks = A[0][0];
    int min = A[0][0];
    for(int m = 0; m < 2; m++){
        for(int n = 0; n < 3; n++){
            if(maks < A[m][n]){
                maks = A[m][n];
            }
        }
    } 
    cout << "Nilai maksimum: " << maks << endl;

    for(int m = 0; m < 2; m++){
        for(int n = 0; n < 3; n++){
            if(min > A[m][n]){
                min = A[m][n];
            }
        }
    } 
    cout << "Nilai mininum: " << min << endl;

    int x;
    bool exist = false;
    cout << "Masukkan angka yang dicari: ";
    cin >> x;
    for(int m = 0; m < 2; m++){
        for(int n = 0; n < 3; n++){
            if(x == A[m][n]){
                exist = true;
                break;
            }
        }
    }
    if(exist == true){
        cout << "Ada elemen yang sama";
    } else{
        cout << "Tidak ada elemen yang sama";
    }
    return 0;
}