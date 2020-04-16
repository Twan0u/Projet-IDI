#include <stdio.h>
#include "classificationStatistics.h"
#include "interfacelib.h"

int main() {
    line();
    title();
    line();
    printf("Bonjour et bienvenue dans ce programme de reconnaissance d'activités.\n");
    printf("Veuillez choisir une  des propositions suivantes:\n");
    printf("1: ...\n");
    printf("2: Tester le programme\n");
    printf(">");
    int userInput;
    scanf("%d",&userInput);
    switch (userInput)
    {
        case 1:
            printf("Vous avez sélectionné 1.\n");
            break;
        case 2:
            printf("Début des tests\n");
            line();
                test_classificationStatistics();
            line();
                test_dao();
            line();
            break;
        default:
            printf("Choix incorrect\n");
    }

    return 0;
}





