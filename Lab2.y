%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void yyerror(char *s);
int yylex();
int asignarSimbolo(char *lexema, int token);
int localizaSimbolo(char *lexema , int token);
char lexema[100];
typedef struct{
        char nombre[100];
        int token;
        double valor;
}TipoTS;
TipoTS tablaSimbolos[100];
int nSim=0;
%}


%token  MIENTRAS IF ID NUM SUMAUN
%token  IGUALDAD
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID


%%
prog:  listainst;
listainst: instr listainst ;
listainst: ;
instr: declaracion | asignacion | comp | iterativa_while | condicional;
iterativa_while: MIENTRAS '(' comp ')' bloque ;
condicional: IF '(' comp ')' bloque;
bloque: '{' listainst '}' ;
declaracion: identificador ID {$$=asignarSimbolo(lexema,ID);};
asignacion:  ID {$$=localizaSimbolo(lexema,ID);} '=' expresion ;
identificador: INT;
expresion: expr| comp |sumaunaria;
expr : expr '+' term   ;
expr : expr '-' term  ;
expr : term  ;
term : term opmult factor ;
term : factor ;
opmult:'*';
factor: NUM { $$=localizaSimbolo(lexema,NUM);};
factor: '(' expr')'  ;
factor: ID  { $$=localizaSimbolo(lexema,ID);};
comp: expr '>' '=' expr ;
comp: expr '>'  expr ;
comp: expr '<'  expr ;
comp: expr IGUALDAD  expr ;
sumaunaria: ID SUMAUN; 


%%

/*codigo C*/
/*análisis léxico*/
/*localiza el lexema dentro de la tabla de simbolos*/

int asignarSimbolo(char *lexema, int token){
	int i;
	for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            printf("Error al declarar una misma variable");
            exit(1);
        }
    }
    strcpy(tablaSimbolos[i].nombre,lexema);
    if(token == NUM ){ 
        tablaSimbolos[i].valor=atof(lexema); 
    } 
    else{ 
        tablaSimbolos[nSim].valor=0.0; 
    } 
    tablaSimbolos[i].token=token;
    nSim++;
    return nSim-1;
}

int localizaSimbolo(char *lexema , int token){
    int i;
    for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            return i;
        }
    }
    strcpy(tablaSimbolos[i].nombre,lexema);
    if(token == NUM ){ 
        tablaSimbolos[i].valor=atof(lexema); 
    } 
    else{ 
        printf("Variable no reconocida\n");
        exit(1);
    }
    /* 
        tablaSimbolos[i].token=token;
        nSim++;
        return nSim-1;     
    */
}

int yylex(){
    int i;
    char c;
    
    c=getchar();
    while(c==' ' || c=='\n' || c=='\t'){ 
        c=getchar(); 
        if(c!=' ' && c!='\n' && c!='\t') break;
    }             
    if(c=='#') return 0;
    
    if(isalpha(c)){
        i=0;
        do{
            lexema[i++]=c;
            c=getchar();
        }while(isalnum(c));
        ungetc(c,stdin);
        lexema[i++]='\0';
        if(!strcmp(lexema,"if")) return IF; 
        if(!strcmp(lexema,"while")) return MIENTRAS;
        if(!strcmp(lexema,"enteroAmor")) return INT;
        if(!strcmp(lexema,"realAmor")) return FLOAT;
        if(!strcmp(lexema,"doblementeReal")) return DOUBLE;
        if(!strcmp(lexema,"caracterCorazoncito")) return CHAR;
        if(!strcmp(lexema,"cortaRelacion")) return SHORT;
        if(!strcmp(lexema,"largaDuracion")) return LONG;
        if(!strcmp(lexema,"boolCool")) return BOOL;
        if(!strcmp(lexema,"falsoAmor")) return FALSO;
        if(!strcmp(lexema,"verdaderoSentimiento")) return VERDAD;
        if(!strcmp(lexema,"vacioProfundo")) return VOID;
        return ID;
    }

    if(isdigit(c)){
        i=0;
        do{
            lexema[i++]=c;
            c=getchar();
        }while(isdigit(c));
        ungetc(c,stdin);
        lexema[i++]='\0';
        return NUM;
    } 
                 
               
    if (c=='='){
        c=getchar();
        if (c=='='){  
            return IGUALDAD;                        
        }
        else{
            ungetc(c,stdin);
            return '=';
        }  
    }
                
    if (c=='+'){
        c=getchar();
        if (c=='+'){  
            return SUMAUN;                        
        }
        else{
            ungetc(c,stdin);
            return '+';
        }  
    }
    return c;
}

void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}

int main(){
    if(!yyparse()){
        printf("cadena válida\n");
	}
	else{
        printf("cadena inválida\n");	
	}
    return 0;
}
