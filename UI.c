#include <stdio.h>
#include "interfacelib.h"
#include "business.h"

int main() {
    line();
    title();
    line();
    printf("Bonjour et bienvenue dans ce programme de reconnaissance d'activités.\n");
    printf("Veuillez choisir une  des propositions suivantes:\n");
    printf("1: Generer le modele\n");
    printf("2: Tester le programme\n");
    printf(">");
    int userInput;
    scanf("%d",&userInput);
    switch (userInput)
    {
        case 1:
            printf("Début de la génération du modele\n");
            modele_generation();
            break;
        case 2:
            printf("Début des tests\n");
            //line();
            //    test_classificationStatistics();
            //line();
                test_dao();
            //line();
            break;
        default:
            printf("Choix incorrect\n");
    }

    return 0;
}





