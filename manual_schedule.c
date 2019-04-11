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
//Link ke fungsinya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LIB-TUBES.h"

//ASUMSI
//Perintah keluar hanya bisa dimasukkan di kode praktikum

Dbs_Type Prak;

void manual_schedule()
{
    //Deklarasi variabel
    int cekquit;
    char kodeprak[7];
    char rombongan[4];
    int minggu;
    char hari[10];
    int ruangan[4];
    //End deklarasi

    printf("[Mode Schedule]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    
    //Input dan validasi
    Validasi_KodePrak(kodeprak);
    cekquit = (strcmp(kodeprak,"q")||strcmp(kodeprak,"Q")); //bernilai 1 jika input "q" atau "Q"
    while(cekquit == 0){
        //Input dan validasi
        Validasi_Rombongan(kodeprak, rombongan);
        Validasi_Minggu(minggu);
        Validasi_Hari(hari);
        Validasi_Ruangan(ruangan);
        Validasi_KodePrak(kodeprak, rombongan);
        cekquit = (strcmp(kodeprak,"q")||strcmp(kodeprak,"Q")); //bernilai 1 jika input "q" atau "Q"
        
        //Assign
        Prak[minggu].hari[ruangan]->Kode = kodeprak;
        Prak[minggu].hari[ruangan]->Romb = rombongan;
    }
    if(cekquit == 1){
        exit(0);
    }
}
