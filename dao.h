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

void test();//todo remove securely

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

/**todo*/
int csv_file_reader(const char *pathname, int coll, int line, double** output);

/**todo*/
int csv_file_reader2(const char *pathname, int line_buffer_size, int coll, int line, double** output, char** category);

/**
 * enumere sous la forme d'un tableau a double entrees le nom des fichiers dans leur dossiers pour un path voulu. [dossier][fichier]
 *
 * @param path chemin racine pour tous les dossiers
 * @param max_number_of_directory nombre maximum de dossiers à rechercher
 * @param max_number_of_files nombre maximum de fichiers dans lesquels rechercher
 * @param output tableau de sortie
 * @todo
 */
void dir_list(char* path, int max_number_of_directory, int max_number_of_files, char output[max_number_of_directory][max_number_of_files][MAX_FILE_PATH_LENGTH]);

/*todo*/
void write_title_csv(char const *fileName,char const *title_coll);

/** todo
 * Cette fonction permets d'écrire dans un fichier .csv les informations contenues dans un tableau d'entiers plaçé en paramètre
 *
 * @param fileName Nom du fichier ou écire les données
 * @param title_coll titre des colonnes du fichier csv (utile pour comprendre à quoi corespondent les données)
 * @param coll_num nombre de colonnes du tableau contenant les données à inscrire
 * @param line_num nombre de lignes du tableau contenant les données à inscrire
 * @param intput tableau d'entier don't le contenu sera retranscri dans le fichier csv qui porte le nom filename
 *
 * Cette fonction fait appel à la librairie <stdio.h>
 */
void write_csv(char const *fileName, int line_num,double intput[line_num], char category[4]);

#endif //IDI_DAO_H
