#include <iostream>
using namespace std;

int main() {
    int a[5] = {1,1,1,1,1};
    int pivot = a[0];
    bool check = true;
    for(int n = 0; n < 5; n++){
        if(pivot != a[n]){
            check = false;
            break;
        }
    }
    if(check == true){
        cout << "Semua elemen array sama" << endl;
    } else{
        cout << "Tidak semua elemen array sama" << endl;
    }
    return 0;
}