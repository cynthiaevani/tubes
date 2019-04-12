//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2
// File Name: viewSchedule.c
// Dependency : stdio.h, stdlib.h, string.h, LIB-TUBES.h
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

#include "view.h"

void View_Assistant(){
    printf("|-----------------------------------------------|\n");
    printf("|Ruang Praktikum|LAB1\t|LAB2\t|LAB3\t|LSS\t|\n");
    printf("|---------------|-------|-------|-------|-------|\n");
    printf("|Minggu | Hari  |-------|-------|-------|-------|\n");
    printf("|-------|-------|-------|-------|-------|-------|\n");

// EXAMPLE ASSIGN
    // EXAMPLE ASSIGNED
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Asist[i].Senin[j], "G,I");
            //strcpy(tabelOut.Asist[i].Selasa[j], "G,I");
            //strcpy(tabelOut.Asist[i].Rabu[j], "G,I");
            //strcpy(tabelOut.Asist[i].Kamis[j], "G,I");
            //strcpy(tabelOut.Asist[i].Jumat[j], "G,I");
        //}
    //}

    // EXAMPLE EMPTY WITH NULL
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Asist[i].Senin[j], NULL);
            //strcpy(tabelOut.Asist[i].Selasa[j], NULL);
            //strcpy(tabelOut.Asist[i].Rabu[j], NULL);
            //strcpy(tabelOut.Asist[i].Kamis[j], NULL);
            //strcpy(tabelOut.Asist[i].Jumat[j], NULL);
        //}
    //}

    // EXAMPLE EMPTY WITH SPACE
    //for(int i = 0; i < 13; i++)
    //{
        //for(int j = 0; j < 4; j++)
        //{
            //strcpy(tabelOut.Asist[i].Senin[j], " ");
            //strcpy(tabelOut.Asist[i].Selasa[j], " ");
            //strcpy(tabelOut.Asist[i].Rabu[j], " ");
            //strcpy(tabelOut.Asist[i].Kamis[j], " ");
            //strcpy(tabelOut.Asist[i].Jumat[j], " ");
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
                    printf("  %s\t|", tabelOut.Asist[i].Senin[k]);
                }
                printf("\n");
            } else if (j%5 == 1) {
                printf("Selasa |");
                for(int k = 0; k < 4; k++)
                {
                    printf("  %s\t|", tabelOut.Asist[i].Selasa[k]);
                }
                printf("\n");
            } else if (j%5 == 2) {
                printf("Rabu   |");
                for(int k = 0; k < 4; k++)
                {
                    printf("  %s\t|", tabelOut.Asist[i].Rabu[k]);
                }
                printf("\n");
            } else if (j%5 == 3) {
                printf("Kamis  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("  %s\t|", tabelOut.Asist[i].Kamis[k]);
                }
                printf("\n");
            } else if (j%5 == 4) {
                printf("Jumat  |");
                for(int k = 0; k < 4; k++)
                {
                    printf("  %s\t|", tabelOut.Asist[i].Jumat[k]);
                }
                printf("\n");
            }
        }
        printf("|-----------------------------------------------|\n");
    }    
}
