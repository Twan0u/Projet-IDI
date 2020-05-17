//
// Created by Antoine Lambert on 16-05-20.
//

#include "business.h"
#include <math.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_DIRECTORY 15
#define MAX_FILES_PER_DIR 24

/*fonction de mise à la puissance 2*/
double pow2(double nombre){
    return nombre*nombre;
}

/*fonction qui génère le modele*/
double modele(double* data){
    double val = pow2(data[10]) + pow2(data[11]) + pow2(data[12]);
    return sqrt(val);
}

void file_modele_generation(const char* path){
    int lines_max = 1000; //todo changer
    int coll_max = 13; //todo changer

    // Allocation de mémoire
    double** data = (double**) calloc(lines_max, sizeof(double*));
    if (data==NULL){
        printf("pas assze de mémoire");
    }
    for(int i=0;i<lines_max;i++){
        data[i] = (double*) calloc (coll_max,sizeof(double));
        if (data[i]==NULL){
            printf("pas assze de mémoire - %d", i);
        }
    }//fin allocation mémoire


    csv_file_reader(path, 2048, coll_max, lines_max, data);//TODO bufferline size

    for(int i=0;i<lines_max;i++){ // pour chaque ligne du tableau
        // génération du test file
        if((i%10)==0){//todo possibilite de changer la frequence
            // 1/10 des données dans un fichier data_test.csv
            //print la ligne dans le test set
        }else{
            //todo calculer le modele
            //todo mettre ces données dans un tableau
            //todo mettre ce tableau dans un fichier (modele.csv)
            printf("%lf",modele(data[i]));
            printf("\n");
        }
    }

    // Libération de la mémoire
    for(int i=0;i<lines_max;i++){
        free(data[i]);
    }
    free(data);
    // FIN - Libération de la mémoire
}

void modele_generation(){
    // Charger tous les fichiers dans un tableau.
    char data[MAX_DIRECTORY][MAX_FILES_PER_DIR][MAX_FILE_PATH_LENGTH];
    for (int i=0;i<MAX_DIRECTORY;i++){
        for(int j=0;j<MAX_FILES_PER_DIR;j++){
            data[i][j][0]= '\0';
        }
    }

    dir_list("./data",MAX_DIRECTORY,MAX_FILES_PER_DIR,data);
    char category[4];
    for (int i=0;i<MAX_DIRECTORY;i++){
        category[0]='\0';
        activity_recogniser(data[i][1],category);
        printf("%s\n",category);
        for(int j=0;j<MAX_FILES_PER_DIR;j++){
            printf("%s --",data[i][j]);
            //operation sur chaque fichier
            file_modele_generation(data[i][j]);
        }
        printf("\n");
    }
}
void test_dao(){
    // useless
}