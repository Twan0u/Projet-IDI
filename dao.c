#include "dao.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#define MAX_LINE_BUFFER_SIZE 65000

/**
 * Cette fonction transforme une chaine de charactères en un double.
 *
 * @param input : chaine de charactères destinée à être convertie en nombre a virgule flotatnte (double)
 * @return une valeur réele (double) si le nombre est correct, 0 si la chaine de charactère est nulle, vide ou invalide
 *
 * @see <stdlib.h>
 *
 * @note on considère que strtod est exécutée en O(1)
 *
 * Complexité temporelle : O(1)
 * Complexité memoire : O(1)
 *
 **/
double convert_string_to_double(char* input) {
    if (input == NULL) {
        return 0.0;
    }
    return strtod(input, NULL);
}

/**
 * Cette fonction permets de transformer une ligne(String) issue d'un fichier csv (ou chaque élément est séparé par une virgule) en un tableau de Réels
 *
 * @param line chaine de caractère correspondant à une ligne d'un fichier csv (les éléments sont des nombres réels séparés entre eux par des virgules)
 * @param output_length taille du tableau à renvoyer (nombre d'éléments à récupérer au sein de la ligne)
 * @param output tableau de nombres réels utilisés pour renvoyer le résultat de la fonction (taille: output_length)
 *
 * @see <string.h>
 *
 * @note fait appel à la fonction convert_string_to_double
 *
 * Complexité temporelle : O(n)
 * Complexité memoire : O(n)
 *
 */
void csv_line_spliter(char* line,int output_length, double* output){
    char* next_token = NULL;
    for(int i=0; i<output_length ;i++){
        output[i] = convert_string_to_double(strtok_r(line,",",&next_token));
        line=next_token;
    }
}

/**
 * Cette fonction permets de récupérer des nombres réels contenus dans un fichier csv et de les transcrire sous la forme d'un tableau de réels.
 *
 * @note important : la première ligne du fichier csv n'est pas prise en compte (Elle est réservée aux nom des catégories des données du fichier)
 * @note la taille maximale du nombre de lettres contenues dans une ligne d'un fichier lue ne doit pas dépasser la variable MAX_LINE_BUFFER_SIZE
 *
 * @param pathname chemin d'acces au fichier csv que l'on veut lire
 * @param coll_num nombre de colonnes dans le tableau de sortie
 * @param line_num nombre de lignes dans le tableau de sortie
 * @param output tableau contenant les données du tableau à l'exception du nom des colonnes
 * @return un code d'erreur expliquée ci-dessous
 *
 * Les Codes D'Erreur :
 *      * 0 est retourné en cas de réussite du programme
 *      * 1 signifie que le programme n'est pas parvenu à ouvir correctement le fichier
 *
 * @see <stdio.h>
 * @see MAX_LINE_BUFFER_SIZE
 *
 * @note fait appel à la fonction csv_line_spliter
 *
 * Complexité temporelle : O(n)
 * Complexité memoire : O(n)
 *
 */
int csv_file_reader(const char *pathname, int coll, int line, double** output){
    /* ouverture du fichier*/
    FILE *fp = fopen(pathname, "r");
    if (!fp){
        return 1; // code erreur d'ouverture d'un fichier
    }
    /*fin ouverture du fichier*/

    //todo Créer une erreur en cas de taille de ligne d'un fichier trop grande pour le buffer de taille MAX_LINE_BUFFER_SIZE

    char buf[MAX_LINE_BUFFER_SIZE]; //tableau de caractères représentant une ligne d'un fichier

    int line_count = 0;
    fgets(buf, MAX_LINE_BUFFER_SIZE, fp); // ignore la première ligne d'un fichier (titre des colonnes)

    while (fgets(buf, MAX_LINE_BUFFER_SIZE, fp) && (line_count < line)) {
        csv_line_spliter(buf,coll,output[line_count]);
        line_count++;
    }

    fclose(fp); //fermeture du fichier
    return 0; //code en cas de réussite
}

//todo idem que csv line spliter mais retire category en plus
void csv_line_spliter2(char* line,int output_length, double* output, char* category){
    char* next_token = NULL;
    for(int i=0; i<output_length ;i++) {
        output[i] = convert_string_to_double(strtok_r(line, ",", &next_token));
        line = next_token;
    }
    strcpy(category,line);
}

// todo
int csv_file_reader2(const char *pathname, int line_buffer_size, int coll, int line, double** output, char** category){
    /* ouverture du fichier*/
    FILE *fp = fopen(pathname, "r"); //ouverture du fichier
    if (!fp){
        return 1; // code erreur d'ouverture de fichier
    }/*fin ouverture du fichier*/
    //todo Créer une erreur en cas de taille de ligne d'un fichier trop grande pour le buffer de taille MAX_LINE_BUFFER_SIZE

    char buf[line_buffer_size]; //tableau de charactères représentant une ligne d'un fichier

    int line_count = 0;
    fgets(buf, line_buffer_size, fp); // prends en compte la première ligne (titre des colonnes)
    while (fgets(buf, line_buffer_size, fp) && (line_count < line)) {
        csv_line_spliter2(buf,coll,output[line_count],category[line_count]);
        line_count++;
    }
    fclose(fp); //fermeture du fichier
    return 0;   //code en cas de réussite
}


