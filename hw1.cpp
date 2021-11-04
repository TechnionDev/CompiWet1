#include <iostream>
#include "tokens.hpp"

using namespace std;

void showToken(const string& token){
    cout << to_string(yylineno) + " " + token + " " + yytext <<endl;
}
int main()
{
	int token = yylex();
    while(token) {
	// Your code here
       if (token == VOID){
            showToken("VOID");
        }
        else if (token == INT){
            showToken("INT");
        }
        else if (token == BYTE){
            showToken("BYTE");
        }
        else if (token == B){
            showToken("B");
        }
        else if (token == BOOL){
            showToken("BOOL");
        }
        else if (token == AND){
            showToken("AND");
        }
        else if (token == OR){
            showToken("OR");
        }
        else if (token == NOT){
            showToken("NOT");
        }
        else if (token == TRUE){
            showToken("TRUE");
        }
        else if (token == FALSE){
            showToken("FALSE");
        }
        else if (token == RETURN){
            showToken("RETURN");
        }
        else if (token == IF){
            showToken("IF");
        }
        else if (token == ELSE){
            showToken("ELSE");
        }
        else if (token == WHILE){
            showToken("WHILE");
        }
        else if (token == BREAK){
            showToken("BREAK");
        }
        else if (token == CONTINUE){
            showToken("CONTINUE");
        }
        else if (token == SC){
            showToken("SC");
        }
        else if (token == COMMA){
            showToken("COMMA");
        }
        else if (token == LPAREN){
            showToken("LPAREN");
        }
        else if (token == RPAREN){
            showToken("RPAREN");
        }
        else if (token == LBRACE){
            showToken("LBRACE");
        }
        else if (token == RBRACE){
            showToken("RBRACE");
        }
        else if (token == ASSIGN){
            showToken("ASSIGN");
        }
        else if (token == RELOP){
            showToken("RELOP");
        }
        else if (token == BINOP){
            showToken("BINOP");
        }
        else if (token == COMMENT){
            showToken("COMMENT");
        }
        else if (token == ID){
            showToken("ID");
        }
        else if (token == NUM){
            showToken("NUM");
        }
        else if (token == STRING){
            showToken("STRING");
        }
        token = yylex();
    }
	return 0;
}