%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"

%}

%option yylineno
%option noyywrap
firstDigit   		([1-9])
Digit           (firstDigit[0-9]*)
letter  		([a-zA-Z])
whitespace		([\t\n ])
quote           (\")
%%
void                        return VOID;
int                         return INT;
byte                        return BYTE;
b                           return B;
bool                        return BOOL;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
if                          return IF;
else                        return ELSE;
while                       return WHILE;
break                       return BREAK;
continue                    return CONTINUE;
;                           return SC;
,                           return COMMA;
"("                         return LPAREN;
")"                         return RPAREN;
"{"                         return LBRACE;
"}"                         return RBRACE;
"=="|"!="|"<"|">"|"<="|">=" return RELOP;
"="                         return ASSIGN;
"+"|"-"|"*"|"/"             return BINOP;
"//"                        return COMMENT; //TODO::need to fix this
{firstDigit}[0-9]*|[0]      return NUM;
{letter}[0-9a-zA-Z]*        return ID;
{quote}{quote}                     return STRING;
{whitespace}				;
.                       	printf("Lex doesn't know what that is!\n"); //TODO::need to fix this
%%