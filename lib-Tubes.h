//***********************************************************//

//                      [ Source Code ]

//

// Institution: Institut Teknologi Bandung

// Name: A2

// File Name: lib-Tubes.h

// Dependency : stdio.h, stdlib.h, string.h

//

// Description:

// Library untuk database menyimpan schedule praktikum, schedule asisten, dan daftar hari libur

//

// Status:

// 1. Christofel Rio Goenawan - 13217026

// 2. <Nama Praktikan> - <NIM> : Fix the bug where number 2 printed twice

//***********************************************************//



//BELOM LENGKAP: -


#ifndef LIB-TUBES_H
#define LIB-TUBES_H
#include <stdio.h>
#include <stdlib.h>


typedef struct Praktikum_Type{// Tipe data untuk memuat data praktikum dan rombongan pada suatu hari
    char Prak[7];
    char Romb[4];
    
} Praktikum_Type;


typedef struct Dbs_Week_PrakT{ //Tipe data untuk memuat data praktikum pada suatu minggu
    Praktikum_Type Senin[4];
    Praktikum_Type Selasa[4];
    Praktikum_Type Rabu[4];
    Praktikum_Type Kamis[4];
    Praktikum_Type Jumat[4];

} Dbs_Week_PrakT;

typedef struct Dbs_Week_AsistenT{ //Tipe data untuk menyimpan data asisten pada suatu minggu
    char Senin[4][4];
    char Selasa[4][4];
    char Rabu[4][4];
    char Kamis[4][4];
    char Jumat[4][4];

} Dbs_Week_AsistenT;

//------------------------------------------------------

typedef struct Dbs{ //Tipe data untuk menyimpan data asisten dan praktikum pada minggu 2 sampai dengan 15 (full)
    Dbs_Week_PrakT Prak[15];
    Dbs_Week_AsistenT Asist[15];
    
} Dbs_Type;
    
//---------------------------------------------------------    
typedef struct Rule_List_perWeekType{ //Tipe data untuk menyimpan sebuah data hari libur pada sebuah minggu
    int Week;
    char Day[10];

} Rule_List_perWeekType;

//-------------------------------------------------------
typedef struct Rule_List_Type{ //Tipe data untuk menyimpan data hari libur pada praktikum
    int len; //Banyak hari libur pada list
    Rule_List_perWeekType List[65];

}
#endif
