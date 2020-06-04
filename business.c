//
// Created by Antoine Lambert on 16-05-20.
//

#include "business.h"
//#include "modele.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_DIRECTORY 15
#define MAX_FILES_PER_DIR 24
#define MAX_SIZE_NUM_IN_FILE 69
//todo changer max size num in file

/**fonction qui génère la distance euclidienne entre des valeurs et un pattern
 *@params valeurs contient un tableau de vecteur (1 entree)
 *@params pattern contient un tableaux contenant tout les pattern (2 entree)
 * renvoie un entier correspondant a au pattern avec la plus petite distance euclidienne
 */
int distanceEuclidienne(double* valeurs, double** patterns)
{
    double sommes[MAX_NB_PATTERN];
    int line, minDistance;
    int coll = 0;
    double minVector = LONG_MAX; //valeur maximale pour un double/long
    double valeur;

    while (coll < MAX_VECTOR)
    {
        line = 0;
        valeur = *(valeurs + coll);
        while (line < MAX_NB_PATTERN)
        {
            sommes[line] = pow(valeur - *(*(patterns + line) + coll), 2);//
            line++;
        }
        coll++;
    }
    double results;
    for (int i = 0; i < MAX_NB_PATTERN; i++)
    {
        results = sqrt(*(sommes + i));
        if (minVector > results)
        {
            minVector = results;
            minDistance = i;
        }
    }
    return minDistance;
}

/** Cette fonction
 *
 * @param path
 * @param fichier_sortie
 * @param lines_max
 * @param coll_max
 * @param index_in_file index à indiquer comme premier élément de chaque ligne dans le fichier de sortie
 * @param category dernier élément de chaque ligne dans le fichier de sortie
 * @return code erreur qui décrit comment la fonction s'est terminée
 *
 * Erreurs :
 *      * 0 Tout c'est terminé correctement
 *      * 1 Il y a eu un problème lors de l'attribution de mémoire (pas assez de mémoire disponible)
 *      * 2 Il y a eu un problème lors de l'ouverture du fichier à l'adresse path
 */
int file_modele_generation(const char* path, const char* fichier_sortie, int lines_max, int coll_max, double index_in_file, char category[4]) {
    /* Début : Allocation de mémoire */
    double** data_from_file = (double**)calloc(lines_max, sizeof(double*));//data_from_file représente les données contenues dans le fichier à l'adresse path
    if (data_from_file == NULL) {
        return 1; //erreur mémoire faible
    }
    for (int i = 0; i < lines_max; i++) {
        data_from_file[i] = (double*)calloc(coll_max, sizeof(double));
        if (data_from_file[i] == NULL) {
            return 1; //erreur mémoire faible
        }
    }
    /* fin :  allocation mémoire */

    int csv_return_code = csv_file_reader(path, coll_max, lines_max, data_from_file);//TODO bufferline size (à augmenter pour permettre un traitement de fichiers plus grands) ( ici 2048 caractères)

    if (csv_return_code == 1) {//code erreur en cas de problème à l'ouverture du fichier renvoyé par csv_file_reader
        return 2; // code erreur en cas d'imposibilité d'ouvrir le fichier
    }

    double buffer[lines_max + 1]; // le +1 est utilisé pour comptabiliser la colonne index en début
    buffer[0] = index_in_file;

    for (int i = 0; i < lines_max; i++) { // pour chaque ligne d'un fichier
        buffer[i + 1] = modele_set(data_from_file[i]);
    }

    //todo error codes
    write_csv(fichier_sortie, lines_max, buffer, category);

    // Libération de la mémoire
    for (int i = 0; i < lines_max; i++) {
        free(data_from_file[i]);
    }
    free(data_from_file);
    // FIN - Libération de la mémoire
}

