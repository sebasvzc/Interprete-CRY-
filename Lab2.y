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


%token  WHILE IF ID NUM DO FOR
%token  IGUALDAD ELSE ELIF CONTINUE
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID CONST BITSIZ BITSDE
%token RETURN BREAK PASS
%token  INCREMENTO DECREMENTO AUMENTO DISMINUCION MULTI DIVI MOD
%token PRINT COMENTARIOSIMPLE COMENTARIOCOMPLEJO
%token  DE_TIPO DESIGUALDAD SCAN
%token NEGACION AND OR NAND XOR NOR;

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
    | condicional 
    | imprimir 
    | leer 
    | comentario
    | funcion;
comentario
    : comentarioSimple 
    | comentarioComplejo;
comentarioSimple
    : COMENTARIOSIMPLE;
comentarioComplejo
    : COMENTARIOCOMPLEJO;
imprimir
    : PRINT '(' expr ')';
leer
    : SCAN '(' expr ')';
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
    : ID { $$=localizaSimboloAnadeNum(lexema,ID);} asignaciones;
asignaciones
    : '=' expresion
    | INCREMENTO
    | DECREMENTO
    | AUMENTO expresion
    | DISMINUCION expresion 
    | MULTI expresion
    | DIVI expresion 
    | MOD expresion;
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
    |BITSDE 
    |'%' ;
factor
    : NUM { $$=localizaSimboloAnadeNum(lexema,NUM);}
    | '(' expr')'  
    | ID  { $$=localizaSimboloAnadeNum(lexema,ID);} 
    | VERDAD { $$=localizaSimboloAnadeNum(lexema,NUM);} ;
    | FALSO { $$=localizaSimboloAnadeNum(lexema,NUM);} ; 
comp
    : expr '>' '=' expr  
    | expr '>'  expr  
    | expr '<'  expr  
    | expr '<' '='  expr  
    | expr IGUALDAD  expr 
    | expr DESIGUALDAD  expr 
    | expresion exp_logica expresion;
else
    : ELSE bloque
    | ELIF '(' comp ')' bloque else
    | ;
funcion
    : DE_TIPO '(' identificador ')' 
    | NEGACION '(' expr ')' ;
exp_logica
    : AND 
    | OR 
    | NAND 
    | XOR 
    | NOR;
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
        if(!strcmp(lexema,"imprimir")) return PRINT;
        if(!strcmp(lexema,"leer")) return SCAN;
        if(!strcmp(lexema,"deTipo")) return DE_TIPO;
        if(!strcmp(lexema,"falsoAmor")) return FALSO;
        if(!strcmp(lexema,"verdaderoSentimiento")) return VERDAD;
        if(!strcmp(lexema,"jamas")) return NEGACION;
        if(!strcmp(lexema,"yh")) return AND;
        if(!strcmp(lexema,"oh")) return OR;
        if(!strcmp(lexema,"nomas")) return NAND;
        if(!strcmp(lexema,"ellaOyo")) return XOR;
        if(!strcmp(lexema,"nituNiyo")) return NOR;
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
    
    if (c=='/'){
        c=getchar();
        if (c=='/'){  
            while(getchar()!='\n');
            return COMENTARIOSIMPLE;                        
        }
        else if (c == '=') {
            return DIVI;
        }
        else{
            ungetc(c,stdin);
            return '/';
        }  
    }
    
    if (c=='@'){
        while(getchar()!='@');
        return COMENTARIOCOMPLEJO;  
    } 

    if (c=='!'){
        c=getchar();
        if (c=='='){  
            return DESIGUALDAD;                        
        }
        else{
            ungetc(c,stdin);
            return '=';
        }  
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
            return INCREMENTO;                        
        }
        else if(c == '='){
            return AUMENTO;
        }
        else{
            ungetc(c,stdin);
            return '+';
        }  
    }
    
    if (c=='-'){
        c=getchar();
        if (c=='-'){  
            return DECREMENTO ;                        
        }
        else if (c == '='){
            return DISMINUCION;
        }
        else{
            ungetc(c,stdin);
            return '-';
        }  
    }
    
    if (c=='*'){
        c=getchar();
        if (c=='='){  
            return MULTI;                        
        }
        else{
            ungetc(c,stdin);
            return '*';
        }
    }     
       	
    if (c=='%'){
        c=getchar();
        if (c=='='){  
            return MOD;                        
        }
        else{
            ungetc(c,stdin);
            return '%';
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
            return BITSDE;                        
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
