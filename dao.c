//
// Created by Antoine Lambert on 20-03-20.
//

#include "dao.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <dirent.h>
#define MAX_FILE_PATH_LENGTH 100

void test(){
    printf("DAO Connecté\n");
}

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
 * Cette fonction permets de transformer une ligne de charactères issu d'un fichier csv en un tableau d'entiers
 *
 * @param line chaine de caractère correspondant à une ligne d'un fichier csv (les éléments sont des nombres entiers séparés entre eux par des virgules)
 * @param output_length taille du tableau à renvoyer
 * @param output tableau d'entier utilisé pour renvoyer le résultat de la fonction
 *
 * Cette fonction fait appel à la librairie <string.h>
 */
void csv_line_spliter(char* line,int output_length, int output[output_length]){
    char* next_token = NULL;
    for(int i=0;i<output_length;i++){
        output[i]=(int) convert_to_int(strtok_r(line,",",&next_token));
        line=next_token;
    }
}

/**
 * Cette fonction permets de récupérer des nombres entiers contenus dans un fichier csv et de les transcrire sous la forme d'un tableau.
 *
 * @param pathname chemin d'acces au fichier que l'on veut lire
 * @param line_buffer_size taille allouée à la chaine de caractère pour contenir une ligne du fichier
 * @param coll_num nombre de colonnes dans le tableau de sortie
 * @param line_num nombre de lignes dans le tableau de sortie
 * @param output tableau contenant les données du tableau à l'exception du nom des colonnes
 *
 * Cette fonction fait appel à la librairie <stdio.h>
 */
void csv_file_reader(const char *pathname,int line_buffer_size, int coll_num, int line_num,int output[line_num][coll_num]){
    FILE *fp = fopen(pathname, "r");
    if (!fp){
        fprintf(stderr, "Can't open file %s\n", pathname);
        return;
    }

    char buf[line_buffer_size];
    int line_count = 0;

    while (fgets(buf, line_buffer_size, fp) && (line_count < line_num)) {
        if (line_count == 0) {
            line_count++;
            continue;
        }

        int line[coll_num];
        csv_line_spliter(buf,coll_num,line);

        for(int i=0;i<coll_num;i++) {
            output[line_count-1][i]=line[i];
        }
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
void write_csv(char const *fileName,char const *title_coll, int coll_num, int line_num,int intput[line_num][coll_num]){
    FILE* file = fopen(fileName,"w");
    if(file==NULL){
        fprintf(stderr, "Can't write in file :  %s\n", fileName);
        return;
    }
    fprintf(file,"%s\n", title_coll);
    for(int i = 0;i<line_num;i++){
        for(int j = 0;j<coll_num-1;j++){
            fprintf(file,"%d,", intput[i][j]);
        }
        fprintf(file,"%d\n", intput[i][coll_num-1]);
    }
    fclose(file);
}

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
 * cette fonction Cette fonction fait appel à la librairie <dirent.h>
 */
void file_list(char* path_of_dir,int number_of_files_max, char output[number_of_files_max][MAX_FILE_PATH_LENGTH]){
    struct dirent *dir;
    DIR *d = opendir(path_of_dir);
    if (d){
        for (int i=0; (i<number_of_files_max+2) && ((dir = readdir(d)) != NULL);i++){
            if(i>1){ // pour éviter de se retrouver avec . et .. dans le tableau
                char path_of_current_file[MAX_FILE_PATH_LENGTH];
                path_concatenation(path_of_dir, dir->d_name, path_of_current_file);

                printf("%s \n",path_of_current_file);

                strcpy(output[i-2],path_of_current_file);
                path_of_current_file[0]='\0';
            }
        }
        closedir(d);
    }
}
/**
 *
 * @param path
 * @param max_number_of_directory
 * @param max_number_of_files
 * @param output
 */
void dir_list(char* path, int max_number_of_directory, int max_number_of_files, char output[max_number_of_directory][max_number_of_files][MAX_FILE_PATH_LENGTH]){
    struct dirent *dir;
    DIR *d = opendir(path);
    if (d){
        for (int i=0; (i<(max_number_of_directory+2))&&((dir = readdir(d)) != NULL);i++){
            if (i > 1) {// cas de . et ..
                char current_dir[MAX_FILE_PATH_LENGTH]="";
                char temp[max_number_of_files][MAX_FILE_PATH_LENGTH]; // stocke temporairement le nom des fichiers contenu dans le directory current

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

void activity_recogniser(char* path, char category[4]){
    //TODO marche seulement avec ./data/ACT_NUM/sub_NUM et retire act
    char* p = path+7;
    strncpy(category,p, 3);
    category[4]='\0';
}

int main() {

    /*int doss = 2;
    int files = 2;

    char data[doss][files][MAX_FILE_PATH_LENGTH];

    for (int i=0;i<doss;i++){
        for(int j=0;j<files;j++){
            data[i][j][0]= '\0';
        }
    }

    dir_list("./data",doss,files,data);

    for (int i=0;i<doss;i++){
        for(int j=0;j<files;j++){
            printf("%s --",data[i][j]);
        }
        printf("\n");
    }*/

    char category[4];
    activity_recogniser("./data/Bit_1234/sub_12",category);
    printf("%s",category);

    return 0;
}
