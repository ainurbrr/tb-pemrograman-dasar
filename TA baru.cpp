#include <stdio.h>
#include <string.h>
#include <windows.h>

int jumlahmenu=10;
char menu[10][20] = {"Nasi goreng", "Nasi Rames", "Nasi bebek", "Nasi Rawon", "Nasi Pecel", "Mie Ayam", "Bakso", "Air Putih", "Es teh", "Es jeruk"};
int harga[10] = {13000, 10000, 15000, 15000, 10000,10000, 12000, 3000, 5000, 5000};
int i, totalharga=0, jumlahpesanan[20], pilihanmenu[20], bayar, kembalian;


void printmenu(){
	printf("-------------------------------------------------------------\n");
    printf("\t======SELAMAT DATANG DI RUMAH MAKAN SEDERHANA======\n");
    printf("-------------------------------------------------------------\n");
    printf("Silahkan pilih menu makanan atau minuman yang kami sediakan\n\n");
    for(i=0; i<jumlahmenu; i++){
        printf("\t\t%d. %s : Rp. %d\n\n", i+1, menu[i], harga[i]);
    }
}

void printrincian(){
	
	printf("=============================================================================\n");
    printf("Total harga yang harus dibayar adalah %d dengan rincian sebagai berikut : \n", totalharga);
    printf("=============================================================================\n");
    for(i=0; i<10; i++){
        if(pilihanmenu[i]>0){
            printf("%d. %d %s %dx%d = %d\n",i+1, jumlahpesanan[i], menu[pilihanmenu[i]-1], jumlahpesanan[i], harga[pilihanmenu[i]-1], jumlahpesanan[i]*harga[pilihanmenu[i]-1]);
        }
    }
    bayar :
    printf("Masukkan jumlah pembayaran : Rp. ");
    scanf("%d", &bayar);
    kembalian=bayar-totalharga;
    if(bayar<totalharga){
    	system("color 4");
    	printf("Mohon maaf uang anda tidak cukup\n");
    	printf("Total harga pesanan anda Rp. %d\n\n\n", totalharga);
    	goto bayar;
	}
	system("color A");
    printf("Kembalian : Rp. %d\n", kembalian);
    printf("Terimakasih Telah Mampir di rumah makan kami\n");
    printf("=============================================================================\n");
}

int main(){
    int pilihmenu, jumlah, pilih=1, ipesanan;
    system("color 9");
    while(pilih == 1){
        printmenu();
        printf("masukkan pesanan : ");
        scanf("%d",&pilihmenu);
        printf("masukkan jumlah : ");
        scanf("%d", &jumlah);
        totalharga = totalharga + jumlah*harga[pilihmenu-1];
        pilihanmenu[ipesanan] = pilihmenu;
        jumlahpesanan[ipesanan] =jumlah;
        ipesanan++;
        printf("berhasil menambahkan %d %s ke dalam pesanan, apakah ingin menambah pesanan ?\n",jumlah, menu[pilihmenu-1]);
        printf("1. Yes\n2. NO\n");
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilih);
    }
    printrincian();

    return 0;
}
