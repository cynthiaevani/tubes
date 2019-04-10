//***********************************************************//



//                      [ Source Code ]



//



// Institution: Institut Teknologi Bandung



// Name: A2



// File Name: Rule_Checker.c



// Dependency : stdio.h, stdlib.h, string.h, lib-Tubes.h



//



// Description:



// Library untuk database menyimpan schedule praktikum, schedule asisten, dan daftar hari libur



//



// Status:



// 1. Christofel Rio Goenawan - 13217026



// 2. <Nama Praktikan> - <NIM> : Fix the bug where number 2 printed twice



//***********************************************************//







//BELOM LENGKAP: -

//-------------------------------------------------

#include "lib-Tubes.h"
#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<stdbool.h>

bool _initRuleList_(Rule_List_Type *RuleList); //Fungsi untuk menginisialisasi list hari libur

int checkSchedule(Dbs_Type Dbs, Rule_List_Type *Rule_List, int N); //Fungsi untuk mengecek apakah ada praktikum saat libur

int strToInt(char Str[]); //File yang mengubah string menjadi int, daro 0- 99

bool isValid(char Week[], char Day[]); //Fungsi untuk menentukan apakah masukan valid atau tidak

int dayToNumber(char Day[]);

bool ruleChecker(Dbs_Type Dbs, Rule_List_Type *Rule_List){
    //Inisiasi
    long Baris=0; //Untuk menentukan baris ke berapa
    long Many_Input=0; //Menetukan banyak input yang diterima(yang valid)
    char i[100], *Checker, *Day; //Checker adalah pengecek apakah sudah sampai EOF
    bool isFalse= false; //Fungsi pengecek apakah ditemukan baris yang salah
    FILE *pFile;

    //Terima nama file eksternal
    printf("Masukkan File DRC (dalam format .txt) :");
    scanf("%s", i);

    pFile= fopen(i, "r");

    if(!pFile){    //Jika file tidak dapat dibuka

    printf("\nFile tidak dapat ditemukan\nApakah akan masukkan lagi?(Y T)"); //Cek apakah ingin mengulangi atau tidak
    char c;
    scanf("%c", c );
    if ((c=='Y')||(c=='y')){return(false);} else{return(true);}


    }else{ //Jika dapat dibuka
        Checker= fgets(&i, 100, pFile);
        while((Checker!= NULL)&&(!isFalse)){ //Berarti ditemukan barispada file
            Baris++;
            strtok(i, " ");
            Day= strtok(NULL, "\n");
            int Week=0;
            Week= strToInt(i);
            if(!(isValidPrak(Week, Day))){
               Many_Input++;
               Rule_List->List[Many_Input].Week= Week;
               strcpy(Day, Rule_List->List[Many_Input].Day);

               Checker= fgets(&i, 100, pFile);

            }

            else{
                printf("Format salah pada baris ke- %d\n", Baris);
                isFalse= false;
                //Ditawarkan opsi memasukkan file lain
                printf("Masukkan file lagi ( Y / T )?");
                scanf("%s", i);
                if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}

            }}


    if(Baris==0){ //Jika tidak ada input
        printf("Tidak ada isi file. \nMasukkan file lagi ( Y / T )?");
        scanf("%s", i);
        if((!strcmp(i,"Y"))||!(strcmp(i,"y"))){ return(false);} else {return(true);}

    } else if (!isFalse){  //Jika ada baris yang salah
        return(true);
        //Cek apakah ada jadwal salah
        checkSchedule(Dbs, Rule_List, Many_Input);

    }





    fclose(pFile);
    }


}


bool _initRuleList_(Rule_List_Type *RuleList){
    RuleList->len= 0;


}
int checkSchedule(Dbs_Type Dbs, Rule_List_Type *Rule_List, int N){
    int Result= 0;

    for (int i=1; i<= Rule_List->len; i++){
        int weekp;
        char dayp[10];

        weekp= Rule_List->List[i].Week;
        strcpy(dayp, Rule_List->List[i].Day);

        int x= strToInt(dayp);

        /*switch (x){

        case (1):

      //  if ((strcmp(" ",(Dbs.Prak[weekp].Senin[1])))
        //    ||(strcmp(" ", (Dbs.Prak[weekp].Senin[2])))
        //    ||(strcmp(" ", (Dbs.Prak[weekp].Senin[3])))
         //   ||(strcmp(" ", (Dbs.Prak[weekp].Senin[4])))){
         //   Result++;
         //   if (Result==1){printf("PERINGATAN: Terdapat praktikum pada hari libur!\n"); }
          //  printf("Praktikum pada minggu ke- %d hari %s tidak dapat dilakukan.\n", weekp, dayp);

        //}
        //break;

        case (2):

        if ((strcmp(" ", (Dbs.Prak[weekp].(Selasa)[1])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Selasa)[2])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Selasa)[3])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Selasa)[4])))){
            Result++;
            if (Result==1){printf("PERINGATAN: Terdapat praktikum pada hari libur!\n"); }
            printf("Praktikum pada minggu ke- %d hari %s tidak dapat dilakukan.\n", weekp, dayp);

        }
        break;

        case (3):

        if ((strcmp(" ", (Dbs.Prak[weekp].(Rabu)[1])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Rabu)[2])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Rabu)[3])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Rabu)[4])))){
            Result++;
            if (Result==1){printf("PERINGATAN: Terdapat praktikum pada hari libur!\n"); }
            printf("Praktikum pada minggu ke- %d hari %s tidak dapat dilakukan.\n", weekp, dayp);

        }
        break;

        case (4):

        if ((strcmp(" ", (Dbs.Prak[weekp].(Kamis)[1])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Kamis)[2])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Kamis)[3])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Kamis)[4])))){
            Result++;
            if (Result==1){printf("PERINGATAN: Terdapat praktikum pada hari libur!\n"); }
            printf("Praktikum pada minggu ke- %d hari %s tidak dapat dilakukan.\n", weekp, dayp);

        }
        break;

        case (5):

        if ((strcmp(" ", (Dbs.Prak[weekp].(Jumat)[1])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Jumat)[2])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Jumat)[3])))
            ||(strcmp(" ", (Dbs.Prak[weekp].(Jumat)[4]))))){
            Result++;
            if (Result==1){printf("PERINGATAN: Terdapat praktikum pada hari libur!\n"); }
            printf("Praktikum pada minggu ke- %d hari %s tidak dapat dilakukan.\n", weekp, dayp);

        }
        break;
        }
    } */

    if (Result==0){printf("Tidak ada praktikum pada semua hari libur.");}

    return(Result);

}

int strToInt(char Str[]){
    /*if(strlen(Str)>2){return(-1);}
    else if (strlen(Str)=2){return((int) Str[0] * 10+ (int) Str[1]);}
    else {return((int) Str[0]);}

        */

        return(1);
}

bool isValid(char Week[], char Day[]){
    int i= strToInt(Week);
    if(((i>=3)&&(i<=14))&&((!strcmp(Day, "Senin"))|| (!strcmp(Day, "Selasa")) ||
                            (!strcmp(Day, "Rabu"))||(!strcmp(Day, "Kamis"))||(!strcmp(Day, "Jumat"))))
       {
           return(true);
       } else{
            return(false);
        }
}
int dayToNumber(char Day[]){
    if(!strcmp(Day, "Senin")){ return(1);}
    else if(!strcmp(Day, "Selasa")){ return(2);}
    else if(!strcmp(Day, "Rabu")){ return(3);}
    else if(!strcmp(Day, "Kamis")){ return(4);}
    else if(!strcmp(Day, "Jumat")){ return(5);}

}}
