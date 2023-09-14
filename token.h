#ifndef TOKEN_H
#define TOKEN_H
#define LEFT_PARENTHESES 256
#define RIGHT_PARENTHESES 257
#define LEFT_BRACKET 258
#define RIGHT_BRACKET 259
#define LEFT_CURLY_BRACKET 260
#define RIGHT_CURLY_BRACKET 261
#define COMMA 262
#define SEMICOLON 263
#define COLON 264
#define PLUS_PLUS 265
#define MINUS_MINUS 266
#define EQUALS_EQUALS 267
#define NOT_EQUALS 268
#define NOT 269
#define PLUS 270
#define MINUS 271
#define DIVIDE 272
#define MULTIPLY 273
#define MOD 274
#define EXPONENT 275
#define EQUALS 276
#define GREATER_EQUAL 277 
#define LESS_EQUAL 278
#define GREATER 279
#define LESS 280
#define AND 281
#define OR 282
#define KW_ARRAY 283
#define KW_AUTO 284
#define KW_BOOLEAN 285
#define KW_CHAR 286
#define KW_ELSE 287
#define KW_FALSE 288
#define KW_FLOAT 289
#define KW_FOR 290
#define KW_FUNCTION 291
#define KW_IF 292
#define KW_INTEGER 293
#define KW_PRINT 294
#define KW_RETURN 295
#define KW_STRING 296
#define KW_TRUE 297
#define KW_VOID 298
#define KW_WHILE 299
#define IDENTIFIER 300
#define COMMENT 301
#define INTEGER 302
#define FLOAT 303
#define CHAR 304
#define STRING 305
#define ERROR 306
#endif

int tokenToName(int t, char *name);