#include <stdio.h>
#include "encoder.h"
#include "token.h"

enum process {
    encode,
    scan
};

int main(int argc, char *argv[]) {
    int i = 1;
    enum process curr_process;
    
    while(i < argc && argv[i][0] == '-') {
        if(!strcmp(argv[i], "--encode")) {
            curr_process = encode;
        }
        if(!strcmp(argv[i], "--scan")) {
            curr_process = scan;
        }
        i++;
    }

    if(curr_process == encode){
        FILE* fp = fopen(argv[i], "r");
        if(!fp) {
            fprintf(stderr, "Can't open file %s\n", argv[i]);
            return 1;
        }
        char s[255];
        char es[255];
        fgets(es, 255, fp);
        fclose(fp);
        if(! string_decode(es, s)) {
            fprintf(stderr, "Decode failed - %s\n", es);
            return 1;
        }

        printf("%s\n", s);

        if(! string_encode(s, es)) {
            fprintf(stderr, "Encode failed - %s\n", s);
            return 1;
        }

        printf("%s\n", es);
        return 0;

    } else if (curr_process == scan) {
        extern FILE* yyin;
        extern int yylex();
        extern char yytext[];

        FILE* fp = fopen(argv[i], "r");
        if(!fp) {
            fprintf(stderr, "Can't open file %s\n", argv[i]);
            return 1;
        }

        yyin = fp;
        //yyin = stdin;
        int token;
        while(1){
            token = yylex();
            if(token == ERROR) {
                fprintf(stderr, "Scan Error\n");
                return 1;
            }

            if(token == EOF) {
                break;
            }

            char name[100];
            tokenToName(token, name);
            
            if(token >= 300){
                printf("%s %s\n", name, yytext);
            } else {
                printf("%s\n", name);
            }
        }
        
        fclose(fp);

        return 0;
    }

    return 0;
}