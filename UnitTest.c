//
// Created by Antoine Lambert on 31-03-20.
//

#include "UnitTest.h"
#include <stdbool.h>
#include <stdio.h>

void error_assert(bool test, char *message, int* errorCounter) {
    if(!test){
        printf("\t\t* %s\n", message);
        *errorCounter = *errorCounter + 1; // add 1 to the error counter
    }
}