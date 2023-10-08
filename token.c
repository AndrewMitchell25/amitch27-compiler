#include "token2.h"
#include <stdio.h>

int tokenToName(int t, char *name){
    switch(t){
        case TOKEN_LEFT_PARENTHESES:
            sprintf(name, "TOKEN_LEFT_PARENTHESES");
            break;
        case TOKEN_RIGHT_PARENTHESES:
            sprintf(name, "TOKEN_RIGHT_PARENTHESES");
            break;
        case TOKEN_LEFT_BRACKET:
            sprintf(name, "TOKEN_LEFT_BRACKET");
            break;
        case TOKEN_RIGHT_BRACKET:
            sprintf(name, "TOKEN_RIGHT_BRACKET");
            break;
        case TOKEN_LEFT_CURLY_BRACKET:
            sprintf(name, "TOKEN_LEFT_CURLY_BRACKET");
            break;
        case TOKEN_RIGHT_CURLY_BRACKET:
            sprintf(name, "TOKEN_RIGHT_CURLY_BRACKET");
            break;
        case TOKEN_COMMA:
            sprintf(name, "TOKEN_COMMA");
            break;
        case TOKEN_SEMICOLON:
            sprintf(name, "TOKEN_SEMICOLON");
            break;
        case TOKEN_COLON:
            sprintf(name, "TOKEN_COLON");
            break;
        case TOKEN_PLUS_PLUS:
            sprintf(name, "TOKEN_PLUS_PLUS");
            break;
        case TOKEN_MINUS_MINUS:
            sprintf(name, "TOKEN_MINUS_MINUS");
            break;
        case TOKEN_EQUALS_EQUALS:
            sprintf(name, "TOKEN_EQUALS_EQUALS");
            break;
        case TOKEN_NOT_EQUALS:
            sprintf(name, "TOKEN_NOT_EQUALS");
            break;
        case TOKEN_NOT:
            sprintf(name, "TOKEN_NOT");
            break;
        case TOKEN_PLUS:
            sprintf(name, "TOKEN_PLUS");
            break;
        case TOKEN_MINUS:
            sprintf(name, "TOKEN_MINUS");
            break;
        case TOKEN_DIVIDE:
            sprintf(name, "TOKEN_DIVIDE");
            break;
        case TOKEN_MULTIPLY:
            sprintf(name, "TOKEN_MULTIPLY");
            break;
        case TOKEN_MOD:
            sprintf(name, "TOKEN_MOD");
            break;
        case TOKEN_EXPONENT:
            sprintf(name, "TOKEN_EXPONENT");
            break;
        case TOKEN_EQUALS:
            sprintf(name, "TOKEN_EQUALS");
            break;
        case TOKEN_GREATER_EQUAL:
            sprintf(name, "TOKEN_GREATER_EQUAL");
            break;
        case TOKEN_LESS_EQUAL:
            sprintf(name, "TOKEN_LESS_EQUAL");
            break;
        case TOKEN_GREATER:
            sprintf(name, "TOKEN_GREATER");
            break;
        case TOKEN_LESS:
            sprintf(name, "TOKEN_LESS");
            break;
        case TOKEN_AND:
            sprintf(name, "TOKEN_AND");
            break;
        case TOKEN_OR:
            sprintf(name, "TOKEN_OR");
            break;
        case TOKEN_KW_ARRAY:
            sprintf(name, "TOKEN_KW_ARRAY");
            break;
        case TOKEN_KW_AUTO:
            sprintf(name, "TOKEN_KW_AUTO");
            break;
        case TOKEN_KW_BOOLEAN:
            sprintf(name, "TOKEN_KW_BOOLEAN");
            break;
        case TOKEN_KW_CHAR:
            sprintf(name, "TOKEN_KW_CHAR");
            break;
        case TOKEN_KW_ELSE:
            sprintf(name, "TOKEN_KW_ELSE");
            break;
        case TOKEN_KW_FALSE:
            sprintf(name, "TOKEN_KW_FALSE");
            break;
        case TOKEN_KW_FLOAT:
            sprintf(name, "TOKEN_KW_FLOAT");
            break;
        case TOKEN_KW_FOR:
            sprintf(name, "TOKEN_KW_FOR");
            break;
        case TOKEN_KW_FUNCTION:
            sprintf(name, "TOKEN_KW_FUNCTION");
            break;
        case TOKEN_KW_IF:
            sprintf(name, "TOKEN_KW_IF");
            break;
        case TOKEN_KW_INTEGER:
            sprintf(name, "TOKEN_KW_INTEGER");
            break;
        case TOKEN_KW_PRINT:
            sprintf(name, "TOKEN_KW_PRINT");
            break;
        case TOKEN_KW_RETURN:
            sprintf(name, "TOKEN_KW_RETURN");
            break;
        case TOKEN_KW_STRING:
            sprintf(name, "TOKEN_KW_STRING");
            break;
        case TOKEN_KW_TRUE:
            sprintf(name, "TOKEN_KW_TRUE");
            break;
        case TOKEN_KW_VOID:
            sprintf(name, "TOKEN_KW_VOID");
            break;
        case TOKEN_KW_WHILE:
            sprintf(name, "TOKEN_KW_WHILE");
            break;
        case TOKEN_IDENTIFIER:
            sprintf(name, "TOKEN_IDENTIFIER");
            break;
        case TOKEN_INTEGER:
            sprintf(name, "TOKEN_INTEGER");
            break;
        case TOKEN_FLOAT:
            sprintf(name, "TOKEN_FLOAT");
            break;
        case TOKEN_CHAR:
            sprintf(name, "TOKEN_CHAR");
            break;
        case TOKEN_STRING:
            sprintf(name, "TOKEN_STRING");
            break;
        case TOKEN_ERROR:
            sprintf(name, "TOKEN_ERROR");
            break;
        default:
            fprintf(stderr, "Error: Unrecognized Token - %d\n", t);
            return 0;
    }
    return 1;
}