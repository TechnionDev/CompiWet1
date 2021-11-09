#include <iostream>
#include "tokens.hpp"
#include <string.h>
using namespace std;

void showToken(const string& token){
    if (token=="STRING"){
        //cout <<"hii_1"<<endl;
        cout << to_string(yylineno) + " " + token + " " + global_str <<endl;
        memset(global_str, 0, strlen(global_str));
        strIndex =0;
        return;
    } else if (token == "COMMENT"){
        cout << to_string(yylineno) + " " + token + " " + "//" <<endl;
        return;
    }
    //cout <<"hii_2"<<endl;
    cout << to_string(yylineno) + " " + token + " " + yytext <<endl;
}
int main()
{
	int token = yylex();
    while(token) {
	// Your code here
        switch (token) {
            case (VOID):
                showToken("VOID");
                break;
            case INT:
                showToken("INT");
                break;
            case BYTE:
                showToken("BYTE");
                break;
            case B:
                showToken("B");
                break;
            case BOOL:
                showToken("BOOL");
                break;
            case AND:
                showToken("AND");
                break;
            case OR:
                showToken("OR");
                break;
            case NOT:
                showToken("NOT");
                break;
            case TRUE:
                showToken("TRUE");
                break;
            case FALSE:
                showToken("FALSE");
                break;
            case RETURN:
                showToken("RETURN");
                break;
            case IF:
                showToken("IF");
                break;
            case ELSE:
                showToken("ELSE");
                break;
            case WHILE:
                showToken("WHILE");
                break;
            case BREAK:
                showToken("BREAK");
                break;
            case CONTINUE:
                showToken("CONTINUE");
                break;
            case SC:
                showToken("SC");
                break;
            case COMMA:
                showToken(";");
                break;
            case LPAREN:
                showToken("LPAREN");
                break;
            case RPAREN:
                showToken("RPAREN");
                break;
            case LBRACE:
                showToken("LBRACE");
                break;
            case RBRACE:
                showToken("RBRACE");
                break;
            case ASSIGN:
                showToken("ASSIGN");
                break;
            case RELOP:
                showToken("RELOP");
                break;
            case BINOP:
                showToken("BINOP");
                break;
            case COMMENT:
                showToken("COMMENT");
                break;
            case ID:
                showToken("ID");
                break;
            case NUM:
                showToken("NUM");
                break;
            case STRING:
                showToken("STRING");
                break;
            default:
                showToken("ERROR");

                //todo::add error func
        }
        token = yylex();
    }
	return 0;
}
