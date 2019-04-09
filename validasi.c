//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2
// File Name: validasi.c
// Dependency : stdio.h, stdlib.h, string.h
//
// Description:
// Fungsi untuk validasi input
//
// Status:
// 1. Gihon Marten Tumbelaka - 13217038 : Buat validasi kode praktikum, rombongan, dan kode asisten.
// 2. <Nama Praktikan> - <NIM> : Fix the bug where number 2 printed twice
//***********************************************************//

//BELOM LENGKAP:
//Belom ada validasi minggu, hari, sama ruangan
//Itu validasi kode prak.,rombongan, sama kode assisten belum tentu benar 100%. Jadi kalo ada yg salah silahkan debug saja.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Validasi_KodePrak (char kodeprak[10]){
    printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
    scanf("%s", &kodeprak);
    while(strcmp(kodeprak,"EL2205")!= 0 && strcmp(kodeprak,"EL2208")!= 0 && strcmp(kodeprak,"EB2200")!= 0){
        printf("Input tidak valid.\n");
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        scanf("%s", &kodeprak);
    }
}

void Validasi_Rombongan (char kodeprak[10], char rombongan[5]){
    if(strcmp(kodeprak,"EL2205")== 0){
        printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
        scanf("%s", &rombongan);
        while(strcmp(rombongan,"A")!= 0 && strcmp(rombongan,"B")!= 0 && strcmp(rombongan,"C")!= 0 && strcmp(rombongan,"A1")!= 0
              && strcmp(rombongan,"A2")!= 0 &&strcmp(rombongan,"B1")!= 0 && strcmp(rombongan,"B2")!= 0 && strcmp(rombongan,"C1")!=0
              &&strcmp(rombongan,"C2")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
            scanf("%s", &rombongan);}
    } else if(strcmp(kodeprak,"EL2208")== 0){
        printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
        scanf("%s", &rombongan);
        while(strcmp(rombongan,"A")!= 0&&strcmp(rombongan,"B")!= 0&&strcmp(rombongan,"C")!= 0&&
              strcmp(rombongan,"A1")!=0&&strcmp(rombongan,"A2")!=0&&strcmp(rombongan,"A3")!= 0&&
              strcmp(rombongan,"B1")!=0&&strcmp(rombongan,"B2")!=0&&strcmp(rombongan,"B3")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
            scanf("%s", &rombongan);}
    } else if(strcmp(kodeprak,"EB2200")== 0){
        printf("Rombongan (A atau B): ");
        scanf("%s", &rombongan);
        while(strcmp(rombongan,"A")!= 0&&strcmp(rombongan,"B")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A atau B): ");
            scanf("%s", &rombongan);}
    }
}

void Validasi_Asisten (char *asst){
    printf("Pilih Asisten (A-N): ");
    scanf("%s", &asst);
    while(strcmp(asst,"A")!= 0&&strcmp(asst,"B")!= 0&&strcmp(asst,"C")!= 0&&strcmp(asst,"D")!= 0
          &&strcmp(asst,"E")!= 0&&strcmp(asst,"F")!= 0&&strcmp(asst,"G")!= 0&&strcmp(asst,"H")!= 0
          &&strcmp(asst,"I")!= 0&&strcmp(asst,"J")!= 0&&strcmp(asst,"K")!= 0&&strcmp(asst,"L")!= 0
          &&strcmp(asst,"M")!= 0&&strcmp(asst,"N")!= 0){
        printf("Input tidak valid.\n");
        printf("Pilih Asisten (A-N): ");
        scanf("%s", &asst);
    }
}
