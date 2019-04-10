//***********************************************************//



//                      [ Source Code ]



//



// Institution: Institut Teknologi Bandung



// Name: A2



// File Name: Load_File.c



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

bool isValidPrak(int Week, char Day[], char LAB1[], char LAB2[], char LAB3[], char LSS[], int Baris); //Fungsi yang memvalidasi masukan untuk setiap baris

bool isValidAsisten(int Week, char Day[], char LAB1[], char LAB2[], char LAB3[], char LSS[], int Baris); //Fungsi yang memvalidasi masukan untuk setiap baris

void inputToDbs(Dbs_Type *Dbs, int Week, const char Day[], char LAB1, char LAB2, char LAB3, char LSS); //Fungsi untuk memasukkan input ke database praktikum

void inputToDbsAsisten(Dbs_Type *Dbs, int Week, char Day[], char LAB1, char LAB2, char LAB3, char LSS); //Fungsi untuk memasukkan input ke database asistem

int dayToNumber(char Day[]); //Fungsi untuk mengembalikan angka dari sebuah hari

int strToInt(char Str[]);

char loadFile(Dbs_Type *Dbs){
    //Inisiasi
    long Baris=0; //Untuk menentukan baris ke berapa
    int Week; //Untuk menyimpan minggu yang diterima
    bool isFalse= false; //Fungsi pengecek apakah ditemukan baris yang salah
    char i[100], *Checker, Day[10], LAB1[10], LAB2[10], LAB3[10], LSS[10], File_Name[100];
    FILE *pFile;


    printf("\nTentukan file yang akan di load untuk praktikum(.csv) :");
    scanf("%s", File_Name);

    pFile= fopen(File_Name, "r+");

    if(pFile){ //Jika file tidak dapat dibuka
        printf("\nFile tidak dapat ditemukan\nApakah akan masukkan lagi?(Y T)"); //Cek apakah ingin mengulangi atau tidak
        char c;
        scanf("%c", c );
        if ((c=='Y')||(c=='y')){return(false);} else{return(true);}
    }
    else{ //Jika dapat dibuka
    Checker= fgets(&i, 100, pFile);
    while((Checker!= NULL)&&(!isFalse)){ //Berarti ditemukan barispada file
        Baris++;
        if(strcmp(i, "Ruang Praktikum;Lab1:LAB2;LAB3;LSS\n")){ //Jika header salah
            printf("Format salah pada baris ke- %d\n", Baris);
            isFalse= false;
            //Ditawarkan opsi memasukkan file lain
            printf("Masukkan file lagi ( Y / T )?");
            scanf("%s", i);
            if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}


        }
        else{//Jika header benar
              Checker= fgets(&i, 100, pFile);
              Baris++;
              if ((Checker== NULL)||(strcmp(i, "Minggu;Hari\n"))){ //Jika header salah
                printf("Format salah pada baris ke- %d\n", Baris);
                isFalse= false;
                //Ditawarkan opsi memasukkan file lain
                printf("Masukkan file lagi ( Y / T )?");
                scanf("%s", i);
                if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}
              }
                else{//Jika header kedua benar
                    Checker= fgets(&i, 100, pFile);
                    while ((Checker!= NULL)||(isFalse)){
                        Baris++;
                        Week= strToInt(strtok(i, ";"));
                        strcpy(Day, strtok(NULL, ";"));
                        strcpy(LAB1, strtok(NULL, ";"));
                        strcpy(LAB2, strtok(NULL, ";"));
                        strcpy(LAB3, strtok(NULL, ";"));
                        strcpy(LSS, strtok(NULL, "\n"));
                        if(!(isValidPrak(Week, Day, LAB1, LAB2,
                                   LAB3, LSS, Baris))){//Input salah
                            printf("Format salah pada baris ke- %d\n", Baris);
                            isFalse= false;
                            //Ditawarkan opsi memasukkan file lain
                            printf("Masukkan file lagi ( Y / T )?");
                            scanf("%s", i);
                            if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}


                        } else {//Jika input benar
                        //Masukkan ke file Database
                            inputToDbs(Dbs, Week, Day, LAB1, LAB2, LAB3, LSS);

                            Checker= fgets(&i, 100, pFile);
                        }
                }

              }}}

               if(Baris==0){ //Jika tidak ada input
                printf("Tidak ada isi file. \nMasukkan file lagi ( Y / T )?");
                scanf("%s", i);
                if((!strcmp(i,"Y"))||!(strcmp(i,"y"))){ return(false);} else {return(true);}}


                fclose(pFile);



