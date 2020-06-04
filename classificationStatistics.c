//
// Created by Antoine Lambert and Arnaud Cassart on 19-03-20.
//

#include "classificationStatistics.h"
#include "dao.h"
#include "UnitTest.h"

//Contient le taille de l'unité de base pour le diagramme en batonnets
#define MAX_SIZE_BAR 52

#define LINE printf("\n");


/* Contiens un tableau de classes et la taille de ce tableau
 *
 * vector est un tableau contenant des entiers
 * size est la taille de ce tableau
 *
 */
/*
typedef struct Classes Classes;
struct Classes {
    int *vector;
    int size;
};*/
/* Prends le tableau oldArray et le copie dans un nouveau tableau qui mesure une unité de plus que oldArray
 *
 * @param oldArray ancien tableau que l'on souhaite agrandir et copier
 * @param newArray nouveau tableau de taille sizeOldArray +1 dans lequel on va copier les données de l'ancien
 * @param sizeOldArray taille de l'ancien tableau oldArray
 *
 *//*
void sizeUpArray(int* oldArray,int* newArray, int sizeOldArray){
    for(int i=0;i<sizeOldArray;i++)
        newArray[i] = oldArray[i];
}*/

/* Ajoute à la au tableau classes un élément si celui-ci n'existe pas déjà dedans. Cette fonction incrémentera ensuite le compteur de classes de 1 si elle à ajouté un élément
 *
 * @param classes est un pointeur vers un tableau tableau et nbClasses est la taille de celui-ci. Il est utilisé pour stocker les différentes classes individuellement différentes
 * @param realClasse est le nouvel élément dont on doit vérifier l'existence *
 * @return la structure classes entrée en paramètre d'entrée à laquelle on doit ou non ajouter newItem si celui-ci n'était pas déjà présent. cette structure aura son compteur size augmenté de 1 si un élément à été ajouté
 * */

int addWithoutDuplicateClasses(int* classes,int realClasse, int nbClasse)
{

    if (nbClasse == 0) { // si le tableau est vide
        nbClasse = 1;
        *(classes) = 1;
        for (int i = 1; i < MAX_NB_PATTERN; i++) {
            *(classes + i) = 0;
        }
        return nbClasse;
    }// si le tableau n'est pas vide
    // recherche dans tous les éléments de la structure
    for (int i = 0; i < MAX_NB_PATTERN; i++) {
        if (i == realClasse) {
            nbClasse++;
            *(classes + i)= *(classes+i)+1;
            return nbClasse; // Oui
        }

    }
}



/* 	Crée un tableau reprenant les classes différentes que contiens realClasses et supprime les doublons.
 *
 *  @param realClasses est un tableau contenant de les classes existantes
 *
 *  @return un le nombre de classe différentes existant
 */
int researchClasses(int* classes,int* realClasses, int realClassesSize)
{
    int nbClasse=0;
    // Itération sur chaque élément de realClasses et Ajout sans doublons à la structure
    for(int i = 0; i<realClassesSize; i++){
        nbClasse = addWithoutDuplicateClasses(classes,*(realClasses+i),nbClasse);
    }
    // Retourner le nombre de classe
    return nbClasse;
}

/* retourne le calcul d'un pourcentage de ( sum / total ) * 100
 *
 * @param sum est le nombre de réalisation
 * @param total est le nombre d'essais
 *
 * @return un pourcentage. Si sum est suppérieur à total, retourne 100.
 *//*
double percentage(int sum, int total){
    if (sum < total){
        return ((double)sum/(double)total)*100;
    }else{
        return 100;
    }
}*/

/* Test de la fonction de pourcentage
 * Cette méthode effectue des tests pour vérifier que la fonction pourcentage fonctionne toujours
 */
/*int test_percentage(void){
    int error_counter = 0;
    int* error_counter_ptr= &error_counter;
    error_assert(percentage(3300,10000) == 33.00,"simple de pourcentage",error_counter_ptr);
    error_assert(percentage(3333,10000) == 33.33,"pourcentage avec 2 nombres derrière la virgule ",error_counter_ptr);
    error_assert(percentage(1000,10) == 100,"sum suppérieur à total",error_counter_ptr);
    return error_counter;
}*/

/*	Compare 2 entiers et vérifie que ceux-ci sont identiques
 *
 *	@param firstElement premier entier à comparer
 *	@param secondElement second entier à comparer
 *
 *	@return 0 si les 2 éléments sont identiques et autre chose sinon
 */
void compare(int* malClasse,int* realClasses,int* estimateClasses,int nbRealClasse)
{
    for (int i =0 ; i<nbRealClasse; i++)
    {
        if(*(realClasses+i)!=*(estimateClasses+i))
        {
            *(malClasse+*(realClasses+i))= *(malClasse + *(realClasses + i))+1;
        }
    }
}

void generateClasses(double** classes, int* realClasses, int* estimateClasses, double** patterns, int nbRealClasse,char ** category)
{
    char cat[MAX_LENGTH_CATEGORY];
    int realClasse = 0;

    realClasses= (int*) calloc(nbRealClasse,sizeof (int));
    estimateClasses = (int*) calloc(nbRealClasse, sizeof(int));

    strcpy_s(cat,sizeof(cat) ,*(category));
    for (int i = 0; i < nbRealClasse; i++)
    {
        *(estimateClasses+i)= distanceEuclidienne(*(classes + i), patterns);
        if (strcmp(cat,*(category+i))==0)
        {
            *(realClasses+i) = realClasse;
        }
        else
        {
            strcpy_s(cat, sizeof(cat), *(category+i));
        }
    }
}

