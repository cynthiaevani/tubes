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
//***********************************************************//

//BELOM LENGKAP:
//Untuk kasus terisi semua, tabel udh dirapiin, tapi buat data kosong belom. Paling tinggal dipakein "if" aja
//Buat kasus kosong, harus ada fungsi yang mengosongkan struct. Di comment program kyknya bisa jadi fungsi mengosongkan struct.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct praktikum{
    char rombongan[5];
    int minggu;
    char hari[10];
    char ruangan[5][10];
};

struct inputpraktikum{
    struct praktikum elka;
    struct praktikum pmc;
    struct praktikum ptb;
};

struct Dbs_Week_PrakT{ //Tipe data untuk memuat data praktikum pada suatu minggu
    char Senin[5][10]; //Array of string di hari senin yang isinya {LAB1[0], LAB2[1], LAB3[2], LSS[3]}
    char Selasa[5][10]; //Array of string di hari selasa yang isinya {LAB1, LAB2, LAB3, LSS}
    char Rabu[5][10]; //Array of string di hari rabu yang isinya {LAB1, LAB2, LAB3, LSS}
    char Kamis[5][10]; //Array of string di hari kamis yang isinya {LAB1, LAB2, LAB3, LSS}
    char Jumat[5][10]; //Array of string di hari jumat yang isinya {LAB1, LAB2, LAB3, LSS}

};


struct Dbs_Week_AsistenT{ //Tipe data untuk menyimpan data asisten pada suatu minggu
    char Senin[4];
    char Selasa[4];
    char Rabu[4];
    char Kamis[4];
    char Jumat[4];

};

struct Dbs{ //Tipe data untuk menyimpan data asisten dan praktikum pada minggu 2 sampai dengan 15 (full)
    struct Dbs_Week_PrakT Prak[15];
    struct Dbs_Week_AsistenT Asist[15];
    
};

void main(){
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
            //strcpy(tabelOut.Prak[i].Senin[j], " ");
            //strcpy(tabelOut.Prak[i].Selasa[j], " ");
            //strcpy(tabelOut.Prak[i].Rabu[j], " ");
            //strcpy(tabelOut.Prak[i].Kamis[j], " ");
            //strcpy(tabelOut.Prak[i].Jumat[j], " ");
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
