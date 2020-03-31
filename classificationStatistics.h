//
// Created by Antoine Lambert on 19-03-20.
//

#ifndef IDI_CLASSIFICATIONSTATISTICS_H
#define IDI_CLASSIFICATIONSTATISTICS_H
#include "dao.h"
#include "string.h"

void test_dao();

/*  Affiche un tableau reprenant les différentes classes disponibles (cfr interface1 - document de projet), combien ont bien été classées dans estimateClasses, le nombre d'occurences de chaque classe dans vecteur realClasses et un pourcentage de classes qui ont bien été classées dans estimateClasses.
 *
 *  @param realclasses est un vecteur de classes
 *
 *  @return void
 */
void displayResultsForEachClasses(int *realClasses, int *estimateClasses);

/* 	Affiche la précision de l'estimation faite par estimateClasses sur le vecteur realclasses et l'affiche sous la forme suivante "L’accuracy est de XX%".
 *
 *  @param realClasses est un vecteur de classes concrètes
 *  @param estimateClasses est un vecteur de classes estimées par le programme
 *
 *  @return void
 */
void displayAccuracy(int *realclasses, int *estimateClasses);

/* 	crée un graphique à bars (cfr interface 2 - document de projet)
 *  @params TODO
 *  @return void
 */
void displayBarChart();

/* fonction générale de test de la librairie
 *
 */
void test_classificationStatistics(void);

#endif //IDI_CLASSIFICATIONSTATISTICS_H
