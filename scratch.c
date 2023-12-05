#include <stdio.h>
#include <stdlib.h>
#include "scratch.h"

char * name[7] = {"%rbx", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};
int inuse[7] = {0, 0, 0, 0, 0, 0, 0};

int scratch_alloc(){
    int i = 0;
    for(i = 0; i < 7; i++) {
        if(inuse[i] == 0) {
            break;
        }
    }
    if(i == 7) {
        printf("allocation error: no more free registers.\n");
        exit(EXIT_FAILURE);
    }
    inuse[i] = 1;
    return i;
}
void scratch_free( int r ){
    inuse[r] = 0;
}
const char * scratch_name( int r ){
    return name[r];
}