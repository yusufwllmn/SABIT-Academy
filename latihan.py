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