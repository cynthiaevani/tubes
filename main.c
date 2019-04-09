//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2/4
// File Name: main.c
// Dependency : stdio.h, stdlib.h, string.h, LIB-TUBES.h
//
// Description:
// Program utama.
//
// Status:
// 1. Cynthia Evani - 13217045 : Buat main
//***********************************************************//

//BELOM LENGKAP:
//Deklarasi fungsi
//Link ke fungsinya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LIB-TUBES.h"

//ASUMSI:
//Nama proyek tidak lebih dari 30 karakter
//Schedule harus sudah ada sebelum assign asisten secara manual
//Masukan file eksternal selalu benar

int main() {
    int mainchoice, subchoice;
    char *projectname;
    
    projectname = (char*)malloc(30*sizeof(char));
    
    //Menu Utama
    printf("Menu: \n");
    printf("1. Buat Proyek Baru \n");
    printf("2. Muat Proyek dari Berkas \n");
    printf("3. Keluar \n");
    printf("Masukan: "); scanf("%d",&mainchoice);
    
    
    if(mainchoice == 3){
        return 0;
    }
    else{
        if(mainchoice == 1){
            printf("===== Membuat Proyek Baru =====\n");
            printf("Masukkan nama proyek: "); scanf("%s", projectname);
        }
        else if(mainchoice == 2){
            printf("===== Memuat Proyek dari Berkas =====");
            printf("Masukkan nama proyek yang ingin dimuat: "); scanf("%s", projectname);
            Load_Project(strcpy(projectname).csv);//Ofel
        }
        //Submenu
        printf("[Menu Utama]\n");
        printf("Pilih Mode: \n");
        printf("1. Tampilkan Schedule\n");
        printf("2. Schedule Manual\n");
        printf("3. Tampilkan Status Assignment Asisten\n");
        printf("4. Assign Asisten Manual\n");
        printf("5. Schedule Otomatis\n");
        printf("6. Assign Otomatis\n");
        printf("7. Rule Checker\n");
        printf("8. Simpan Proyek dan Keluar\n");
        printf("Pilih Mode: "); scanf("%d", &subchoice);
        
        while(subchoice != 8){
            if(subchoice == 1){
                View_Schedule(bdwbd2bk);//Justin
            }
            else if(subchoice == 2){
                Manual_Schedule(ndkje3jkd3b);//Cynthia
            }
            else if(subchoice == 3){
                View_Assistant(dkbewdjkbjkd);//Justin
            }
            else if(subchoice == 4){
                Manual_Assistant(bskjwbdws);//Gihon
            }
            else if(subchoice == 5){
                Automatic_Schedule(bewbdw);//keroyokan
            }
            else if(subchoice == 6){
                Automatic_Assistant(bcdwjkbewk);//keroyokan
            }
            else if(subchoice == 7){
                Rule_Checker(bjkbdejkwbd);//Ofel
            }
        }
        if(subchoice == 8){
            Save_and_Quit(kjbdjkbe2);
        }
    }
    
    return 0;
}