/**
 * todo
 */
void write_title_csv(char const *fileName,char const *title_coll){
    FILE* file = fopen(fileName,"w");
    if(file==NULL){
        fprintf(stderr, "Can't write in file :  %s\n", fileName);
        return;
    }
    fprintf(file,"%s\n", title_coll);
    fclose(file);
}
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
void write_csv(char const *fileName, int line_num,double intput[line_num], char category[4]){
    FILE* file = fopen(fileName,"a");

    if(file==NULL){
        fprintf(stderr, "Can't write in file :  %s\n", fileName);
        return;
    }

    int i=0;
    while(i<line_num){
            fprintf(file,"%lf,", intput[i]);
            i++;
    }
    fprintf(file,"%s\n", category);
    fclose(file);
}

/**
 * Concatene un path avec un sub path sous la forme root/sub_path en ajoutant le '/' les séparant
 * @param root première partie du chemin output à retrourner
 * @param sub_path seconde partie du path
 * @param output valeur de retour du path final concatene sous la forme root/sub_path
 *
 * @see <string.h>
 *
 * Complexité temporelle : O(n)
 * Complexité memoire : O(n)
 *
 */
void path_concatenation(char* root, char* sub_path, char output[MAX_FILE_PATH_LENGTH]){
    strcat(output,root); // path
    strcat(output,"/"); // path/
    strcat(output,sub_path);// path/filename.extension
}

/**
 * Cette fonction liste tous les fichiers contenus dans un directory à l'exception de . et ..
 * @param path_of_dir chemin du dossier dans lequel sont situés les fichiers
 * @param number_of_files_max nombre maximum de fichiers contenus dans chaque dossier et taille de output
 * @param output tableau qui contiendra les noms des fichiers dans le dossier à l'adresse path_of_dir
 *
 * @see <dirent.h>
 *
 */
void file_list(char* path_of_dir,int number_of_files_max, char output[number_of_files_max][MAX_FILE_PATH_LENGTH]){
    struct dirent *dir;
    DIR *d = opendir(path_of_dir);
    if (d){
        for (int i=0; (i<number_of_files_max+2) && ((dir = readdir(d)) != NULL);i++){
            if(i>1){ // pour éviter de se retrouver avec . et .. dans le tableau
                char path_of_current_file[MAX_FILE_PATH_LENGTH];
                strcpy(path_of_current_file,"");// reset path string

                path_concatenation(path_of_dir, dir->d_name, path_of_current_file);

                strcpy(output[i-2],path_of_current_file);
                path_of_current_file[0]='\0';
            }
        }
        closedir(d);
    }
}

/**
 * enumere sous la forme d'un tableau a double entrees le nom des fichiers dans leur dossiers pour un path voulu. [dossier][fichier]
 *
 * @param path chemin racine pour tous les dossiers
 * @param max_number_of_directory nombre maximum de dossiers à rechercher
 * @param max_number_of_files nombre maximum de fichiers dans lesquels rechercher
 * @param output tableau de sortie
 * @todo
 */
void dir_list(char* path, int max_number_of_directory, int max_number_of_files, char output[max_number_of_directory][max_number_of_files][MAX_FILE_PATH_LENGTH]){
    char current_dir[MAX_FILE_PATH_LENGTH]; //le directory utilisé actuellement par le programme

    struct dirent *dir;
    DIR *d = opendir(path);

    if (d){
        for (int i=0; (i<(max_number_of_directory+2))&&((dir = readdir(d)) != NULL);i++){
            if (i > 1) {// cas de . et ..
               strcpy(current_dir,"");

                char temp[max_number_of_files][MAX_FILE_PATH_LENGTH];

                path_concatenation(path,dir->d_name,current_dir);
                file_list(current_dir,max_number_of_files,temp);

                for (int j = 0; j<max_number_of_files; j++){
                    strcpy(output[i-2][j],temp[j]);
                }
            }
        }
        closedir(d);
    }
}

/**
 * Reconaissance d'une activité sur base de son path ( chemin ). Il faut impérativemnt que le chemin soit construit comme suit : ./data/ACT_NUM/sub_NUM.csv le programme renverra ACT
 *
 * @param path chemin du fichier './data/ACT_NUM/sub_NUM.csv'
 * @param category ACTIVITE (ACT) contenue dans le path. tableau de char de taille 4
 *
 * Complexite temporelle : O(1)
 * Complexité memoire : O(1)
 *
 */
void activity_recogniser(char* path, char category[4]){
    char* p = path+7;
    strncpy(category,p, 3);
    category[4]='\0';
}