//------------------------------------------------------------------------------
            // Load file asisten
            if (!isFalse){ //Jika tidak ada kesalahan, load file asisten
                printf("\nTentukan file yang akan di load untuk praktikum(.csv) :");
                scanf("%s", File_Name);

                pFile= fopen(File_Name, "r+");

                if(pFile){ //Jika file tidak dapat dibuka
                printf("\nFile tidak dapat ditemukan\nApakah akan masukkan lagi?(Y T)"); //Cek apakah ingin mengulangi atau tidak
                char c;
                scanf("%c", c );
                if ((c=='Y')||(c=='y')){return(false);} else{return(true);}
                }
                else{ //Jika dapat dibuka
                    Checker= fgets(&i, 100, pFile);
                    while((Checker!= NULL)&&(!isFalse)){ //Berarti ditemukan barispada file
                        Baris++;
                        if(strcmp(i, "Ruang Praktikum;Lab1:LAB2;LAB3;LSS\n")){ //Jika header salah
                        printf("Format salah pada baris ke- %d\n", Baris);
                        isFalse= false;
                        //Ditawarkan opsi memasukkan file lain
                        printf("Masukkan file lagi ( Y / T )?");
                        scanf("%s", i);
                        if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}


                }
                else{//Jika header benar
                    Checker= fgets(&i, 100, pFile);
                    Baris++;
                    if ((Checker== NULL)||(strcmp(i, "Minggu;Hari\n"))){ //Jika header salah
                    printf("Format salah pada baris ke- %d\n", Baris);
                    isFalse= false;
                    //Ditawarkan opsi memasukkan file lain
                    printf("Masukkan file lagi ( Y / T )?");
                    scanf("%s", i);
                    if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}
                    }
                    else{//Jika header kedua benar
                        Checker= fgets(&i, 100, pFile);
                        while ((Checker!= NULL)||(isFalse)){
                            Baris++;
                            Week= strToInt(strtok(i, ";"));
                            strcpy(&Day, strtok(NULL, ";"));
                            strcpy(&LAB1, strtok(NULL, ";"));
                            strcpy(&LAB2, strtok(NULL, ";"));
                            strcpy(&LAB3, strtok(NULL, ";"));
                            strcpy(&LSS, strtok(NULL, "\n"));
                            if(!(isValidAsisten(Week, Day, LAB1, LAB2,
                                   LAB3, LSS, Baris))){//Input salah
                                printf("Format salah pada baris ke- %d\n", Baris);
                                isFalse= false;
                                //Ditawarkan opsi memasukkan file lain
                                printf("Masukkan file lagi ( Y / T )?");
                                scanf("%s", i);
                                if(!strcmp("Y",i)||!strcmp("y",i)){ return(false);} else {return(true);}


                            } else {//Jika input benar
                            //Masukkan ke file Database
                                inputToDbsAsisten(Dbs, Week, Day, LAB1, LAB2, LAB3, LSS);

                                Checker= fgets(&i, 100, pFile);
                            }
                    }

                    }}}

                    if(Baris==0){ //Jika tidak ada input
                    printf("Tidak ada isi file. \nMasukkan file lagi ( Y / T )?");
                    scanf("%s", i);
                    if((!strcmp(i,"Y"))||!(strcmp(i,"y"))){ return(false);} else {return(true);}}


                    fclose(pFile);
            }
    }

     fclose(pFile);


    }

}

