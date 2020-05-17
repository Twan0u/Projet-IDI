//
// Created by Antoine Lambert on 16-05-20.
//

#include "business.h"

#include <math.h>

/*fonction de mise à la puissance 2*/
double pow2(double nombre){
    return nombre*nombre;
}

/*fonction qui génère le modele*/
double modele(double* data){
    double val = pow2(data[10]) + pow2(data[11]) + pow2(data[12]);
    return sqrt(val);
}

void test_dao(){
    //test();

    int lines_max = 1000;
    int coll_max = 13;

    double** data = (double**) calloc(lines_max, sizeof(double*));
    if (data==NULL){
        printf("pas assze de mémoire");
    }
    for(int i=0;i<lines_max;i++){
        data[i] = (double*) calloc (coll_max,sizeof(double));
        if (data[i]==NULL){
            printf("pas assze de mémoire - %d", i);
        }
    }
     csv_file_reader("./data/dws_1/sub_2.csv", 2048, coll_max, lines_max, data);

    for(int i=0;i<lines_max;i++){
        printf("%lf",modele(data[i]));
        printf("\n");
    }

    for(int i=0;i<lines_max;i++){
        free(data[i]);
    }

    free(data);

    //test calloc [10000][13]

}