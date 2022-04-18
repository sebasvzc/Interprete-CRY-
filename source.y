%{
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int yylex();
void yyerror(char *s);
char lexema[100];

%}

%token ID NUM SI MIENTRAS SINO OSISI PARA
%token INT DOUBLE FLOAT CHAR SHORT LONG BOOL VOID
%token CONST PALITOSDOBLES PRINT EXPRESION
%token INC DEC INCN DECN MULN DIVN RESTN
%token TRUE FALSE
%token OR AND
//%token SUM REST DIV MUL

%%
prog : listainst;
listainst: inst listainst; 
listainst: ;
inst: declaracion;
inst: CONST declaracion;
inst: imprimir;
inst: ID INC;
inst: ID DEC;
inst: ID INCN NUM;
inst: ID DECN NUM;
inst: ID MULN NUM;
inst: ID DIVN NUM;
inst: ID RESTN NUM;
inst: PALITOSDOBLES inst ;
inst: ID OR ID;
inst: ID AND ID;



declaracion: INT ID;
declaracion: DOUBLE ID;
declaracion: FLOAT ID;
declaracion: CHAR ID;
declaracion: SHORT ID;
declaracion: LONG ID;
declaracion: BOOL ID;
declaracion: VOID ID;

imprimir: PRINT '(' ID ')';



inst: asignacion;
inst: mientras;
inst: selectiva;
inst: bucle;
asignacion : ID;
asignacion : ID '=' NUM'.'NUM;
asignacion : ID '=' NUM;
mientras: MIENTRAS '(' NUM ')' '{' listainst '}';
bucle: PARA '(' listainst ')'
selectiva: SI '(' NUM ')' '{' listainst '}' selectaux;
selectaux: OSISI '(' NUM ')' '{' listainst '}' selectaux;
selectaux: SINO '(' NUM ')' '{' listainst '}';
selectaux: ;
%%


int main() {
    if (!yyparse()) {
        printf("cadena válida\n");
    } else {
        printf("cadena inválida\n");
    }
    return 0;
}

int yylex() {
    char c;
    int i;
    c = getchar();
    while (c == ' ' || c == '\n' || c == '\t') {
        c = getchar();
        if (c != ' ' && c != '\n' && c != '\t') break;
    }
    if (c == '#') return 0;
    
    if (isalpha(c) || c=='+' || c=='-' || c=='=' || c=='*' || c=='/' || c=='%' || c=='.') {
        i = 0;
        do {
            lexema[i++] = c;
            c = getchar();
        } while (isalnum(c));
        ungetc(c, stdin);
        lexema[i++] = '\0';
        if (!strcmp(lexema, "enteroAmor"))
            return INT;
        if (!strcmp(lexema, "realAmor"))
            return FLOAT;
        if (!strcmp(lexema, "doblementeReal"))
            return DOUBLE;
        if (!strcmp(lexema, "caracterCorazoncito"))
            return CHAR;
        if (!strcmp(lexema, "cortaRelacion"))
            return SHORT;
        if (!strcmp(lexema, "largaDuracion"))
            return LONG;
        if (!strcmp(lexema, "boolCool"))
            return BOOL;
        if (!strcmp(lexema, "verdaderoSentimiento"))
            return TRUE;
        if (!strcmp(lexema, "falsoAmor"))
            return FALSE;
        if (!strcmp(lexema, "vacioProfundo"))
            return VOID;
        if (!strcmp(lexema, "oh"))
            return OR;
        if (!strcmp(lexema, "mas"))
            return AND;
        if (!strcmp(lexema, "//"))
            return PALITOSDOBLES;
        if (!strcmp(lexema, "sisi"))
            return SI;
        if (!strcmp(lexema, "osino"))
            return SINO;
        if (!strcmp(lexema, "osisi"))
            return OSISI;
        if (!strcmp(lexema, "mientras"))
            return MIENTRAS;
        if (!strcmp(lexema, "para"))
            return PARA;
        if (!strcmp(lexema, "imprimir"))
            return PRINT;
        if (!strcmp(lexema, "++"))
            return INC;
        if (!strcmp(lexema, "--"))
            return DEC;
        if (!strcmp(lexema, "+="))
            return INCN;
        if (!strcmp(lexema, "-="))
            return DECN;
        if (!strcmp(lexema, "*="))
            return MULN;
        if (!strcmp(lexema, "/="))
            return DIVN;
        if (!strcmp(lexema, "%="))
            return RESTN;
        if (!strcmp(lexema, "//"))
            return PALITOSDOBLES;
        if (!strcmp(lexema, "constanteRechazo"))
            return CONST;
        return ID;
    }

    if (isdigit(c)) {
        i = 0;
        do {
            lexema[i++] = c;
            c = getchar();
        } while (isdigit(c));
        ungetc(c, stdin);
        lexema[i++] = '\0';
        return NUM;
    }
    return c;
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
