//
// Created by Antoine Lambert on 19-03-20.
//

#ifndef IDI_CLASSIFICATIONSTATISTICS_H
#define IDI_CLASSIFICATIONSTATISTICS_H
#include "dao.h"
void test_dao();


/* Crée un tableau reprenant les classes différentes et de connaître le nombre de classes.
 *  @params : TODO
 *  @return : TODO
 * */
void researchClasses();

/*  Crée un tableau reprenant la classes(cfr interface1 - document de projet), les bien classes un total et un calcul du pourcentage de bien classes
 *  @params : TODO
 *  @return : TODO
 * */
void displayResultsForEachClasses();

/* fonction permettant l'affichage de l'accuracy "L’accuracy est de 78%"
 *  @params : TODO
 *  @return : TODO
 * */
void displayAccuracy();

/* crée un graphique à bars (cfr interface 2 - document de projet)
 *  @params : TODO
 *  @return : TODO
 * */
void displayBarChart();

#endif //IDI_CLASSIFICATIONSTATISTICS_H
