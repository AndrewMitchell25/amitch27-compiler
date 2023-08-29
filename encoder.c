#include "encoder.h"

int string_decode( const char *es, char *s ) {
    if(*es != '"') {
        return 0;
    }

    es++;

    while(*es != 0) {
        if(*es < 32 || *es > 126) {
            fprintf(stderr, "Invalid character - %c\n", *es);
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
                    fprintf(stderr, "Invalid escape code.\n");
                    return 0;
            }
        } else {
            if(*es == '\"') {
                es++;
                if(*es != 0) {
                    fprintf(stderr, "Quotations must be escaped.\n");
                    return 0;
                } else {
                    continue;
                }
            }

            *s = *es;
        }
        es++;
        s++;
    }

    *s = 0;
    return 1;
}

int string_encode( const char *s, char *es ) {
    *es = '\"';
    es++;
    while(*s != 0) {
        switch(*s){
            case '\a':
                *es = '\\';
                es++;
                *es = 'a';
                break;
            case '\b':
                *es = '\\';
                es++;
                *es = 'b';
                break;
            case '\e':
                *es = '\\';
                es++;
                *es = 'e';
                break;
            case '\f':
                *es = '\\';
                es++;
                *es = 'f';
                break;
            case '\n':
                *es = '\\';
                es++;
                *es = 'n';
                break;
            case '\r':
                *es = '\\';
                es++;
                *es = 'r';
                break;
            case '\t':
                *es = '\\';
                es++;
                *es = 't';
                break;
            case '\v':
                *es = '\\';
                es++;
                *es = 'v';
                break;
            case '\\':
                *es = '\\';
                es++;
                *es = '\\';
                break;
            case '\'':
                *es = '\\';
                es++;
                *es = '\'';
                break;
            case '\"':
                *es = '\\';
                es++;
                *es = '\"';
                break;

            default:
                *es = *s;
                break;
        }

        es++;
        s++;
    }

    *es = '\"';
    es++;
    *es = 0;

    return 1;
}