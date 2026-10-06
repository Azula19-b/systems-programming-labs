/*
 Name: Bahar Ozer
 Description: Flex scanner updated to recognize division and modulus operators.
*/

%{
#include "zcalc.h"
#include <math.h>

int ch;
int flag = 0;

#define NAME 257
#define SEMISYM 268
#define COMMASYM 269
#define LPARSYM 270
#define RPARSYM 271
#define EQSYM 272
#define PLUSSYM 273
#define MULTSYM 274
#define ASGNSYM 275
#define MINUSSYM 276
#define NUMBER 277
#define DIVIDESYM 278
#define MODULUSSYM 279

typedef struct {
  double dval;
  struct symtab *symp;
} my_type;

static my_type yylval;
%}

letter [A-Za-z]
digit  [0-9]+
ident  {letter}({letter}|{digit})*
ws     [ \t\n]+
other  .

%%

{ws}  ;
"//".* ;

";" return SEMISYM;
"," return COMMASYM;
"(" return LPARSYM;
")" return RPARSYM;
"==" return EQSYM;
"+"  return PLUSSYM;
"*"  return MULTSYM;
"="  return ASGNSYM;
"-"  return MINUSSYM;
"/"  return DIVIDESYM;
"%"  return MODULUSSYM;

{ident} {
  struct symtab *sp = symlook(yytext);
  yylval.symp = sp;
  return NAME;
}

{digit} {
  yylval.dval = atof(yytext);
  return NUMBER;
}

"$" { return 0; }
{other} ;

%%

void yyerror(char *mesg);

struct symtab *
symlook(s)
char *s;
{
  char *p;
  struct symtab *sp;

  for (sp = symtab; sp < &symtab[NSYMS]; sp++) {
    if (sp->name && !strcmp(sp->name, s))
      return sp;

    if (!sp->name) {
      sp->name = (char *)strdup(s);
      return sp;
    }
  }

  yyerror("Too many symbols...\n");
  exit(1);
}

addfunc(name, func)
char *name;
double (*func)();
{
  struct symtab *sp = symlook(name);
  sp->funcptr = func;
}

void yyerror(char *mesg)
{
  flag = 1;
  printf("%s \n", mesg);
}

main()
{
  printf("Lex  \t\tToken\t\t\n");
  printf("----------------------------\n");

  do {
    ch = yylex();

    if (ch == SEMISYM)
      printf("%s\t\tSEMICOLON ", yytext);
    else if (ch == COMMASYM)
      printf("%s\t\tCOMMA ", yytext);
    else if (ch == LPARSYM)
      printf("%s\t\tL_PARENTHESIS ", yytext);
    else if (ch == RPARSYM)
      printf("%s\t\tR_PARENTHESIS ", yytext);
    else if (ch == EQSYM)
      printf("%s\t\tEQ_OP ", yytext);
    else if (ch == PLUSSYM)
      printf("%s\t\tPLUS_OP ", yytext);
    else if (ch == MULTSYM)
      printf("%s\t\tMULT_OP ", yytext);
    else if (ch == ASGNSYM)
      printf("%s\t\tASSIGNMENT_STMT ", yytext);
    else if (ch == MINUSSYM)
      printf("%s\t\tMINUS_OP ", yytext);
    else if (ch == DIVIDESYM)
      printf("%s\t\tDIVIDE_OP ", yytext);
    else if (ch == MODULUSSYM)
      printf("%s\t\tMODULUS_OP ", yytext);
    else if (ch == NUMBER)
      printf("%s\t\tNUMBER ", yytext);
    else if (ch == NAME)
      printf("%s\t\tNAME\t\t", yytext);
    else
      printf("%c ", ch);

    printf("\n");

  } while (ch != 0);
}

int yywrap()
{
  return 1;
}