void modele_generation() {

    char* nom_fichier_entrainement = "train_set.csv";
    char* nom_fichier_test = "test_set.csv";
    int pourcentage_dans_testset = 10; //pourcentage des données à mettre dans le testset
    int trainvalue = 100 / pourcentage_dans_testset;
    int lines_max_to_read_in_file = 1000;
    int coll_max_to_read_in_file = 13;

    // Charger tous les fichiers dans un tableau.
    char data[MAX_DIRECTORY][MAX_FILES_PER_DIR][MAX_FILE_PATH_LENGTH];
    for (int i = 0; i < MAX_DIRECTORY; i++) {
        for (int j = 0; j < MAX_FILES_PER_DIR; j++) {
            data[i][j][0] = '\0';
        }
    }

    dir_list("./data", MAX_DIRECTORY, MAX_FILES_PER_DIR, data);

    write_title_csv(nom_fichier_entrainement, "index,Values...,Activity(ACT)");
    write_title_csv(nom_fichier_test, "index,Values...,Activity(ACT)");

    double index_in_out = 0;
    double index_in_test = 0;
    int filecount = 0;
    char category[4]; //3 charactères du nom et '/0'
    for (int i = 0; i < MAX_DIRECTORY; i++) {
        category[0] = '\0';
        activity_recogniser(data[i][1], category);
        printf("%s\n", category);
        for (int j = 0; j < MAX_FILES_PER_DIR; j++) {
            printf("%s --", data[i][j]);//si on veut afficher le nom du fichier a traiter
            if (filecount % trainvalue == 0) {
                file_modele_generation(data[i][j], nom_fichier_test, lines_max_to_read_in_file, coll_max_to_read_in_file, index_in_test, category);
                index_in_test++;
            }
            else {
                file_modele_generation(data[i][j], nom_fichier_entrainement, lines_max_to_read_in_file, coll_max_to_read_in_file, index_in_out, category);//remettre 1000 et 13
                //todo changer valeur fixes
                //todo changer le nombres de colonnes dans les fichiers de départ
                index_in_out++;
            }
            filecount++;
        }
        printf("\n");
    }
}


void gen_mod(double ** pattern)
{
    int line = 400; //lignes dans le fichier train_set //todo modifier en fonction du nombres de fichiers a analyser
    int coll = 1000;//todo
    //coll++;// todo il ne faut pas +1 ?
    const char* train_set_path = "train_set.csv";
    char cat[MAX_LENGTH_CATEGORY];
    double somme[400];
    int iPattern, i, iter, nbLigne = 0;


    for (iter = 0; i < coll; i++)somme[i] = 0;

    double** data = (double**)calloc(line, sizeof(double*));//todo verifier mémoire disponible
    for (int i = 0; i < line; i++) {
        data[i] = (double*)calloc(coll, sizeof(double));
    }

    double** patern = (double**)calloc(line, sizeof(double*));//todo verifier mémoire disponible
    for (int i = 0; i < line; i++) {
        pattern[i] = (double*)calloc(coll, sizeof(double));
    }

    char** category = (char**)calloc(line, sizeof(char*));// car il faut compter les 3 pour le mot et 1 pour le \0
    for (int i = 0; i < line; i++) {
        category[i] = (char*)calloc(4, sizeof(char));
    }

    csv_file_reader2(train_set_path, 65000, coll, line, data, category);//todo expliquer 6500000

    while (i < line)
    {
        strcpy_s(cat, MAX_LENGTH_CATEGORY, *(category + i));

        while (i < line && strcmp(cat, *(category + i)) == 0)
        {
            iter = 0;

            while (i < line && strcmp(cat, *(category + i)) == 0 && iter < coll)
            {
                somme[iter] += **((data + iter) + i);
                iter++;
            }
            strcpy_s(cat, MAX_LENGTH_CATEGORY, *(category + i));
            i++;
        }

        for (int iColl = 0; iColl < coll; iColl++)
        {
            **((pattern + iPattern) + iColl) = somme[iColl] / (i - nbLigne);
        }
        nbLigne += i;

    }

}


void test_dao() {//todo remove safely
    gen_mod();
}