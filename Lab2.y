%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void yyerror(char *s);
int yylex();
int asignarSimbolo(char *lexema, int token);
int localizaSimboloAnadeNum(char *lexema , int token); //Actualizar cabezera
void ImprimeTablaSimbolo( );
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
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID CONST
%token  DE_TIPO


%%
prog
    : listainst{printf("1\n");};
listainst
    : instr listainst {printf("2\n");}
    | {printf("3\n");};
instr
    : declaracion  {printf("4\n");}
    | asignacion  {printf("5\n");}
    | comp  {printf("6\n");}
    | iterativa_while  {printf("7\n");}
    | condicional {printf("8\n");};
    | funcion {printf("8.5\n");};
iterativa_while
    : MIENTRAS '(' comp ')' bloque  {printf("9\n");};
condicional
    : IF '(' comp ')' bloque {printf("10\n");};
bloque
    : '{' listainst '}' {printf("11\n");}; 
declaracion
    : identificador ID {printf("12\n"); $$=asignarSimbolo(lexema,ID); }
    | CONST identificador ID {printf("14\n"); $$=asignarSimbolo(lexema,ID);} '=' {printf("102\n");} expresion {printf("103\n");} ;
asignacion
    : ID { printf("15\n"); $$=localizaSimboloAnadeNum(lexema,ID);} '=' expresion ;
identificador
    : INT {printf("16\n");}          ///////////////////
    | FLOAT {printf("17\n");}
    | DOUBLE {printf("18\n");}
    | CHAR {printf("19\n");}
    | LONG {printf("20\n");}
    | VOID {printf("21\n");}
    | BOOL {printf("22\n");}
    | SHORT {printf("23\n");}; 
expresion
    : expr {printf("24\n");}
    | comp  {printf("25\n");}
    | sumaunaria {printf("26\n");}; 
expr 
    : expr '+' term  {printf("27\n");}
    | expr '-' term   {printf("28\n");}
    | term   {printf("29\n");};
term 
    : term opmult factor  {printf("30\n");}
    | factor  {printf("31\n");};
opmult
    :'*' {printf("32\n");};
factor
    : NUM {  printf("33\n"); $$=localizaSimboloAnadeNum(lexema,NUM);}
    | '(' expr')'  
    | ID  {  printf("34\n"); $$=localizaSimboloAnadeNum(lexema,ID);};
comp
    : expr '>' '=' expr  {printf("35\n");}
    | expr '>'  expr  {printf("36\n");}
    | expr '<'  expr  {printf("37\n");}
    | expr IGUALDAD  expr  {printf("38\n");};
sumaunaria
    : ID SUMAUN {printf("39\n");}; 
funcion
    : DETIPO '(' comp ')' bloque {printf("40\n");};


%%

/*codigo C*/
/*análisis léxico*/
/*localiza el lexema dentro de la tabla de simbolos*/

void ImprimeTablaSimbolo( ){
    int i;
    printf("Tabla de simbolos\n");
    for(i=0;i<nSim ;i++){
        printf("%d\t%-13s",i,tablaSimbolos[i].nombre);
        printf("%d\t",tablaSimbolos[i].token);
        printf("%lf\n",tablaSimbolos[i].valor);
    }
}


int asignarSimbolo(char *lexema, int token){
	int i;
    printf("var %s\n",lexema);
	for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            printf("Error al declarar una misma variable\n");
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
    printf("prob %s\n",lexema);
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
        if(!strcmp(lexema,"if")) return IF; 
        if(!strcmp(lexema,"while")) return MIENTRAS;
        if(!strcmp(lexema,"enteroAmor")) {printf("%s\n",lexema);return INT;}
        if(!strcmp(lexema,"realAmor")){printf("%s\n",lexema);return FLOAT;}
        if(!strcmp(lexema,"doblementeReal")) {printf("%s\n",lexema);return DOUBLE;}
        if(!strcmp(lexema,"caracterCorazoncito")) return CHAR;
        if(!strcmp(lexema,"cortaRelacion")) return SHORT;
        if(!strcmp(lexema,"largaDuracion")) return LONG;
        if(!strcmp(lexema,"boolCool")) return BOOL;
        if(!strcmp(lexema,"falsoAmor")) FALSO;
        if(!strcmp(lexema,"verdaderoSentimiento")) return VERDAD;
        if(!strcmp(lexema,"constanteRechazo"))    return CONST;
        if(!strcmp(lexema,"vacioProfundo")) return VOID;
        if(!strcmp(lexema,"deTipo")) return DE_TIPO;
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
    return c;
}

void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}

int main(){
    if(!yyparse()){
        ImprimeTablaSimbolo();
        printf("cadena válida\n");
	}
	else{
        printf("cadena inválida\n");	
	}
    return 0;
}
