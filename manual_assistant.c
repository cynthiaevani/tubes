//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2/4
// File Name: manual_assistant.c
// Dependency : stdio.h, stdlib.h, string.h
//
// Description:
// Membuat assignment asisten secara manual berdasarkan input dari user
//
// Status:
// 1. Christian Justin - 13217031 : Buat validasi
// 2. Gihon Marten Tumbelaka - 13217038 : Buat validasi, fungsi manual_assistant nya
//***********************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Validasi_Asisten (char asst);

void manual_assistant(){
    typedef struct ruangan_s{
        char *i, *j, *k;
    }ruangan_t;

    char *asst, *minggu, *hari;
    ruangan_t *ruangan;

    asst = (char*)malloc(1*sizeof(char));
    minggu = (char*)malloc(2*sizeof(char));
    hari = (char*)malloc(8*sizeof(char));
    ruangan = (ruangan_t*)malloc(4*sizeof(ruangan_t));

    printf("[Mode Assign Asisten]\n");
    printf("Isi `q` atau `Q` untuk kembali ke menu\n");

    printf("Pilih Asisten (A-N): ");
    scanf("%s", asst);
    if(strcmp(asst,"q")==0 || strcmp(asst,"Q")==0){
        exit(0);
    } else{
        Validasi_Asisten(asst);
    }

    printf("Minggu: ");
    scanf("%s", minggu);
    Validasi_Minggu(minggu);

    printf("Hari: ");
    scanf("%s", hari);
    Validasi_Hari(hari);

    printf("Ruang: ");
    scanf("%s", ruangan);
    Validasi_Ruangan(ruangan);
}

void Validasi_Asisten (char asst){
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

