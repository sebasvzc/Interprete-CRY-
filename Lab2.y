%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void yyerror(char *s);
int yylex();
int asignarSimbolo(char *lexema, int token);
int localizaSimboloAnadeNum(char *lexema , int token); //Actualizar cabezera
char lexema[100];
typedef struct{
        char nombre[100];
        int token;
        double valor;
}TipoTS;
TipoTS tablaSimbolos[100];
int nSim=0;
%}


%token  MIENTRAS IF ID NUM SUMAUN OSINO OSISI FOR DO
%token  IGUALDAD
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID


%%
prog:  listainst;
listainst: instr listainst ;
listainst: ;
instr: declaracion | asignacion | comp | iterativa_while | iterativa_for | condicional | iterativa_do ;
iterativa_do: DO bloque MIENTRAS '(' comp ')' ;
iterativa_while: MIENTRAS '(' comp ')' bloque ;
iterativa_for: FOR '(' asignacion ';' comp ';' asignacion ')' bloque ;
condicional: IF '(' comp ')' bloque else;
bloque: '{' listainst '}' ;
declaracion: identificador ID {$$=asignarSimbolo(lexema,ID);};
asignacion:  ID {$$=localizaSimboloAnadeNum(lexema,ID);} '=' expresion ;
identificador: INT | FLOAT;
expresion: expr| comp |sumaunaria;
expr : expr '+' term   ;
expr : expr '-' term  ;
expr : term  ;
term : term opmult factor ;
term : factor ;
opmult:'*';
factor: NUM { $$=localizaSimboloAnadeNum(lexema,NUM);};
factor: '(' expr')'  ;
factor: ID  { $$=localizaSimboloAnadeNum(lexema,ID);};
comp: expr '>' '=' expr ;
comp: expr '>'  expr ;
comp: expr '<'  expr ;
comp: expr IGUALDAD  expr ;
sumaunaria: ID SUMAUN;
else: ;
else: OSISI '(' comp ')' bloque else;
else: OSINO bloque;


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
    /*if(token == NUM ){                        No creo q sea necesario pues no vamos a declarar un numero
        tablaSimbolos[i].valor=atof(lexema); 
    }*/ 
    tablaSimbolos[nSim].valor=0.0;
    tablaSimbolos[i].token=token;
    nSim++;
    return nSim-1;
}

int localizaSimboloAnadeNum(char *lexema , int token){ //Mejor nombre? Nosexd
    int i;
    for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            return i;
        }
    }
    if(token == NUM ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); //Solo debemos aniadir el lexema si es numero, sino solo debemos msotrar el error de abajo
        tablaSimbolos[i].valor=atof(lexema); 
        tablaSimbolos[i].token=token;  //Falto aniadir el token del num
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
        if(!strcmp(lexema,"sisi")) return IF; 
        if(!strcmp(lexema,"mientras")) return MIENTRAS;
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
        if(!strcmp(lexema,"osino")) return OSINO;
        if(!strcmp(lexema,"osisi")) return OSISI;
        if(!strcmp(lexema,"para")) return FOR;
        if(!strcmp(lexema,"haz")) return DO;
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
