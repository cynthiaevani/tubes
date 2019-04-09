//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2
// File Name: viewSchedule.c
// Dependency : stdio.h, stdlib.h, string.h
//
// Description:
// Menampilkan Data Schedule
// Status:
// 1. Christian Justin - 13217031 : Buat menampilkan Schedule
// 2. Cynthia Evani - 13217045: Menambahkan library LIB-TUBES.h,
//  mengganti nama fungsi
//***********************************************************//

//BELOM LENGKAP:
//Untuk kasus terisi semua, tabel udh dirapiin, tapi buat data kosong belom. Paling tinggal dipakein "if" aja
//Buat kasus kosong, harus ada fungsi yang mengosongkan struct. Di comment program kyknya bisa jadi fungsi mengosongkan struct.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LIB-TUBES.h"

void View_Schedule(){
    struct Dbs tabelOut;
    printf("|-------------------------------------------------------------------------------|\n");
    printf("|Ruang Praktikum|     LAB1\t|     LAB2\t|      LAB3\t|      LSS\t|\n");
    printf("|---------------|---------------|---------------|---------------|---------------|\n");
    printf("|Minggu | Hari  |---------------|---------------|---------------|---------------|\n");
    printf("|-------|-------|---------------|---------------|---------------|---------------|\n");

// EXAMPLE ASSIGN
    // EXAMPLE ASSIGNED
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Prak[i].Senin[j], "EL2205-A1");
            //strcpy(tabelOut.Prak[i].Selasa[j], "EL2205-A1");
            //strcpy(tabelOut.Prak[i].Rabu[j], "EL2205-A1");
            //strcpy(tabelOut.Prak[i].Kamis[j], "EL2205-A1");
            //strcpy(tabelOut.Prak[i].Jumat[j], "EL2205-A1");
        //}
    //}

    // EXAMPLE EMPTY WITH NULL
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Prak[i].Senin[j] = NULL;
            //strcpy(tabelOut.Prak[i].Selasa[j], NULL);
            //strcpy(tabelOut.Prak[i].Rabu[j], NULL);
            //strcpy(tabelOut.Prak[i].Kamis[j], NULL);
            //strcpy(tabelOut.Prak[i].Jumat[j], NULL);
        //}
    //}

    // EXAMPLE EMPTY WITH SPACE
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Prak[i].Senin[j], "       ");
            //strcpy(tabelOut.Prak[i].Selasa[j], "       ");
            //strcpy(tabelOut.Prak[i].Rabu[j], "       ");
            //strcpy(tabelOut.Prak[i].Kamis[j], "       ");
            //strcpy(tabelOut.Prak[i].Jumat[j], "       ");
        //}
    //}

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("|   %d\t|", ((j/5)+3+i));
            if (j % 5 == 0) {
                printf("Senin  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s\t|", tabelOut.Prak[i].Senin[k]);
                }
                printf("\n");
            } else if (j%5 == 1) {
                printf("Selasa |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s\t|", tabelOut.Prak[i].Selasa[k]);
                }
                printf("\n");
            } else if (j%5 == 2) {
                printf("Rabu   |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s\t|", tabelOut.Prak[i].Rabu[k]);
                }
                printf("\n");
            } else if (j%5 == 3) {
                printf("Kamis  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s\t|", tabelOut.Prak[i].Kamis[k]);
                }
                printf("\n");
            } else if (j%5 == 4) {
                printf("Jumat  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s\t|", tabelOut.Prak[i].Jumat[k]);
                }
                printf("\n");
            }
        }
        printf("|-------------------------------------------------------------------------------|\n");
    }    
}
