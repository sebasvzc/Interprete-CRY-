%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void yyerror(char *s);
int yylex();
int asignarSimbolo(char *lexema, int token);
int localizaSimboloAnadeNum(char *lexema , int token);
char lexema[100];
typedef struct{
        char nombre[100];
        int token;
        double valor;
}TipoTS;
TipoTS tablaSimbolos[100];
int nSim=0;
%}


%token  WHILE IF ID NUM SUMAUN DO FOR
%token  IGUALDAD ELSE ELIF CONTINUE RESTAUN
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID CONST BITSIZ BISTDE
%token RETURN BREAK PASS

%%
prog
    : listainst;
listainst
    : instr listainst 
    | ;
instr
    : declaracion 
    | asignacion 
    | comp 
    | iterativa_while  
    | iterativa_do  
    | iterativa_for  
    | CONTINUE
    | RETURN
    | BREAK
    | PASS
    | condicional ;
iterativa_do
    : DO bloque WHILE '(' comp ')' ;
iterativa_for
    : FOR '(' asignacion ';' comp ';' asignacion ')' bloque ;
iterativa_while
    : WHILE '(' comp ')' bloque  else;
condicional
    : IF '(' comp ')' bloque ;
bloque
    : '{' listainst '}' ; 
declaracion
    : identificador ID {$$=asignarSimbolo(lexema,ID); }
    | CONST identificador ID {$$=asignarSimbolo(lexema,ID);} '=' expresion ;
asignacion
    : ID { $$=localizaSimboloAnadeNum(lexema,ID);} '=' expresion ;
identificador
    : INT 
    | FLOAT 
    | DOUBLE 
    | CHAR 
    | LONG 
    | VOID 
    | BOOL 
    | SHORT ; 
expresion
    : expr 
    | comp 
    | sumaunaria ;
expr 
    : expr '+' term  
    | expr '-' term   
    | term ;
term 
    : term op factor  
    | factor ;
op
    :'*' 
    |'/' 
    |BITSIZ 
    |BISTDE 
    |'%' ;
factor
    : NUM { $$=localizaSimboloAnadeNum(lexema,NUM);}
    | '(' expr')'  
    | ID  { $$=localizaSimboloAnadeNum(lexema,ID);} ;
comp
    : expr '>' '=' expr  
    | expr '>'  expr  
    | expr '<'  expr  
    | expr '<' '='  expr  
    | expr IGUALDAD  expr ;
sumaunaria
    : ID SUMAUN 
    | ID RESTAUN ;
else
    : ELSE bloque
    | ELIF '(' comp ')' bloque else
    | ;


%%

/*codigo C*/
/*análisis léxico*/
/*localiza el lexema dentro de la tabla de simbolos*/
int asignarSimbolo(char *lexema, int token){
	int i;
	for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            printf("Error al declarar una misma variable\n");
            exit(1);
        }
    }
    strcpy(tablaSimbolos[i].nombre,lexema);
    tablaSimbolos[nSim].valor=0.0;
    tablaSimbolos[i].token=token;
    nSim++;
    return nSim-1;
}

int localizaSimboloAnadeNum(char *lexema , int token){ 
    int i;
    for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            return i;
        }
    }
    if(token == NUM ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); 
        tablaSimbolos[i].valor=atof(lexema); 
        tablaSimbolos[i].token=token;  
    } 
    else{ 
        printf("Variable no reconocida\n");
        exit(1);
    }
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
        if(!strcmp(lexema,"terminamos")) return BREAK;
        if(!strcmp(lexema,"regresemos")) return RETURN;
        if(!strcmp(lexema,"nada")) return PASS;
        if(!strcmp(lexema,"sisi")) return IF; 
        if(!strcmp(lexema,"mientras")) return WHILE;
        if(!strcmp(lexema,"enteroAmor")) return INT;
        if(!strcmp(lexema,"realAmor"))return FLOAT;
        if(!strcmp(lexema,"doblementeReal"))return DOUBLE;
        if(!strcmp(lexema,"caracterCorazoncito")) return CHAR;
        if(!strcmp(lexema,"cortaRelacion")) return SHORT;
        if(!strcmp(lexema,"largaDuracion")) return LONG;
        if(!strcmp(lexema,"boolCool")) return BOOL;
        if(!strcmp(lexema,"falsoAmor")) return FALSO;
        if(!strcmp(lexema,"verdaderoSentimiento")) return VERDAD;
        if(!strcmp(lexema,"constanteRechazo"))    return CONST;
        if(!strcmp(lexema,"vacioProfundo")) return VOID;
        if(!strcmp(lexema,"haz")) return DO;
        if(!strcmp(lexema,"para")) return FOR;
        if(!strcmp(lexema,"osino")) return ELSE;
        if(!strcmp(lexema,"osisi")) return ELIF;
        if(!strcmp(lexema,"volvamos")) return CONTINUE;
        return ID;
    }

    if(isdigit(c)){
        i=0;
        do{
            lexema[i++]=c;
            c=getchar();
        }while(isdigit(c) || c=='.');
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
    
    if (c=='-'){
        c=getchar();
        if (c=='-'){  
            return RESTAUN ;                        
        }
        else{
            ungetc(c,stdin);
            return '-';
        }  
    }
    
    if (c=='<'){
        c=getchar();
        if (c=='<'){  
            return BITSIZ;                        
        }
        else{
            ungetc(c,stdin);
            return '<';
        }  
    }
    
    if (c=='>'){
        c=getchar();
        if (c=='>'){  
            return BISTDE;                        
        }
        else{
            ungetc(c,stdin);
            return '>';
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
