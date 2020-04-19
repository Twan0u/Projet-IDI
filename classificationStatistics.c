//
// Created by Antoine Lambert on 19-03-20.
//

#include "classificationStatistics.h"
#include "dao.h"
#include "UnitTest.h"

/* Contiens un tableau de classes et la taille de ce tableau
 *
 * vector est un tableau contenant des entiers
 * size est la taille de ce tableau
 *
 */
typedef struct Classes Classes;
struct Classes {
    int *vector;
    int size;
};
/* Prends le tableau oldArray et le copie dans un nouveau tableau qui mesure une unité de plus que oldArray
 *
 * @param oldArray ancien tableau que l'on souhaite agrandir et copier
 * @param newArray nouveau tableau de taille sizeOldArray +1 dans lequel on va copier les données de l'ancien
 * @param sizeOldArray taille de l'ancien tableau oldArray
 *
 */
void sizeUpArray(int* oldArray,int* newArray, int sizeOldArray){
    for(int i=0;i<sizeOldArray;i++)
        newArray[i] = oldArray[i];
}

/* Ajoute à la structure Classes un élément si celui-ci n'existe pas déjà dedans. Cette fonction incrémentera ensuite le compteur de classes de 1 si elle à ajouté un élément
 *
 * @param classes est une structure contenant un tableau et la taille de celui-ci. Il est utilisé pour stocker les différentes classes individuellement différentes
 * @param newItem est le nouvel élément à ajouter à classes
 *
 * @return la structure classes entrée en paramètre d'entrée à laquelle on doit ou non ajouter newItem si celui-ci n'était pas déjà présent. cette structure aura son compteur size augmenté de 1 si un élément à été ajouté
 * */
Classes addWithoutDuplicateClasses(Classes classes, int newItem){
    if (classes.size==0){ // si le tableau est vide
        classes.size = 1;
        int newArray[] ={newItem};
        classes.vector = newArray;
        return classes;
    }else{// si le tableau n'est pas vide
        for(int i=0; i< classes.size;i++){ // recherche dans tous les éléments de la structure
            if(classes.vector[i]==newItem){// Le nouvel élément existe-il déjà ?
                return classes; // Oui
            }
        }
        // Le nouvel élément n'existe pas encore
        int newArray[classes.size+1];
        sizeUpArray(classes.vector, newArray, classes.size); // on agrandit la taille du tableau de 1 unité
        classes.vector = newArray;
        classes.vector[classes.size] = newItem;//ajout du nouvel élément dans le tableau
        classes.size = classes.size+1;
        return classes;
    }

}

/* 	Crée un tableau reprenant les classes différentes que contiens realClasses et supprime les doublons.
 *
 *  @param realClasses est un vecteur contenant de une série de classes
 *
 *  @return une structure de donnée contenant un tableau avec les classes individuellement différentes et le nombre total de classes individuellement différentes disponibles.
 */
Classes researchClasses(int* realClasses, int realClassesSize){
    // Création de la structure de retour
    Classes output;
    output.size=0;
    // Itération sur chaque élément de realClasses et Ajout sans doublons à la structure
    for(int i = 0; i<realClassesSize; i++){
        output= addWithoutDuplicateClasses(output,realClasses[i]);
    }
   // Retourner la structure sans doublons
    return output;
}

/* retourne le calcul d'un pourcentage de ( sum / total ) * 100
 *
 * @param sum est le nombre de réalisation
 * @param total est le nombre d'essais
 *
 * @return un pourcentage. Si sum est suppérieur à total, retourne 100.
 */
double percentage(int sum, int total){
    if (sum < total){
        return ((double)sum/(double)total)*100;
    }else{
        return 100;
    }
}

/* Test de la fonction de pourcentage
 * Cette méthode effectue des tests pour vérifier que la fonction pourcentage fonctionne toujours
 */
