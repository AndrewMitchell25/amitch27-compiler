#include "encoder.h"

int string_decode( const char *es, char *s ) {
    if(*es != '"') {
        return 0;
    }

    es++;

    while(*es != 0) {
        if(*es < 32 || *es > 126) {
            return 0;
        }

        if(*es == '\\') {
            es++;
            switch(*es) {
                case 'a': //bell
                    *s = '\a';
                    break;
                case 'b': //backspace
                    *s = '\b';
                    break;
                case 'e': //escape
                    *s = '\e';
                    break;
                case 'f': //form feed (clear)
                    *s = '\f';
                    break;
                case 'n': //new line
                    *s = '\n';
                    break;
                case 'r': //return
                    *s = '\r';
                    break;
                case 't': //tab
                    *s = '\t';
                    break;
                case 'v': //vertical tab
                    *s = '\v';
                    break;
                case '\\': //backslash
                    *s = '\\';
                    break;
                case '\'': //single quote
                    *s = '\'';
                    break;
                case '\"': //double quote
                    *s = '\"';
                    break;
                /*TODO: NEED TO FIGURE OUT HEXADECIMAL ONE
                
                case '0':
                    es++;
                    if(*es == 'x') {
                        es++;
                        HERE READ IN THE TWO HEX VALUES
                        *s =  '\x';
                    }

                    return 0;
                    
                */                
                default:
                    fprintf(stderr, "Invalid escape code\n");
                    return 0;
            }
        }


    }

    return 1;
}

int string_encode( const char *s, char *es ) {


    return 1;
}