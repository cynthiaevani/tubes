//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2/4
// File Name: manual_schedule.c
// Dependency : stdio.h, stdlib.h, string.h
//
// Description:
// Fungsi untuk membuat schedule secara manual
//
// Status:
// 1. Cynthia Evani - 13217045 : Create the file
// 2. <Nama Praktikan> - <NIM> : Fix the bug where number 2 printed twice
//***********************************************************//

//BELOM LENGKAP:
//Deklarasi fungsi
//Link ke fungsinya

//Last debugged: 9 Apr 17.59 by Cynthia
//  Benerin fungsi validasi


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ASUMSI
//Perintah keluar hanya bisa dimasukkan di kode praktikum
//Kalau hari sabtu atau minggu, pesan error --> di validasi


void manual_schedule()
{
    typedef struct ruangan_s{
        char *i, *j, *k;
    }ruangan_t;
    
    char *kodeprak, *rombongan, *minggu, *hari;
    int cekquit;
    ruangan_t *ruangan;
    
    kodeprak = (char*)malloc(6*sizeof(char));
    rombongan = (char*)malloc(2*sizeof(char));
    minggu = (char*)malloc(2*sizeof(char));
    hari = (char*)malloc(8*sizeof(char));
    ruangan = (ruangan_t*)malloc(4*sizeof(ruangan_t));
    
    cekquit = (strcmp(kodeprak,"q")||strcmp(kodeprak,"Q"));

    printf("[Mode Schedule]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    
    while(cekquit == 0){
        Validasi_KodePrak(kodeprak);
        if(strcmp(kodeprak,"EL2205") == 1){
            Validasi_Rombongan(rombongan.elka);
        }
        else if(strcmp(kodeprak,"EL2208") == 1){
            Validasi_Rombongan(rombongan.pmc);//taudah
        }
        else{
            Validasi_Rombongan(rombongan.ptb);//taudah
        }
        
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
