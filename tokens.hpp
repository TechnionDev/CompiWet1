#ifndef TOKENS_HPP_
#define TOKENS_HPP_
enum tokentype {
  VOID = 1,
  INT = 2,
  BYTE = 3,
  B = 4,
  BOOL = 5,
  AND = 6,
  OR = 7,
  NOT = 8,
  TRUE = 9,
  FALSE = 10,
  RETURN = 11,
  IF = 12,
  ELSE = 13,
  WHILE = 14,
  BREAK = 15,
  CONTINUE = 16,
  SC = 17,
  COMMA = 18,
  LPAREN = 19,
  RPAREN = 20,
  LBRACE = 21,
  RBRACE = 22,
  ASSIGN = 23,
  RELOP = 24,
  BINOP = 25,
  COMMENT = 26,
  ID = 27,
  NUM = 28,
  STRING = 29
};
    extern int yylineno;
    extern char* yytext;
    extern size_t yyleng; //TODO::need to change to size_t
    extern int yylex();
    extern char global_str[1024];
    extern int strIndex;
#endif /* TOKENS_HPP_ */