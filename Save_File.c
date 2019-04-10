//***********************************************************//



//                      [ Source Code ]



//



// Institution: Institut Teknologi Bandung



// Name: A2



// File Name: Save_File.c



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

bool saveProject(Dbs_Type Dbs){

    char File_Name[100], Day;
    FILE *pFile;

    printf("\nTentukan di file mana akan disimpan schedule praktikum (.csv) :");
    scanf("%s", File_Name);

    pFile= fopen(File_Name, "w+");

    if(pFile){ //Jika file tidak dapat dibuka
        printf("\nFile tidak dapat ditemukan\nApakah akan masukkan lagi?(Y T)"); //Cek apakah ingin mengulangi atau tidak
        char c;
        scanf("%c", c );
        if ((c=='Y')||(c=='y')){return(false);} else{return(true);}
    }
    else{ //Jika file dapat dibuka

        //Tuliskan header
        fprintf(pFile, "Ruang Praktikum;Lab1:LAB2;LAB3;LSS\nMinggu;Hari\n");

        //Tuliskan isi database
        for (int i=3; i<= 14; i++){
            for (int j=1; j<=5; j++){
                switch(j){
                    case 1: strcpy(Day,"Senin"); break;
                    case 2: strcpy(Day,"Selasa"); break;
                    case 3: strcpy(Day,"Rabu"); break;
                    case 4: strcpy(Day,"Kamis"); break;
                    case 5: strcpy(Day,"Jumat"); break;

                }

               /* fprintf(pFile, "%d;%s;%s-%s;%s-%s;%s-%s;%s-%s\n", i, Day, Dbs.Prak.(Day)[1].Kode, Dbs.Prak.(Day)[1].Romb,
                         Dbs.Prak.(Day)[2].Kode,Dbs.Prak.(Day)[2].Romb, Dbs.Prak.(Day)[3].Kode,Dbs.Prak.(Day)[3].Romb,
                         Dbs.Prak.(Day)[4].Kode, Dbs.Prak.(Day)[4].Romb);

                */
        }


        fclose(pFile);

        //Save file asisten

        printf("\nTentukan di file mana akan disimpan schedule asisten (.csv) :");
        scanf("%s", File_Name);

        pFile= fopen(File_Name, "w+");

        if(pFile){ //Jika file tidak dapat dibuka
            printf("\nFile tidak dapat ditemukan\nApakah akan masukkan lagi?(Y T)"); //Cek apakah ingin mengulangi atau tidak
            char c;
            scanf("%c", c );
            if ((c=='Y')||(c=='y')){return(false);} else{return(true);}
        }
        else{ //Jika file dapat dibuka

            //Tuliskan header
            fprintf(pFile, "Ruang Praktikum;Lab1:LAB2;LAB3;LSS\nMinggu;Hari\n");

            //Tuliskan isi database
            for (int i=3; i<= 14; i++){
                for (int j=1; j<=5; j++){
                    switch(j){
                        case 1: strcpy(Day,"Senin"); break;
                        case 2: strcpy(Day,"Selasa"); break;
                        case 3: strcpy(Day,"Rabu"); break;
                        case 4: strcpy(Day,"Kamis"); break;
                        case 5: strcpy(Day,"Jumat"); break;

                    }}

                 /*   fprintf(pFile, "%d;%s;%s;%s;%s;%s\n", i, Day, Dbs.Asist.(Day)[1], Dbs.Asist.(Day)[2]
                            Dbs.Asist.(Day)[3], Dbs.Asist.(Day)[4]);
                */

            }





            fclose(pFile);
        return(true);
    }



    }


}}