bool isValidPrak(int Week, char Day[], char LAB1[], char LAB2[], char LAB3[], char LSS[], int Baris){
    char Kode1[10], Kode2[10], Kode3[10], Kode4[10];
    char Romb1[10], Romb2[10], Romb3[10], Romb4[10];

    strcpy(Kode1, strtok(LAB1, "-"));
    strcpy(Romb1, strtok(NULL, ";"));

    strcpy(Kode2, strtok(LAB2, "-"));
    strcpy(Romb2, strtok(NULL, ";"));

    strcpy(Kode3, strtok(LAB3, "-"));
    strcpy(Romb3, strtok(NULL, ";"));

    strcpy(Kode4, strtok(LSS, "-"));
    strcpy(Romb4, strtok(NULL, ";"));


    if (((Week >= 3)&&(Week<= 14))&&
        ((!strcmp(Day, "Senin"))||(!strcmp(Day, "Selasa"))||(!strcmp(Day, "Rabu"))||(!strcmp(Day, "Kamis"))||(!strcmp(Day, "Jumat")))&&
        (((!strcmp(Kode1, "EL2205"))||(!strcmp(Kode1, "EB2200"))||(!strcmp(Kode1, "EL2208")))&& ((!strcmp(Kode2, "EL2205"))||(!strcmp(Kode2, "EB2200"))||(!strcmp(Kode2, "EL2208")))||
         ((!strcmp(Kode3, "EL2205"))||(!strcmp(Kode3, "EB2200"))||(!strcmp(Kode3, "EL2208")))||  ((!strcmp(Kode4, "EL2205"))||(!strcmp(Kode4, "EB2200"))||(!strcmp(Kode4, "EL2208"))))){
            return(true);

         } else {return(false);}



}

bool isValidAsisten(int Week, char Day[], char LAB1[], char LAB2[], char LAB3[], char LSS[], int Baris){

    return(true);
}

void inputToDbs(Dbs_Type *Dbs, int Week, const char Day[], char LAB1, char LAB2, char LAB3, char LSS){
    char Kode1[10], Kode2[10], Kode3[10], Kode4[10];
    char Romb1[10], Romb2[10], Romb3[10], Romb4[10];

    strcpy(Kode1, strtok(LAB1, "-"));
    strcpy(Romb1, strtok(NULL, ";"));

    strcpy(Kode2, strtok(LAB2, "-"));
    strcpy(Romb2, strtok(NULL, ";"));

    strcpy(Kode3, strtok(LAB3, "-"));
    strcpy(Romb3, strtok(NULL, ";"));

    strcpy(Kode4, strtok(LSS, "-"));
    strcpy(Romb4, strtok(NULL, ";"));

    //Input ke file
    int x= dayToNumber(Day);

    switch (x){
        case 1:

    strcpy(Dbs->Prak[Week].Senin[1].Kode, Kode1);
    strcpy(Dbs->Prak[Week].Senin[2].Kode, Kode2);
    strcpy(Dbs->Prak[Week].Senin[3].Kode, Kode3);
    strcpy(Dbs->Prak[Week].Senin[4].Kode, Kode4);
    strcpy(Dbs->Prak[Week].Senin[1].Romb, Romb1);
    strcpy(Dbs->Prak[Week].Senin[1].Romb, Romb2);
    strcpy(Dbs->Prak[Week].Senin[1].Romb, Romb3);
    strcpy(Dbs->Prak[Week].Senin[1].Romb, Romb4);

    break;

    case 2:

    strcpy(Dbs->Prak[Week].Selasa[1].Kode, Kode1);
    strcpy(Dbs->Prak[Week].Selasa[2].Kode, Kode2);
    strcpy(Dbs->Prak[Week].Selasa[3].Kode, Kode3);
    strcpy(Dbs->Prak[Week].Selasa[4].Kode, Kode4);
    strcpy(Dbs->Prak[Week].Selasa[1].Romb, Romb1);
    strcpy(Dbs->Prak[Week].Selasa[1].Romb, Romb2);
    strcpy(Dbs->Prak[Week].Selasa[1].Romb, Romb3);
    strcpy(Dbs->Prak[Week].Selasa[1].Romb, Romb4);

    break;

    case 3:

    strcpy(Dbs->Prak[Week].Rabu[1].Kode, Kode1);
    strcpy(Dbs->Prak[Week].Rabu[2].Kode, Kode2);
    strcpy(Dbs->Prak[Week].Rabu[3].Kode, Kode3);
    strcpy(Dbs->Prak[Week].Rabu[4].Kode, Kode4);
    strcpy(Dbs->Prak[Week].Rabu[1].Romb, Romb1);
    strcpy(Dbs->Prak[Week].Rabu[1].Romb, Romb2);
    strcpy(Dbs->Prak[Week].Rabu[1].Romb, Romb3);
    strcpy(Dbs->Prak[Week].Rabu[1].Romb, Romb4);

    break;

    case 4:

    strcpy(Dbs->Prak[Week].Kamis[1].Kode, Kode1);
    strcpy(Dbs->Prak[Week].Kamis[2].Kode, Kode2);
    strcpy(Dbs->Prak[Week].Kamis[3].Kode, Kode3);
    strcpy(Dbs->Prak[Week].Kamis[4].Kode, Kode4);
    strcpy(Dbs->Prak[Week].Kamis[1].Romb, Romb1);
    strcpy(Dbs->Prak[Week].Kamis[1].Romb, Romb2);
    strcpy(Dbs->Prak[Week].Kamis[1].Romb, Romb3);
    strcpy(Dbs->Prak[Week].Kamis[1].Romb, Romb4);

    break;

    case 5:

    strcpy(Dbs->Prak[Week].Jumat[1].Kode, Kode1);
    strcpy(Dbs->Prak[Week].Jumat[2].Kode, Kode2);
    strcpy(Dbs->Prak[Week].Jumat[3].Kode, Kode3);
    strcpy(Dbs->Prak[Week].Jumat[4].Kode, Kode4);
    strcpy(Dbs->Prak[Week].Jumat[1].Romb, Romb1);
    strcpy(Dbs->Prak[Week].Jumat[1].Romb, Romb2);
    strcpy(Dbs->Prak[Week].Jumat[1].Romb, Romb3);
    strcpy(Dbs->Prak[Week].Jumat[1].Romb, Romb4);

    break;


    }

}

