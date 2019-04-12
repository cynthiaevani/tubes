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
            //strcpy(tabelOut.Prak[i].Senin[j].Kode, "EL2205");
            //strcpy(tabelOut.Prak[i].Selasa[j].Kode, "EL2205");
            //strcpy(tabelOut.Prak[i].Rabu[j].Kode, "EL2205");
            //strcpy(tabelOut.Prak[i].Kamis[j].Kode, "EL2205");
            //strcpy(tabelOut.Prak[i].Jumat[j].Kode, "EL2205");
            //strcpy(tabelOut.Prak[i].Senin[j].Romb, "A1");
            //strcpy(tabelOut.Prak[i].Selasa[j].Romb, "A1");
            //strcpy(tabelOut.Prak[i].Rabu[j].Romb, "A1");
            //strcpy(tabelOut.Prak[i].Kamis[j].Romb, "A1");
            //strcpy(tabelOut.Prak[i].Jumat[j].Romb, "A1");            
        //}
    //}

    // EXAMPLE EMPTY WITH SPACE
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Prak[i].Senin[j].Kode, "     ");
            //strcpy(tabelOut.Prak[i].Selasa[j].Kode, "     ");
            //strcpy(tabelOut.Prak[i].Rabu[j].Kode, "     ");
            //strcpy(tabelOut.Prak[i].Kamis[j].Kode, "     ");
            //strcpy(tabelOut.Prak[i].Jumat[j].Kode, "     ");
            //strcpy(tabelOut.Prak[i].Senin[j].Romb, "  ");
            //strcpy(tabelOut.Prak[i].Selasa[j].Romb, "  ");
            //strcpy(tabelOut.Prak[i].Rabu[j].Romb, "  ");
            //strcpy(tabelOut.Prak[i].Kamis[j].Romb, "  ");
            //strcpy(tabelOut.Prak[i].Jumat[j].Romb, "  ");            
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
                    printf("   %s-%s\t|", tabelOut.Prak[i].Senin[k].Kode, tabelOut.Prak[i].Senin[k].Romb);
                }
                printf("\n");
            } else if (j%5 == 1) {
                printf("Selasa |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s-%s\t|", tabelOut.Prak[i].Selasa[k].Kode, tabelOut.Prak[i].Selasa[k].Romb);
                }
                printf("\n");
            } else if (j%5 == 2) {
                printf("Rabu   |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s-%s\t|", tabelOut.Prak[i].Rabu[k].Kode, tabelOut.Prak[i].Rabu[k].Romb);
                }
                printf("\n");
            } else if (j%5 == 3) {
                printf("Kamis  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s-%s\t|", tabelOut.Prak[i].Kamis[k].Kode, tabelOut.Prak[i].Kamis[k].Romb);
                }
                printf("\n");
            } else if (j%5 == 4) {
                printf("Jumat  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("   %s-%s\t|", tabelOut.Prak[i].Jumat[k].Kode, tabelOut.Prak[i].Jumat[k].Romb);
                }
                printf("\n");
            }
        }
        printf("|-------------------------------------------------------------------------------|\n");
    }
}