/* Test sur la fonction compare()
 */
/*int test_compare(void){
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
}*/

/*	Compare 2 vecteurs entre eux et retourne un tableau de taille identique au premier vecteur mis en paramètre. Si l'élément du tableau vaut 0, cela signifie que les 2 vecteurs ont le même contenu.
 *
 *	@param realClasses est le premier vecteur a comparer
 *  @param estimateClasses est un second vecteur qui sera comparé au premier
 *
 *  @return un tableau d'entier de même taille que realClasses qui contiens un 0 quand les 2 éléments du tableau sont identiques et autre chose quand ils sont différents
 */
/*int *compareVectors(int *realClasses, int *estimateClasses){
    //int out[1];
    return realClasses;
}*/

/*  Affiche un tableau reprenant les différentes classes disponibles (cfr interface1 - document de projet), combien ont bien été classées dans estimateClasses, le nombre d'occurences de chaque classe dans vecteur realClasses et un pourcentage de classes qui ont bien été classées dans estimateClasses.
 *
 *  @param realclasses est un tableau de vecteur
 *
 *  @return void
 */
void displayResultsForEachClasses( int *realClasses, int* estimateClasses,int nbRealClasse)
{
    int malClasse[MAX_NB_PATTERN];// contient pour chacune des classes le nombre d'éléments mal classe
    int classes[MAX_NB_PATTERN];

    int nbClasse = researchClasses(classes, realClasses, nbRealClasse);

    compare(malClasse, realClasses, estimateClasses, nbRealClasse);

    printf("classe          |   bien classe   |   total   |    Pourcentage");
    LINE;
    for(int i=0;i<nbClasse; i++)
    {
        printf("%d            |%5d            |%5d      |       %f",i+1,*(malClasse+i),*(classes+i),((double)*(malClasse+i)/ *(classes+i)*100));
        LINE;
    }
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

/*crée une barre de longueur donnée
 *@params void
 *@return void
 */
void displayBar(int size)
{
    for (int i=0;i<size;i++)
    {
        printf("__");
    }
}
/* crée une échelle  pour le graphique à barre
 * @params scale est l'échelle  = nombre d'élements total/50
 * @return void
 */
//test
void displayScale(int scale)
{
    printf("   ");
    for(int i = 1; i < MAX_SIZE_BAR; i++)// réalise la première ligne de l'échelle
    {
        printf(" ");
        if (i<=2 || (i!=0 && i%10==0))
            printf("%d",i*scale);
        else if (i%10!=1) printf(" ");
    }
    LINE;
    printf("___");
    for(int i = 1; i < MAX_SIZE_BAR; i++)// réalise la deuxième ligne de l'échelle
    {
        printf("_");
        if (i<=2 || (i!=0 && i%10==0))
            printf("|");
        else printf("_");
    }
    LINE;
    for(int i =0;i<3;i++)
    {
        printf("  |");
        LINE;
    }
}

/* 	crée un graphique à bars (cfr interface 2 - document de projet)
 *  @params TODO
 *  @return void
 */

void displayBarChart(int* realClasses, int* estimateClasses, int nbRealClasse)
{
    int malClasse[MAX_NB_PATTERN];// contient pour chacune des classes le nombre d'éléments mal classe
    int classes[MAX_NB_PATTERN];

    int nbClasse =researchClasses(classes, realClasses, nbRealClasse);

    compare(malClasse, realClasses, estimateClasses, nbRealClasse);

    printf("Legende : \n"
           "T : Total\n"
           "N : Nombre de bien classe\n"
           "P : nombre de pas correctement classe\n\n\n");
    displayScale((nbRealClasse/50)+1);
    for(int i =0; i<nbClasse; i++)
    {
        printf(" P|");
        displayBar(*(classes+i)-*(malClasse+i));
        LINE;
        printf("%iN|",i+1);
        displayBar(*(malClasse + i));
        LINE;
        printf(" T|");
        displayBar(*(classes + i));
        LINE;
        printf("  |");
        LINE;
    }
}
void test_display()
{
    int testClasses[MAX_NB_PATTERN];// contient le nombre d'élément de chacune des classes
    char** category=(char**) calloc(4,sizeof(char*));
    int* testRealClasses;
    int* testEstimateClasses;

    int testNbClasses;
    int nbRealClasse; // nbligne dans testset
    double** patterns;
    double** classes;

    csv_file_reader2("test_set.csv",65000,MAX_VECTOR,nbRealClasse,classes,category); // TODO nbligne dans testset

    int nbClassesTest = researchClasses(testClasses,testRealClasses,nbRealClasse); // nbligne dans test

    generateClasses(classes, testRealClasses, testEstimateClasses, patterns, nbRealClasse,category);

    displayResultsForEachClasses(testRealClasses,testEstimateClasses,nbRealClasse);
    displayAccuracy(testRealClasses,testClasses,nbRealClasse);
    displayBarChart(testRealClasses, testEstimateClasses, nbRealClasse);

}


void test_classificationStatistics(void){
    printf("Début - Test de classification Statistics :\n");
    //printf("\tx Fonction compare : %d erreurs\n",test_compare());
    // printf("\tx Fonction percentage : %d erreurs\n",test_percentage());
    printf("\tx Fonction display \n"); test_display();
    printf("Fin - Test de classification Statistics :\n");
}