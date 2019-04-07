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

struct rombpraktikum{
    char elka[10];
    char pmc[10];
    char ptb[10];
};

int main(){
    char kodeprak[10], asst[10];
    struct rombpraktikum rombongan;

    printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
    scanf("%s", &kodeprak);
    while(strcmp(kodeprak,"EL2205")!= 0 && strcmp(kodeprak,"EL2208")!= 0 && strcmp(kodeprak,"EB2200")!= 0){
        printf("Input tidak valid.\n");
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        scanf("%s", &kodeprak);
    }

    if(strcmp(kodeprak,"EL2205")== 0){
        printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
        scanf("%s", &rombongan.elka);
        while(strcmp(rombongan.elka,"A")!= 0 && strcmp(rombongan.elka,"B")!= 0 && strcmp(rombongan.elka,"C")!= 0 && strcmp(rombongan.elka,"A1")!= 0
              && strcmp(rombongan.elka,"A2")!= 0 &&strcmp(rombongan.elka,"B1")!= 0 && strcmp(rombongan.elka,"B2")!= 0 && strcmp(rombongan.elka,"C1")!=0
              &&strcmp(rombongan.elka,"C2")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
            scanf("%s", &rombongan.elka);}
    } else if(strcmp(kodeprak,"EL2208")== 0){
        printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
        scanf("%s", &rombongan.pmc);
        while(strcmp(rombongan.pmc,"A")!= 0&&strcmp(rombongan.pmc,"B")!= 0&&strcmp(rombongan.pmc,"C")!= 0&&
              strcmp(rombongan.pmc,"A1")!=0&&strcmp(rombongan.pmc,"A2")!=0&&strcmp(rombongan.pmc,"A3")!= 0&&
              strcmp(rombongan.pmc,"B1")!=0&&strcmp(rombongan.pmc,"B2")!=0&&strcmp(rombongan.pmc,"B3")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
            scanf("%s", &rombongan.pmc);}
    } else if(strcmp(kodeprak,"EB2200")== 0){
        printf("Rombongan (A atau B): ");
        scanf("%s", &rombongan.ptb);
        while(strcmp(rombongan.ptb,"A")!= 0&&strcmp(rombongan.ptb,"B")!= 0){
            printf("Input tidak valid.\n");
            printf("Rombongan (A atau B): ");
            scanf("%s", &rombongan.ptb);}
    }
    
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
    return 0;
}
