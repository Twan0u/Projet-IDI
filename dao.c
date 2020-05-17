
#include "dao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_DIRECTORY 15
#define MAX_FILES_PER_DIR 24


/**
 * Cette fonction transforme une chaine de charactères en un entier. si la chaine est nulle ou vide, cette fonction retourne 0.
 * @param input : chaine de charactères destinée à être convertie en nombre entier
 * @return une valeur entiere (int) si le nombre est correct, 0 si la chaine de charactère est nulle, vide ou invalide
 *
 * Cette fonction fait appel à la librairie <stdlib.h>
 **/
int convert_to_int(char* input){
    if (input==NULL){
        return 0;
    }
    int output = atoi(input);
    return output;
}

/**
 * Cette fonction transforme une chaine de charactères en un double. si la chaine est nulle ou vide, cette fonction retourne 0.
 * @param input : chaine de charactères destinée à être convertie en nombre a virgule flotatnte (double)
 * @return une valeur réele (double) si le nombre est correct, 0 si la chaine de charactère est nulle, vide ou invalide
 *
 * Cette fonction fait appel à la librairie <stdlib.h>
 **/
double convert_to_double(char* input){
    if (input==NULL){
        return 0;
    }
    double output = strtod(input,NULL);
    return output;
}

/**
 * Cette fonction permets de transformer une ligne de charactères issu d'un fichier csv en un tableau de doubles
 *
 * @param line chaine de caractère correspondant à une ligne d'un fichier csv (les éléments sont des nombres réels séparés entre eux par des virgules)
 * @param output_length taille du tableau à renvoyer
 * @param output tableau de nombres réels utilisés pour renvoyer le résultat de la fonction
 *
 * Cette fonction fait appel à la librairie <string.h>
 */
void csv_line_spliter(char* line,int output_length, double* output){
    char* next_token = NULL;
    for(int i=0;i<output_length;i++){
        output[i]=(double) convert_to_double(strtok_r(line,",",&next_token));
        line=next_token;
    }
}

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
void csv_file_reader(const char *pathname, int line_buffer_size, int coll_num, int line_num, double** output){
    FILE *fp = fopen(pathname, "r"); //ouverture du fichier

    if (!fp){
        fprintf(stderr, "Can't open file %s\n", pathname);
        return;
    }

    char buf[line_buffer_size];
    int line_count = 0;

    while (fgets(buf, line_buffer_size, fp) && (line_count < line_num)) {
        if (line_count == 0) { // ligne contenant le titre des colonnes
            line_count++;
            continue;
        }
        csv_line_spliter(buf,coll_num,output[line_count-1]);

        line_count++;
    }
    fclose(fp);
}

/**
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
void write_csv(char const *fileName,char const *title_coll, int coll_num, int line_num,double intput[line_num][coll_num]){
    FILE* file = fopen(fileName,"w");
    if(file==NULL){
        fprintf(stderr, "Can't write in file :  %s\n", fileName);
        return;
    }
    fprintf(file,"%s\n", title_coll);
    for(int i = 0;i<line_num;i++){
        for(int j = 0;j<coll_num-1;j++){
            fprintf(file,"%lf,", intput[i][j]);
        }
        fprintf(file,"%lf\n", intput[i][coll_num-1]);
    }
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
                printf("%s",path);
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

void test() {
   /* char data[MAX_DIRECTORY][MAX_FILES_PER_DIR][MAX_FILE_PATH_LENGTH];

    for (int i=0;i<MAX_DIRECTORY;i++){
        for(int j=0;j<MAX_FILES_PER_DIR;j++){
            data[i][j][0]= '\0';
        }
    }

    dir_list("./data",MAX_DIRECTORY,MAX_FILES_PER_DIR,data);

    for (int i=0;i<MAX_DIRECTORY;i++){
        for(int j=0;j<MAX_FILES_PER_DIR;j++){
            printf("%s --",data[i][j]);
        }
        printf("\n");
    }

    char category[4];
    activity_recogniser(data[0][1],category);
    printf("%s",category);*/
}
