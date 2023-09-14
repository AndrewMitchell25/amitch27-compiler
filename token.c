#include "token.h"
#include <stdio.h>

int tokenToName(int t, char *name){
    switch(t){
        case LEFT_PARENTHESES:
            sprintf(name, "LEFT_PARENTHESES");
            break;
        case RIGHT_PARENTHESES:
            sprintf(name, "RIGHT_PARENTHESES");
            break;
        case LEFT_BRACKET:
            sprintf(name, "LEFT_BRACKET");
            break;
        case RIGHT_BRACKET:
            sprintf(name, "RIGHT_BRACKET");
            break;
        case LEFT_CURLY_BRACKET:
            sprintf(name, "LEFT_CURLY_BRACKET");
            break;
        case RIGHT_CURLY_BRACKET:
            sprintf(name, "RIGHT_CURLY_BRACKET");
            break;
        case COMMA:
            sprintf(name, "COMMA");
            break;
        case SEMICOLON:
            sprintf(name, "SEMICOLON");
            break;
        case COLON:
            sprintf(name, "COLON");
            break;
        case PLUS_PLUS:
            sprintf(name, "PLUS_PLUS");
            break;
        case MINUS_MINUS:
            sprintf(name, "MINUS_MINUS");
            break;
        case EQUALS_EQUALS:
            sprintf(name, "EQUALS_EQUALS");
            break;
        case NOT_EQUALS:
            sprintf(name, "NOT_EQUALS");
            break;
        case NOT:
            sprintf(name, "NOT");
            break;
        case PLUS:
            sprintf(name, "PLUS");
            break;
        case MINUS:
            sprintf(name, "MINUS");
            break;
        case DIVIDE:
            sprintf(name, "DIVIDE");
            break;
        case MULTIPLY:
            sprintf(name, "MULTIPLY");
            break;
        case MOD:
            sprintf(name, "MOD");
            break;
        case EXPONENT:
            sprintf(name, "EXPONENT");
            break;
        case EQUALS:
            sprintf(name, "EQUALS");
            break;
        case GREATER_EQUAL:
            sprintf(name, "GREATER_EQUAL");
            break;
        case LESS_EQUAL:
            sprintf(name, "LESS_EQUAL");
            break;
        case GREATER:
            sprintf(name, "GREATER");
            break;
        case LESS:
            sprintf(name, "LESS");
            break;
        case AND:
            sprintf(name, "AND");
            break;
        case OR:
            sprintf(name, "OR");
            break;
        case KW_ARRAY:
            sprintf(name, "KW_ARRAY");
            break;
        case KW_AUTO:
            sprintf(name, "KW_AUTO");
            break;
        case KW_BOOLEAN:
            sprintf(name, "KW_BOOLEAN");
            break;
        case KW_CHAR:
            sprintf(name, "KW_CHAR");
            break;
        case KW_ELSE:
            sprintf(name, "KW_ELSE");
            break;
        case KW_FALSE:
            sprintf(name, "KW_FALSE");
            break;
        case KW_FLOAT:
            sprintf(name, "KW_FLOAT");
            break;
        case KW_FOR:
            sprintf(name, "KW_FOR");
            break;
        case KW_FUNCTION:
            sprintf(name, "KW_FUNCTION");
            break;
        case KW_IF:
            sprintf(name, "KW_IF");
            break;
        case KW_INTEGER:
            sprintf(name, "KW_INTEGER");
            break;
        case KW_PRINT:
            sprintf(name, "KW_PRINT");
            break;
        case KW_RETURN:
            sprintf(name, "KW_RETURN");
            break;
        case KW_STRING:
            sprintf(name, "KW_STRING");
            break;
        case KW_TRUE:
            sprintf(name, "KW_TRUE");
            break;
        case KW_VOID:
            sprintf(name, "KW_VOID");
            break;
        case KW_WHILE:
            sprintf(name, "KW_WHILE");
            break;
        case IDENTIFIER:
            sprintf(name, "IDENTIFIER");
            break;
        case COMMENT:
            sprintf(name, "COMMENT");
            break;
        case INTEGER:
            sprintf(name, "INTEGER");
            break;
        case FLOAT:
            sprintf(name, "FLOAT");
            break;
        case CHAR:
            sprintf(name, "CHAR");
            break;
        case STRING:
            sprintf(name, "STRING");
            break;
        case ERROR:
            sprintf(name, "ERROR");
            break;
        default:
            fprintf(stderr, "Error: Unrecognized Token - %d\n", t);
            return 0;
    }
    return 1;
}