void inputToDbsAsisten(Dbs_Type *Dbs, int Week,  char Day[], char LAB1, char LAB2, char LAB3, char LSS){

    //Input ke file
    int x= dayToNumber(Day);

    switch (x){
        case 1:

    strcpy(Dbs->Asist[Week].Senin[1], LAB1);
    strcpy(Dbs->Asist[Week].Senin[2], LAB2);
    strcpy(Dbs->Asist[Week].Senin[3], LAB3);
    strcpy(Dbs->Asist[Week].Senin[4], LSS);

    break;

    case 2:

    strcpy(Dbs->Asist[Week].Selasa[1], LAB1);
    strcpy(Dbs->Asist[Week].Selasa[2], LAB2);
    strcpy(Dbs->Asist[Week].Selasa[3], LAB3);
    strcpy(Dbs->Asist[Week].Selasa[4], LSS);

    break;

    case 3:

    strcpy(Dbs->Asist[Week].Rabu[1], LAB1);
    strcpy(Dbs->Asist[Week].Rabu[2], LAB2);
    strcpy(Dbs->Asist[Week].Rabu[3], LAB3);
    strcpy(Dbs->Asist[Week].Rabu[4], LSS);
    break;

    case 4:

    strcpy(Dbs->Asist[Week].Kamis[1], LAB1);
    strcpy(Dbs->Asist[Week].Kamis[2], LAB2);
    strcpy(Dbs->Asist[Week].Kamis[3], LAB3);
    strcpy(Dbs->Asist[Week].Kamis[4], LSS);

    break;

    case 5:

    strcpy(Dbs->Asist[Week].Jumat[1], LAB1);
    strcpy(Dbs->Asist[Week].Jumat[2], LAB2);
    strcpy(Dbs->Asist[Week].Jumat[3], LAB3);
    strcpy(Dbs->Asist[Week].Jumat[4], LSS);

    break;


    }






}

int dayToNumber(char Day[]){
    if(!strcmp(Day, "Senin")){ return(1);}
    else if(!strcmp(Day, "Selasa")){ return(2);}
    else if(!strcmp(Day, "Rabu")){ return(3);}
    else if(!strcmp(Day, "Kamis")){ return(4);}
    else if(!strcmp(Day, "Jumat")){ return(5);}

}

int strToInt(char Str[]){
    /*if(strlen(Str)>2){return(-1);}
    else if (strlen(Str)=2){return((int) Str[0] * 10+ (int) Str[1]);}
    else {return((int) Str[0]);}

        */

        return(1);
}
