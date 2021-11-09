%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"
char global_str[1024];
int strIndex =0;
void concat(char* str){
    //printf("%lu",sizeof(str));
    //printf("%s",str);
    for (int i=0;i<strlen(str);i++){
        //printf("in loopp");
        global_str[strIndex] = str[i];
        strIndex++;
    }
};
char* hex2char(char* hex){
    int hex_num = (int)strtol(hex, NULL, 16);
    char* chr;
    sprintf(chr,"%c",hex_num);
    return chr;
}
%}

%option yylineno
%option noyywrap
firstDigit   		([1-9])
Digit           (firstDigit[0-9]*)
letter  		([a-zA-Z])
whitespace		([\t\n ])
space           ( )
quote           (\")
backslash       (\\)
allCharacters   ([!-~ ])
allStringCharacters ([ !#-\[\]-~])
%x QUOTE
%x BACKSLASH
%x HEX
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
"//"({allCharacters}*) return COMMENT; //TODO::need to fix this
{firstDigit}[0-9]*|[0]      return NUM;
{letter}[0-9a-zA-Z]*        return ID;
{quote}                     BEGIN(QUOTE); //todo::need to finish this
<QUOTE>{allStringCharacters}+ concat(yytext);
<QUOTE>{backslash}          BEGIN(BACKSLASH);
<QUOTE>\n                   printf("Error unclosed string\n");exit(0);
<BACKSLASH>{backslash}      concat((char*)"\\"); BEGIN(QUOTE);
<BACKSLASH>{quote}          concat((char*)"\""); BEGIN(QUOTE);
<BACKSLASH>n                concat((char*)"\n"); BEGIN(QUOTE);
<BACKSLASH>r                concat((char*)"\r"); BEGIN(QUOTE);
<BACKSLASH>t                concat((char*)"\t"); BEGIN(QUOTE);
<BACKSLASH>0                concat((char*)"\0"); BEGIN(QUOTE);
<BACKSLASH>x                BEGIN(HEX);
<BACKSLASH>.                printf("Error undefined escape sequence %s\n",yytext);exit(0);
<HEX>([0-7][0-9a-f])        {printf("");concat(hex2char(yytext)); BEGIN(QUOTE);}
<HEX>{quote}                printf("Error undefined escape sequence x\n");exit(0);
<HEX>([8-9a-f][0-9a-f])|[0-7] printf("Error undefined escape sequence x%s\n",yytext);exit(0);
<QUOTE>{quote}              BEGIN(INITIAL);return STRING;
<QUOTE>.                    printf("Error unclosed string\n");exit(0);
{whitespace}				;
.                       	printf("Error %s\n",yytext);exit(0); //TODO::need to fix this
%%