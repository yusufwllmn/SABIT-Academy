# #include <iostream>
# usingnamespace std;

# int main(){
# 	int nilai;
# 	cout << "Masukkan nilai: ";
# 	cin >> nilai;

# 	if(nilai >= 80 && nilai <= 100){
#         cout << "Nilai anda A";
#     }else if(nilai >= 70 && nilai <= 79){
#         cout << "Nilai anda B";
#     }else if(nilai >= 60 && nilai <= 69){
#         cout << "Nilai anda C";
#     }else if(nilai >= 50 && nilai <= 59){
#         cout << "Nilai anda D";
#     }else if(nilai >= 0 && nilai <= 49){
#         cout << "Nilai anda E";
#     }else{
#         cout << "Input tidak valid!!";
#     }
#     return 0;
# }

# nilai = int(input("\nMasukkan nilai: "))
# if(nilai >= 80) & (nilai <= 100):
#     print("Nilai anda A")
# elif(nilai >= 70) & (nilai <= 79):
#     print("Nilai anda B")
# elif(nilai >= 60) & (nilai <= 69):
#     print("Nilai anda C")
# elif(nilai >= 50) & (nilai <= 59):
#     print("Nilai anda D")
# elif(nilai >= 0) & (nilai <= 49):
#     print("Nilai anda E")
# else:
#     print("Input tidak valid!")
# print("\n")

# if((nilai <= 100) & (nilai >= 0)):
#     if(nilai >= 80):
#         print("Nilai anda A")
#     elif(nilai >= 70):
#         print("Nilai anda B")
#     elif(nilai >= 60):
#         print("Nilai anda C")
#     elif(nilai >= 50):
#         print("Nilai anda D")
#     elif(nilai >= 0):
#         print("Nilai anda E")
#     else:
#         print("Input tidak valid!")
# else:
#     print("Masukkan nilai dengan rentang 0-100")

# a = int(input("Masukkan a: "))
# b = int(input("Masukkan b: "))
# if(a < b):
#     c = a
#     a = b
#     b = c    
# print("Selisih nilai adalah", a-b)
    
totalHarga = float(input("\nTotal Harga: "))
diskon = 0
bonus = "Tidak ada"

if(totalHarga > 0):
    if(totalHarga >= 5000000):
        diskon = 0.1 * totalHarga
        bonus = "Tas"
    elif(totalHarga >= 1000000):
        diskon = 0.09 * totalHarga
        bonus = "payung"
    elif(totalHarga >= 500000):
        diskon = 0.07 * totalHarga
        bonus = "Piring"
    elif(totalHarga >= 200000):
        diskon = 0.5 * totalHarga
        bonus = "Pulpen"
else:
    print("Masukkan harga dengan benar")
  
if((diskon != 0) & (bonus != "Tidak ada")):
    print("Anda mendapat diskon", diskon, "dan bonus", bonus)
    totalHarga -= diskon
    
print("Total Bayar:", totalHarga)
bayar = float(input("Jumlah bayar: "))
if(bayar >= totalHarga):
    kembalian = bayar - totalHarga
    if(kembalian != 0):
        print("kembalian anda", kembalian)
    print("Transaksi Berhasil")
else:
    print("Jumlah bayar kurang, Transaksi gagal")
print("\n")