int test_percentage(void){
    int error_counter = 0;
    int* error_counter_ptr= &error_counter;
    error_assert(percentage(3300,10000) == 33.00,"simple de pourcentage",error_counter_ptr);
    error_assert(percentage(3333,10000) == 33.33,"pourcentage avec 2 nombres derrière la virgule ",error_counter_ptr);
    error_assert(percentage(1000,10) == 100,"sum suppérieur à total",error_counter_ptr);
    return error_counter;
}

/*	Compare 2 entiers et vérifie que ceux-ci sont identiques
 *
 *	@param firstElement premier entier à comparer
 *	@param secondElement second entier à comparer
 *
 *	@return 0 si les 2 éléments sont identiques et autre chose sinon
 */
int compare(int firstElement, int secondElement){
    return firstElement-secondElement;
}

/* Test sur la fonction compare()
 */
int test_compare(void){
    int error_counter = 0;
    int* error_counter_ptr= &error_counter;
    error_assert(compare(1,1) == 0,"Comparaison de 2 nombres identiques",error_counter_ptr);
    error_assert(compare(1,2) != 0,"Comparaison de 2 nombres différents",error_counter_ptr);
    error_assert(compare(0,0) == 0,"Comparaison entre 2 zeros",error_counter_ptr);
    error_assert(compare(1,0)!=0,"Comparaison entre un nombre non nul et zero",error_counter_ptr);
    error_assert(compare(-5,-5)==0,"Comparaison de 2 nombres identiques négatifs",error_counter_ptr);
    error_assert(compare(-4,8)!=0,"Comparaison entre 2 nombres différents dont un négatif",error_counter_ptr);
    error_assert(compare(-4,-16)!=0,"Comparaison entre 2 nombres négatif différents",error_counter_ptr);
    return error_counter;
}

/*	Compare 2 vecteurs entre eux et retourne un tableau de taille identique au premier vecteur mis en paramètre. Si l'élément du tableau vaut 0, cela signifie que les 2 vecteurs ont le même contenu.
 *
 *	@param realClasses est le premier vecteur a comparer
 *  @param estimateClasses est un second vecteur qui sera comparé au premier
 *
 *  @return un tableau d'entier de même taille que realClasses qui contiens un 0 quand les 2 éléments du tableau sont identiques et autre chose quand ils sont différents
 */
int *compareVectors(int *realClasses, int *estimateClasses){
    //int out[1];
    return realClasses;
}

/*  Affiche un tableau reprenant les différentes classes disponibles (cfr interface1 - document de projet), combien ont bien été classées dans estimateClasses, le nombre d'occurences de chaque classe dans vecteur realClasses et un pourcentage de classes qui ont bien été classées dans estimateClasses.
 *
 *  @param realclasses est un vecteur de classes
 *
 *  @return void
 */
void displayResultsForEachClasses(int *realClasses, int *estimateClasses){

}

/* 	Affiche la précision de l'estimation faite par estimateClasses sur le vecteur realclasses et l'affiche sous la forme suivante "L’accuracy est de XX%".
 *
 *  @param realClasses est un vecteur de classes concrètes
 *  @param estimateClasses est un vecteur de classes estimées par le programme
 *  @param sizeOfRealClasses est la taille du vecteur realClasses
 *
 *  @return void
 */
void displayAccuracy(int *realClasses, int *estimateClasses, int sizeOfRealClasses){
    int errors = 0;
    for(int i=0;i<sizeOfRealClasses;i++){
        if (realClasses[i]!=estimateClasses[i]){
            errors++;
        }
    }
    double accuracy = 100-((errors*100)/sizeOfRealClasses);
    printf("L'accuracy est de %.2f%%\n",accuracy);
}

/* 	crée un graphique à bars (cfr interface 2 - document de projet)
 *  @params TODO
 *  @return void
 */
void displayBarChart(){

}

void test_dao(){
    test();
}

void test_classificationStatistics(void){
    printf("Début - Test de classification Statistics :\n");
        printf("\tx Fonction compare : %d erreurs\n",test_compare());
        printf("\tx Fonction percentage : %d erreurs\n",test_percentage());
    printf("Fin - Test de classification Statistics :\n");
}