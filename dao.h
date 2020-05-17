//
// Created by Antoine Lambert on 20-03-20.
//

#ifndef IDI_DAO_H
#define IDI_DAO_H

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <dirent.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_DIRECTORY 15
#define MAX_FILES_PER_DIR 24

void test();

void file_list(char* path_of_dir,int number_of_files_max, char output[number_of_files_max][MAX_FILE_PATH_LENGTH]);

/**
 * Reconaissance d'une activité sur base de son path ( chemin ). Il faut impérativemnt que le chemin soit construit comme suit : ./data/ACT_NUM/sub_NUM.csv le programme renverra ACT
 *
 * @param path chemin du fichier './data/ACT_NUM/sub_NUM.csv'
 * @param category ACTIVITE (ACT) contenue dans le path
 *
 * Complexite temporelle : O(1)
 * Complexité memoire : O(1)
 *
 */
void activity_recogniser(char* path, char category[4]);

/**
 * Cette fonction permets de récupérer des nombres réels contenus dans un fichier csv et de les transcrire sous la forme d'un tableau.
 *
 * @param pathname chemin d'acces au fichier que l'on veut lire
 * @param line_buffer_size taille allouée à la chaine de caractère pour contenir une ligne du fichier
 * @param coll_num nombre de colonnes dans le tableau de sortie
 * @param line_num nombre de lignes dans le tableau de sortie
 * @param output tableau contenant les données du tableau à l'exception du nom des colonnes
 *
 * Cette fonction fait appel à la librairie <stdio.h>
 */
void csv_file_reader(const char *pathname, int line_buffer_size, int coll_num, int line_num, double** output);

#endif //IDI_DAO_H
