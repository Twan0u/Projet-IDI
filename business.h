//
// Created by Antoine Lambert on 16-05-20.
//

#ifndef IDI_BUSINESS_H
#define IDI_BUSINESS_H

#include "dao.h"
#include "modele.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_DIRECTORY 15
#define MAX_FILES_PER_DIR 24
#define MAX_NB_PATTERN 6
#define MAX_VECTOR 1000
#define MAX_LENGTH_CATEGORY 4

int distanceEuclidienne(double* valeurs, double** patterns);
void modele_generation();
void test_dao();

#endif //IDI_BUSINESS_H
