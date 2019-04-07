#ifndef LIB-TUBES_H
#define LIB-TUBES_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Dbs_Week_PrakT{ //Tipe data untuk memuat data praktikum pada suatu minggu
    char Senin[10];
    char Selasa[10];
    char Rabu[10];
    char Kamis[10];
    char Jumat[10];

} Dbs_Week_PrakT;

typedef struct Dbs_Week_AsistenT{ //Tipe data untuk menyimpan data asisten pada suatu minggu
    char Senin[4];
    char Selasa[4];
    char Rabu[4];
    char Kamis[4];
    char Jumat[4];

} Dbs_Week_AsistenT;

typedef struct Rule_List_perWeekType{ //Tipe data untuk menyimpan sebuah data hari libur pada sebuah minggu
    int Week;
    char Day[10];

} Rule_List_perWeekType;

typedef struct Rule_List_Type{ //Tipe data untuk menyimpan data hari libur pada praktikum
    int lenth;
    Rule_List_perWeekType List[65];

}
#endif
