//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2/4
// File Name: main.c
// Dependency : stdio.h, stdlib.h, string.h, LIB-TUBES.h
//
// Description:
// Membuat schedule secara manual berdasarkan input dari user
//
// Status:
// 1. Cynthia Evani - 13217045 : Buat file
// 2. Christian Justin - 13217031 : Buat validasi
// 3. Gihon Marten Tumbelaka - 13217038 : Buat validasi
//***********************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LIB-TUBES.h"

// KASUS : PRAKTIKUM PMC SAMA ELKA BARENGAN
// MASALAH : Rule Checker (file eksternal berisi hari libur nasional dan kelas atau ujian Mendadak)

void manual_schedule(){
    char kodeprak[10], asst[10];
    struct inputpraktikum assign;
    struct Dbs tabelOut;
    int j;
    int cekquit = 0;

    // INISIALISASI STRUCT TABEL DENGAN CHAR " "
    //for(int i = 0; i < 13; i++)
    //{
//        for(int j = 0; j < 4; j++)
//        {
//            strcpy(tabelOut.Prak[i].Senin[j].Kode, "     ");
//            strcpy(tabelOut.Prak[i].Selasa[j].Kode, "     ");
//            strcpy(tabelOut.Prak[i].Rabu[j].Kode, "     ");
//            strcpy(tabelOut.Prak[i].Kamis[j].Kode, "     ");
//            strcpy(tabelOut.Prak[i].Jumat[j].Kode, "     ");
//            strcpy(tabelOut.Prak[i].Senin[j].Romb, "  ");
//            strcpy(tabelOut.Prak[i].Selasa[j].Romb, "  ");
//            strcpy(tabelOut.Prak[i].Rabu[j].Romb, "  ");
//            strcpy(tabelOut.Prak[i].Kamis[j].Romb, "  ");
//            strcpy(tabelOut.Prak[i].Jumat[j].Romb, "  ");            
//        }
//    }

while(cekquit == 0){ // LOOPING UNTIL QUIT. HARUSNYA DI SAVE DI AKHIR
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        scanf("%s", &kodeprak);
        cekquit = (strcmp(kodeprak,"q") == 0 || strcmp(kodeprak,"Q") == 0);
        while (strcmp(kodeprak,"EL2205")!= 0 && strcmp(kodeprak,"EL2208")!= 0 && strcmp(kodeprak,"EB2200")!= 0 && strcmp(kodeprak,"q")!= 0 &&strcmp(kodeprak,"Q")!= 0)
        {
            printf("Input tidak valid.\n");
            printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
            scanf("%s", &kodeprak);
            cekquit = (strcmp(kodeprak,"q") == 0 || strcmp(kodeprak,"Q") == 0);
            if (cekquit == 1) {
                cekquit = 1;
            }
        }


    if (strcmp(kodeprak,"EL2205") == 0) // PENGOLAHAN DATA PRAKTIKUM ELEKTRONIKA. INPUT SEKALIGUS VALIDASI
    { 
        printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
        scanf("%s", &assign.elka.rombongan);                
            while(strcmp(assign.elka.rombongan,"A")!= 0 && strcmp(assign.elka.rombongan,"B")!= 0 && strcmp(assign.elka.rombongan,"C")!= 0 && strcmp(assign.elka.rombongan,"A1")!= 0
                && strcmp(assign.elka.rombongan,"A2")!= 0 &&strcmp(assign.elka.rombongan,"B1")!= 0 && strcmp(assign.elka.rombongan,"B2")!= 0 && strcmp(assign.elka.rombongan,"C1")!=0
                &&strcmp(assign.elka.rombongan,"C2")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
            scanf("%s", &assign.elka.rombongan);
            }

        printf("Minggu ke: ");
        scanf("%d", &assign.elka.minggu);
            while(assign.elka.minggu < 3 || assign.elka.minggu > 14){
            printf("Minggu ke: ");
            scanf("%d", &assign.elka.minggu);
            }

        printf("Hari: ");
        scanf("%s", &assign.elka.hari);
            while (strcmp(assign.elka.hari,"Senin")!= 0 && strcmp(assign.elka.hari,"Selasa")!= 0 && strcmp(assign.elka.hari,"Rabu")!= 0 && strcmp(assign.elka.hari,"Kamis")!= 0
                    && strcmp(assign.elka.hari,"Jumat")){
            printf("Hari: ");
            scanf("%s", &assign.elka.hari);
            }

        if (strcmp(assign.elka.rombongan, "A")==0 || strcmp(assign.elka.rombongan, "B")==0 || strcmp(assign.elka.rombongan, "C")==0){
            for(int i = 0; i < 2; i++)
            {
                printf("Ruangan %d: ", i+1);
                scanf("%s", &assign.elka.ruangan[i]);
            while (strcmp(assign.elka.ruangan[i],"LAB1")!= 0 && strcmp(assign.elka.ruangan[i],"LAB2")!= 0 && strcmp(assign.elka.ruangan[i],"LAB3")!= 0)
            {
                printf("Ruangan %d: ", i+1);
                scanf("%s", &assign.elka.ruangan[i]);
            }
            }
        } else if (strcmp(assign.elka.rombongan, "A1") == 0 || strcmp(assign.elka.rombongan, "B1") == 0 || strcmp(assign.elka.rombongan, "C1") == 0)
        {
            printf("Ruangan: ");
            scanf("%s", &assign.elka.ruangan[0]);
            while (strcmp(assign.elka.ruangan[0],"LAB1")!= 0 && strcmp(assign.elka.ruangan[0],"LAB2")!= 0 && strcmp(assign.elka.ruangan[0],"LAB3")!= 0)
            {
                printf("Ruangan: ");
                scanf("%s", &assign.elka.ruangan[0]);
            }
        } else if (strcmp(assign.elka.rombongan, "A2") == 0 || strcmp(assign.elka.rombongan, "B2") == 0 || strcmp(assign.elka.rombongan, "C2") == 0){
            printf("Ruangan: ");
            scanf("%s", &assign.elka.ruangan[1]);
            while (strcmp(assign.elka.ruangan[1],"LAB1")!= 0 && strcmp(assign.elka.ruangan[1],"LAB2")!= 0 && strcmp(assign.elka.ruangan[1],"LAB3")!= 0)
            {
                printf("Ruangan: ");
                scanf("%s", &assign.elka.ruangan[1]);
            }
        }
        printf("\n");
    
        // SALIN KE TABEL
        // JIKA ISI DARI TABEL TIDAK NULL, NILAI TABEL TIDAK DIUBAH (TANPA ADA PESAN OUTPUT).
        if (strcmp(assign.elka.hari,"Senin")==0) {
            for(int i = 0; i < 2; i++)
            {
                if (i == 0) { // SOMETHING WRONG HEREE!!
                    if (strcmp(assign.elka.rombongan, "A") == 0) { // ADA SESUATU YG SALAH DISINI
                        strcpy(assign.elka.rombongan, "A1");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B1");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C1");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Romb,assign.elka.rombongan);
                        } else {
                            printf("Jadwal tidak valid. terdapat praktikum %s-%s pada hari dan ruangan yang sama", 
                            tabelOut.Prak[assign.elka.minggu-3].Senin[0].Kode,tabelOut.Prak[assign.elka.minggu-3].Senin[0].Romb);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Romb,assign.elka.rombongan);
                        } else {
                            printf("Jadwal tidak valid. terdapat praktikum %s-%s pada hari dan ruangan yang sama", 
                            tabelOut.Prak[assign.elka.minggu-3].Senin[1].Kode,tabelOut.Prak[assign.elka.minggu-3].Senin[1].Romb);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Romb,assign.elka.rombongan);
                        } else {
                            printf("Jadwal tidak valid. terdapat praktikum %s-%s pada hari dan ruangan yang sama", 
                            tabelOut.Prak[assign.elka.minggu-3].Senin[2].Kode,tabelOut.Prak[assign.elka.minggu-3].Senin[2].Romb);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A2");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B2");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C2");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Romb,assign.elka.rombongan);
                        }
                    }
                }
                strcpy(assign.elka.ruangan[i], " ");
            }
            
        } else if (strcmp(assign.elka.hari,"Selasa")==0) {
            for(int i = 0; i < 2; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A1");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B1");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C1");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Romb,assign.elka.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A2");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B2");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C2");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Selasa[2].Romb,assign.elka.rombongan);
                        }
                    }
                }
                strcpy(assign.elka.ruangan[i], " ");
            }
            
        } else if (strcmp(assign.elka.hari,"Rabu")==0) {
            for(int i = 0; i < 2; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A1");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B1");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C1");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Romb,assign.elka.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A2");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B2");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C2");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Rabu[2].Romb,assign.elka.rombongan);
                        }
                    }
                }
                strcpy(assign.elka.ruangan[i], " ");
            }
            
        } else if (strcmp(assign.elka.hari,"Kamis")==0) {
            for(int i = 0; i < 2; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A1");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B1");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C1");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Romb,assign.elka.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A2");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B2");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C2");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Kamis[2].Romb,assign.elka.rombongan);
                        }
                    }
                }
                strcpy(assign.elka.ruangan[i], " ");
            }
            
        } else if (strcmp(assign.elka.hari,"Jumat")==0) {
            for(int i = 0; i < 2; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A1");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B1");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C1");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Romb,assign.elka.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.elka.rombongan, "A") == 0) {
                        strcpy(assign.elka.rombongan, "A2");
                    } else if (strcmp(assign.elka.rombongan,"B") == 0) {
                        strcpy(assign.elka.rombongan,"B2");
                    } else if (strcmp(assign.elka.rombongan, "C") == 0){
                        strcpy(assign.elka.rombongan,"C2");
                    }
                    if (strcmp(assign.elka.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Romb,"  ") == 0) {
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[0].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[1].Romb,assign.elka.rombongan);
                        }
                    } else if (strcmp(assign.elka.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Romb,"  ") == 0){ 
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Kode,kodeprak);
                            strcpy(tabelOut.Prak[assign.elka.minggu-3].Jumat[2].Romb,assign.elka.rombongan);
                        }
                    }
                }
                strcpy(assign.elka.ruangan[i], " ");
            }
        }
            

    } else if(strcmp(kodeprak,"EL2208")== 0) // PENGOLAHAN DATA PRAKTIKUM PMC. INPUT SEKALIGUS VALIDASI
    {
        printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): "); //INPUT ROMBONGAN
        scanf("%s", &assign.pmc.rombongan);
        while(strcmp(assign.pmc.rombongan,"A")!= 0&&strcmp(assign.pmc.rombongan,"B")!= 0&&strcmp(assign.pmc.rombongan,"C")!= 0&& // VALIDASI ROMBONGAN
              strcmp(assign.pmc.rombongan,"A1")!=0&&strcmp(assign.pmc.rombongan,"A2")!=0&&strcmp(assign.pmc.rombongan,"A3")!= 0&&
              strcmp(assign.pmc.rombongan,"B1")!=0&&strcmp(assign.pmc.rombongan,"B2")!=0&&strcmp(assign.pmc.rombongan,"B3")!= 0)
        {
            printf("Input tidak valid.\n");
            printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
            scanf("%s", &assign.pmc.rombongan);
        }
        printf("Minggu ke: "); // INPUT MINGGU
        scanf("%d", &assign.pmc.minggu);
        while(assign.pmc.minggu < 3 || assign.pmc.minggu > 14)
        { // VALIDASI MINGGU
            printf("Minggu ke: ");
            scanf("%d", &assign.pmc.minggu);
        }
        if (strcmp(assign.pmc.rombongan, "C") == 0){ // VALIDASI BATASAN ROMBONGAN C PMC
            printf("Hari: Rabu\n"); // INPUT ROMBONGAN C PMC
            strcpy(assign.pmc.hari, "Rabu"); // MENETAPKAN HARI ROMBONGAN C MENJADI HARI RABU SECARA LANGSUNG
        }
        else
        {
        printf("Hari: "); // INPUT LAIN SELAIN ROMBONGAN C
        scanf("%s", &assign.pmc.hari);
        while (strcmp(assign.pmc.hari,"Senin")!= 0 && strcmp(assign.pmc.hari,"Selasa")!= 0 && strcmp(assign.pmc.hari,"Rabu")!= 0 && strcmp(assign.pmc.hari,"Kamis")!= 0
              && strcmp(assign.pmc.hari,"Jumat")){ // VALIDASI INPUT HARI
            printf("Hari: ");
            scanf("%s", &assign.pmc.hari);
            }
        }
        if (strcmp(assign.pmc.rombongan, "A")==0 || strcmp(assign.pmc.rombongan, "B")==0){ // VALIDASI INPUT TIDAK TUNGGAL, EX: A, B
                for(int i = 0; i < 3; i++)
                {
                    printf("Ruangan %d: ", i+1);
                    // MEMASUKKAN INPUT RUANGAN BERUPA ARRAY DENGAN: [0] SEBAGAI RUANGAN 1 -> A1, B1, C1
                    // [1] SEBAGAI RUANGAN 2 -> A2, B2
                    // [2] SEBAGAI RUANGAN 3 -> A3, B3
                    scanf("%s", &assign.pmc.ruangan[i]);
                while (strcmp(assign.pmc.ruangan[i],"LAB1")!= 0 && strcmp(assign.pmc.ruangan[i],"LAB2")!= 0 && strcmp(assign.pmc.ruangan[i],"LAB3")!= 0 && strcmp(assign.pmc.ruangan[i],"LSS")!= 0)
                { // VALIDASI SETIAP INPUT PADA ARRAY RUANGAN [i]
                    printf("Ruangan %d: ", i+1);
                    scanf("%s", &assign.pmc.ruangan[i]);
                }
                }
        } else if (strcmp(assign.pmc.rombongan, "A1") == 0 || strcmp(assign.pmc.rombongan, "B1") == 0 )
        {
            printf("Ruangan: ");
            scanf("%s", &assign.pmc.ruangan[0]); // MEMASUKKAN INPUT A1, B1, C1 KEDALAM ARRAY[0]
        } else if (strcmp(assign.pmc.rombongan, "A2") == 0 || strcmp(assign.pmc.rombongan, "B2") == 0 )
        {
            printf("Ruangan: ");
            scanf("%s", &assign.pmc.ruangan[1]); // MEMASUKKAN INPUT A2, B2, C2 KEDALAM ARRAY[1]
        } else if (strcmp(assign.pmc.rombongan, "A3") == 0 || strcmp(assign.pmc.rombongan, "B3") == 0 )
        {
            printf("Ruangan: ");
            scanf("%s", &assign.pmc.ruangan[2]); // MEMASUKKAN INPUT A3, B3, C3 KEDALAM ARRAY[2]
        } else if (strcmp(assign.pmc.rombongan, "C") == 0){
            printf("Ruangan: ");
            scanf("%s", &assign.pmc.ruangan[3]);
        }
        printf("\n");

        // SALIN DATA KE TABEL

        if (strcmp(assign.pmc.hari,"Senin")==0) {
            for(int i = 0; i < 4; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A1");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B1");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.elka.minggu-3].Senin[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A2");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B2");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 2){
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A3");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B3");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 3 ){
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,"  ") == 0) { 
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Senin[3].Romb,assign.pmc.rombongan);
                        }
                    }
                }
                
            }
            
        } else if (strcmp(assign.pmc.hari,"Selasa")==0) {
            for(int i = 0; i < 4; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A1");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B1");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A2");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B2");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 2){
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A3");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B3");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 3 ){
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Selasa[3].Romb,assign.pmc.rombongan);
                        }
                    }
                }
                strcpy(assign.pmc.ruangan[i], " ");
            }
            
        } else if (strcmp(assign.pmc.hari,"Rabu")==0) {
            for(int i = 0; i < 4; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A1");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B1");
                    }
                    
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 1) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A2");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B2");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 2) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A3");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B3");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 3 ){
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Rabu[3].Romb,assign.pmc.rombongan);
                        }
                    }
                }
                strcpy(assign.pmc.ruangan[i], " ");
            }

        } else if (strcmp(assign.pmc.hari,"Kamis")==0) {
            for(int i = 0; i < 4; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A1");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B1");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 1){
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A2");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B2");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,assign.pmc.rombongan);
                        }
                    }  else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 2) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A3");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B3");
                    }
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) { 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,assign.pmc.rombongan);
                        }
                    }  else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 3 ){
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Kamis[3].Romb,assign.pmc.rombongan);
                        }
                    }
                }
                strcpy(assign.pmc.ruangan[i], " ");
            }

        } else if (strcmp(assign.pmc.hari,"Jumat")==0) {
            for(int i = 0; i < 4; i++)
            {
                if (i == 0) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A1");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B1");
                    }

                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,assign.pmc.rombongan);
                        }
                    }  else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 1) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A2");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B2");
                    }

                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,assign.pmc.rombongan);
                        }
                    }  else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 2) {
                    if (strcmp(assign.pmc.rombongan, "A")==0) {
                        strcpy(assign.pmc.rombongan, "A3");
                    } else if (strcmp(assign.pmc.rombongan,"B")==0) {
                        strcpy(assign.pmc.rombongan,"B3");
                    }

                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,assign.pmc.rombongan);
                        }
                    }  else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,assign.pmc.rombongan);
                        }
                    }
                } else if (i == 3 ){
                    if (strcmp(assign.pmc.ruangan[i],"LAB1")==0){ 
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[0].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB2")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[1].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LAB3")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[2].Romb,assign.pmc.rombongan);
                        }
                    } else if (strcmp(assign.pmc.ruangan[i],"LSS")==0) {
                        if (strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,"     ") == 0 && strcmp(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,"  ") == 0) {
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Kode,kodeprak);
                        strcpy(tabelOut.Prak[assign.pmc.minggu-3].Jumat[3].Romb,assign.pmc.rombongan);
                        }
                    }
                }
                strcpy(assign.pmc.ruangan[i], " ");
            }
        }
    

    } else if(strcmp(kodeprak,"EB2200")== 0) // PENGOLAHAN DATA PRAKTIKUM PTB. INPUT SEKALIGUS VALIDASI
    {
        printf("Rombongan (A atau B): ");   // INPUT ROMBONGAN PTB
        scanf("%s", &assign.ptb.rombongan);
        while(strcmp(assign.ptb.rombongan,"A")!= 0&&strcmp(assign.ptb.rombongan,"B")!= 0) // VALIDASI INTPUT ROMBONGAN
        {
            printf("Input tidak valid.\n");
            printf("Rombongan (A atau B): ");
            scanf("%s", &assign.ptb.rombongan);
        }
        printf("Minggu ke: "); // INPUT MINGGU
        scanf("%d", &assign.ptb.minggu);
        while(assign.ptb.minggu < 3 || assign.ptb.minggu > 14) // VALIDASI INPUT MINGGU
        {
            printf("Minggu ke: ");
            scanf("%d", &assign.ptb.minggu);
        }
        printf("Hari: "); // INPUT HARI
        scanf("%s", &assign.ptb.hari);
        while (strcmp(assign.ptb.hari,"Selasa")!= 0 && strcmp(assign.ptb.hari,"Kamis")!= 0) //VALIDASI INPUT HARI
        {
            printf("Hari: ");
            scanf("%s", &assign.ptb.hari);
        }

        printf("Ruangan: "); //INPUT RUANGAN
        scanf("%s", &assign.ptb.ruangan[0]); //DISIMPAN KE DALAM STRUCT ARRAY RUANGAN. UNTUK PRAK PTB, 
                                            // ROMBONGAN HANYA PUNYA 2 JENIS DENGAN MASING MASING 1 TIPE
                                            //SEHINGGA HANYA MENGGUNAKAN ARRAY INDEKS PERTAMA [0]
        while (strcmp(assign.ptb.ruangan[0],"LAB1")!= 0 && strcmp(assign.ptb.ruangan[0],"LAB2")!= 0 && strcmp(assign.ptb.ruangan[0],"LAB3")!= 0 )
        { // VALIDASI INPUT RUANGAN
            printf("Ruangan: ");
            scanf("%s", &assign.ptb.ruangan[0]);
        }
        printf("\n");

        // SALIN INPUT KE TABEL
        if (strcmp(assign.ptb.hari, "Senin") == 0) {
            if (strcmp(assign.ptb.ruangan[0],"LAB1")==0){ 
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[0].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[0].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB2")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[1].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[1].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB3")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[2].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[2].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LSS")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[3].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Senin[3].Romb,assign.ptb.rombongan);
            }
        } else if (strcmp(assign.ptb.hari, "Selasa") == 0) {
            if (strcmp(assign.ptb.ruangan[0],"LAB1")==0){ 
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[0].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[0].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB2")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[1].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[1].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB3")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[2].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[2].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LSS")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[3].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Selasa[3].Romb,assign.ptb.rombongan);
            }
        } else if (strcmp(assign.ptb.hari, "Rabu") == 0) {
            if (strcmp(assign.ptb.ruangan[0],"LAB1")==0){ 
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[0].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[0].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB2")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[1].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[1].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB3")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[2].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[2].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LSS")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[3].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Rabu[3].Romb,assign.ptb.rombongan);
            }
        } else if (strcmp(assign.ptb.hari, "Kamis") == 0) {
            if (strcmp(assign.ptb.ruangan[0],"LAB1")==0){ 
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[0].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[0].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB2")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[1].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[1].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB3")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[2].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[2].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LSS")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[3].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Kamis[3].Romb,assign.ptb.rombongan);
            }
        } else if (strcmp(assign.ptb.hari, "Jumat") == 0) {
            if (strcmp(assign.ptb.ruangan[0],"LAB1")==0){ 
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[0].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[0].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB2")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[1].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[1].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LAB3")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[2].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[2].Romb,assign.ptb.rombongan);
            } else if (strcmp(assign.ptb.ruangan[0],"LSS")==0) {
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[3].Kode,kodeprak);
                strcpy(tabelOut.Prak[assign.ptb.minggu-3].Jumat[3].Romb,assign.ptb.rombongan);
            }
        }
    }
}

        //MENAMPILKAN OUTPUT
    //for(int i = 0; i < 13; i++)
    //{
