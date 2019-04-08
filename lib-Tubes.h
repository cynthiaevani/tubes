#ifndef LIB-TUBES_H
#define LIB-TUBES_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Dbs_Day_PrakT{ //Tipe data untuk memuat data praktikum pada suatu hari
    char LAB1[10];
    char LAB2[10];
    char LAB3[10];
    char LSS[10];
    
} Dbs_Day_PrakT;

typedef struct Dbs_Day_AsistenT{ //Tipe data untuk memuat data asisten pada suatu hari
    char LAB1[4];
    char LAB2[4];
    char LAB3[4];
    char LSS[4];
    
} Dbs_Day_AsistenT;

typedef struct Dbs_Week_PrakT{ //Tipe data untuk memuat data praktikum pada suatu minggu
    Dbs_Day_PrakT Senin;
    Dbs_Day_PrakT Selasa;
    Dbs_Day_PrakT Rabu;
    Dbs_Day_PrakT Kamis;
    Dbs_Day_PrakT Jumat;

} Dbs_Week_PrakT;

typedef struct Dbs_Week_AsistenT{ //Tipe data untuk menyimpan data asisten pada suatu minggu
    Dbs_Day_AsistenT Senin;
    Dbs_Day_AsistenT Selasa;
    Dbs_Day_AsistenT Rabu;
    Dbs_Day_AsistenT Kamis;
    Dbs_Day_AsistenTr Jumat;

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
