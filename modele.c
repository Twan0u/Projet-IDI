//
// Created by Antoine Lambert on 26-05-20.
//

#include "modele.h"
#include <math.h>

/*fonction de mise à la puissance 2*/
double pow2(double nombre){
    return nombre*nombre;
}

/*fonction qui génère le modele*/
double modele_base(double* data){
    double val = pow2(data[10]) + pow2(data[11]) + pow2(data[12]);
    return sqrt(val);
}


/*Cette fonction agit comme un proxy et permets de facilement changer la fonction modele sans devoir modifier beaucoup de code*/
double modele_set(double* data){
    return modele_base(data);
}