//        for(int j = 0; j < 5; j++)
//        {
//            printf("|   %d\t|", ((j/5)+3+i));
//            if (j % 5 == 0) {
//                printf("Senin  |");
//                for(int k = 0; k < 4; k++)
//                {
//                  printf("   %s-%s\t|", tabelOut.Prak[i].Senin[k].Kode, tabelOut.Prak[i].Senin[k].Romb);
//              }
 //               printf("\n");
 //           } else if (j%5 == 1) {
//                printf("Selasa |");
//                for(int k = 0; k < 4; k++)
//                {
//                    printf("   %s-%s\t|", tabelOut.Prak[i].Selasa[k].Kode, tabelOut.Prak[i].Selasa[k].Romb);
//                }
//                printf("\n");
//            } else if (j%5 == 2) {
//                printf("Rabu   |");
//                for(int k = 0; k < 4; k++)
//                {
//                    printf("   %s-%s\t|", tabelOut.Prak[i].Rabu[k].Kode, tabelOut.Prak[i].Rabu[k].Romb);
//                }
//                printf("\n");
//            } else if (j%5 == 3) {
//                printf("Kamis  |");
//                for(int k = 0; k < 4; k++)
//                {
//                    printf("   %s-%s\t|", tabelOut.Prak[i].Kamis[k].Kode, tabelOut.Prak[i].Kamis[k].Romb);
//                }
//                printf("\n");
//            } else if (j%5 == 4) {
//                printf("Jumat  |");
//                for(int k = 0; k < 4; k++)
//                {
//                    printf("   %s-%s\t|", tabelOut.Prak[i].Jumat[k].Kode, tabelOut.Prak[i].Jumat[k].Romb);
//                }
//                printf("\n");
//            }
//        }
//        printf("|-------------------------------------------------------------------------------|\n");
//    }
}
