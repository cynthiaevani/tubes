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
    
    cekquit = (strcmp(kodeprak,"q")||strcmp(kodeprak,"Q")); //bernilai 1 jika input "q" atau "Q"

    printf("[Mode Schedule]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    
    Validasi_KodePrak(kodeprak);
    while(cekquit == 0){
        Validasi_Rombongan(kodeprak, rombongan);
        Validasi_Minggu(minggu);
        Validasi_Hari(hari);
        Validasi_Ruangan(...);
        Validasi_KodePrak(kodeprak, rombongan);
    }
    if(cekquit == 1){
        exit(0);
    }
}
