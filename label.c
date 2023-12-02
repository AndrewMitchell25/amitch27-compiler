#include <stdio.h>
#include <stdlib.h>
#include "label.h"

int counter = 0;

int label_create() {
    counter++;
    return counter;
}

const char * label_name( int label ){
    char * name = malloc(sizeof(char) * 10);
    sprintf(name, ".L%d", label);
    return name;
}