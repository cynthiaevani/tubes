//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2/4
// File Name: manual_schedule.c
// Dependency : stdio.h, stdlib.h, string.h, LIB-TUBES.h
//
// Description:
// Fungsi untuk membuat schedule secara manual
//
// Status:
// 1. Cynthia Evani - 13217045 : Buat manual schedule
//***********************************************************//

//BELOM LENGKAP:
//Deklarasi fungsi
//Link ke fungsinya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LIB-TUBES.h"

//ASUMSI
//Perintah keluar hanya bisa dimasukkan di kode praktikum
//Kalau hari sabtu atau minggu, pesan error --> di validasi


void manual_schedule()
{
    //Start variable declaration
    int cekquit;
    char *kodeprak, *rombongan, *minggu, *hari, *ruangan;
    //End declaration
    
    cekquit = (strcmp(kodeprak,"q")||strcmp(kodeprak,"Q"));

    printf("[Mode Schedule]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    
    while(cekquit == 0){
        Validasi_KodePrak(kodeprak, rombongan);
        
        Validasi_Minggu(minggu);
        
        printf("\nRuangan: ");
        if(strlen(rombongan)>1){ //Kebanyakan yang cuma 1 karakter ada subnya
            if((strcmp(kodeprak,"EL2205") == 1)){ //Kalo EL2205 pasti 2 ruangan
                printf("Ruangan 1:"); scanf("%s",ruangan->i);
                printf("Ruangan 2:"); scanf("%s",ruangan->j);
            }
            else if((strcmp(kodeprak,"EL2208") == 1)&&((strcmp(rombongan,"A")==1)||(strcmp(rombongan,"B")==1))){
                printf("Ruangan 1:"); scanf("%s",ruangan->i);
                printf("Ruangan 2:"); scanf("%s",ruangan->j);
                printf("Ruangan 3:"); scanf("%s",ruangan->k);
            }
        }
        else{
            printf("Ruangan:"); scanf("%s",ruangan->i);
        }
    }
    if(cekquit == 1){
        exit(0);
    }
}
