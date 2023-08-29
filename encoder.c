#include "encoder.h"

int string_decode( const char *es, char *s ) {
    if(*es != '"') {
        fprintf(stderr, "String must begin with quotes.\n");
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
                case '0': //hex
                    es++;
                    if(*es == 'x') {
                        es++;
                        if((*es >= '0' && *es <= '9') || (*es >= 'A' && *es <= 'F') || (*es >= 'a' && *es <= 'f')) {
                            unsigned char c1 = *es;
                            es++;
                            if((*es >= '0' && *es <= '9') || (*es >= 'A' && *es <= 'F') || (*es >= 'a' && *es <= 'f')) {
                                unsigned char c2 = *es;
                                if(c1 <= '9') {
                                    c1 = c1 - '0';
                                } else if(c1 <= 'F') {
                                    c1 = c1 - 'A' + 10;
                                } else {
                                    c1 = c1 - 'a' + 10;
                                }

                                if(c2 <= '9') {
                                    c2 = c2 - '0';
                                } else if(c2 <= 'F') {
                                    c2 = c2 - 'A' + 10;
                                } else {
                                    c2 = c2 - 'a' + 10;
                                }
                                
                                unsigned char hex = c1<<4 | c2;
                                *s = hex;
                                break;
                            }
                        }
                    } 
                    fprintf(stderr, "Invalid hex.\n");
                    return 0;
                default:
                    fprintf(stderr, "Invalid escape code.\n");
                    return 0;
            }
        } else {
            if(*es == '\'') {
                fprintf(stderr, "Quotes must be escaped.\n");
                return 0;
            }

            if(*es == '\"') {
                es++;
                if(*es != 0) {
                    fprintf(stderr, "Quotes must be escaped.\n");
                    return 0;
                } else {
                    *s = 0;
                    return 1;
                }
            }

            *s = *es;
        }
        es++;
        s++;
    }

    fprintf(stderr, "String must end with quotes.\n");
    return 0;
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