%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void yyerror(char *s);
int yylex();
void imprimeTablaCodigo();
void imprimeTablaSimbolo();
int genTemp();
void generaCodigo(int op,int a1,int a2,int a3);
int asignarSimbolo(char *lexema, int token);
int localizaSimboloAnadeNum(char *lexema , int token);
char lexema[100];
typedef struct{
        char nombre[100];
        int token;
        double valor;
}TipoTS;
typedef struct{
        int op;
        int a1;
        int a2;
        int a3; 
}TipoTC;
TipoTC tablaCodigo[100];
TipoTS tablaSimbolos[100];
int nSim=0;
int cx = -1;
int nVarTemp=1;
int regreso[100];
int cont_r=0;
%}


%token  WHILE IF ID NUM DO FOR
%token  IGUALDAD ELSE ELIF CONTINUE
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID CONST BITSIZ BITSDE
%token RETURN BREAK PASS
%token  INCREMENTO DECREMENTO AUMENTO DISMINUCION MULTI DIVI MOD
%token PRINT COMENTARIOSIMPLE COMENTARIOCOMPLEJO
%token  DE_TIPO DESIGUALDAD SCAN
%token NEGACION AND OR NAND XOR NOR;
//tokens de pedro C
%token COMPMAYOR COMPMENOR COMPMAYORIGUAL COMPMENORIGUAL COMPIGUAL COMPDESIGUAL SALTARF SALTAR COMPAND COMPOR COMPNAND
%token ASIGNAR INCREMENTAR DECREMENTAR COMPXOR COMPNOR
//tokens de Pedro C y cbas
%token MULTIPLICAR DIVIDIR MODULAR SUMAR RESTAR
//tokens de cbas
%token MOVERBDE MOVERBIZ
//tokens de gerar
%token IMPRIMIR DECLARAR DECLARARCONST
//token de pedro Y
%token SALTARV CONTINUAR
//token de Marcelo Jara
%token RETORNAR_TIPO LEER
//Cuidado usando tokens de otros que pueden ser otra operacion de la q parecen

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
    | CONTINUE {generaCodigo(CONTINUAR,regreso[cont_r-1],'-','-');}
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
    : PRINT '(' expresion {generaCodigo(IMPRIMIR,$3,'-','-');} ')';
leer
    : SCAN '(' expr ')' {generaCodigo(LEER,$3,'-','-');};
iterativa_do
    : DO {regreso[cont_r++]=cx+1; $$=cx+1;} bloque WHILE '(' {$$=cx+1;} comp {generaCodigo(SALTARV,$7,$2,'-'); cont_r--; $$=cx;} ')' ;
iterativa_for
    : FOR '(' asignacion ';' 
            {regreso[cont_r++]=cx+1; $$=cx+1;} comp {generaCodigo(SALTARF,$6,'?','-'); $$=cx;} {generaCodigo(SALTAR,'?','-','-'); $$=cx;} ';' 
            {$$=cx+1;} asignacion {generaCodigo(SALTAR,$5,'-','-'); $$=cx;} ')' 
            { tablaCodigo[$8].a1= cx + 1; } {$$=cx+1;} bloque {generaCodigo(SALTAR,$10,'-','-'); $$=cx;} { tablaCodigo[$7].a2 = cx +1 ; cont_r--;} ; 
iterativa_while
    : WHILE '(' {regreso[cont_r++]=cx+1; $$=cx+1;} comp {generaCodigo(SALTARF,$4,'?','-'); $$=cx;} ')' 
            bloque {generaCodigo(SALTAR,$3,'-','-'); $$=cx;} { tablaCodigo[$5].a2 = cx +1 ; cont_r--;};
condicional
    : IF '(' comp ')' {generaCodigo(SALTARF,$3,'?','-'); $$=cx;} bloque { tablaCodigo[$5].a2 = cx +1 ; } else;
bloque
    : '{' listainst '}' ; 
declaracion
    : identificador ID {$$=asignarSimbolo(lexema,ID); } {generaCodigo(DECLARAR,$3,'-','-');}
    | CONST identificador ID {$$=asignarSimbolo(lexema,ID);} '=' expresion {generaCodigo(DECLARARCONST,$4,$6,'-');};
asignacion
    : ID {$$=localizaSimboloAnadeNum(lexema,ID);} asignar expresion {if($3==1)generaCodigo(ASIGNAR,$2,$4,'-');
                                                                else if($3==2)generaCodigo(SUMAR,$2,$2,$4);
                                                                else if($3==3)generaCodigo(RESTAR,$2,$2,$4);
                                                                else if($3==4)generaCodigo(MULTIPLICAR,$2,$2,$4);
                                                                else if($3==5)generaCodigo(DIVIDIR,$2,$2,$4);
                                                                else if($3==6)generaCodigo(MODULAR,$2,$2,$4);}
    | ID {$$=localizaSimboloAnadeNum(lexema,ID);} INCREMENTO {generaCodigo(INCREMENTAR,$2,'-','-');}
    | ID {$$=localizaSimboloAnadeNum(lexema,ID);} DECREMENTO {generaCodigo(DECREMENTAR,$2,'-','-');};
    
asignar
    : '='{$$=1;}
    | AUMENTO{$$=2;}
    | DISMINUCION{$$=3;}
    | MULTI{$$=4;}
    | DIVI{$$=5;}
    | MOD{$$=6;};
    
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
    | comp ;
expr 
    : expr '+' term  { int i=genTemp(); generaCodigo(SUMAR,i,$1,$3); $$=i;}  
    | expr '-' term   { int i=genTemp(); generaCodigo(RESTAR,i,$1,$3); $$=i;}  
    | term ;
term 
    : term op factor  { int i=genTemp(); if($2==1) generaCodigo(MULTIPLICAR,i,$1,$3); 
                                    else if($2==2) generaCodigo(DIVIDIR,i,$1,$3); 
                                    else if($2==3) generaCodigo(MOVERBIZ,i,$1,$3); 
                                    else if($2==4) generaCodigo(MOVERBDE,i,$1,$3); 
                                    else if($2==5) generaCodigo(MODULAR,i,$1,$3); $$=i;}  
    | factor ;
op
    :'*' {$$=1;}
    |'/'  {$$=2;}
    |BITSIZ  {$$=3;}
    |BITSDE  {$$=4;}
    |'%' {$$=5;} ;
factor
    : NUM { $$=localizaSimboloAnadeNum(lexema,NUM);}
    | '(' expr')'  
    | ID  { $$=localizaSimboloAnadeNum(lexema,ID);} 
    | VERDAD { $$=localizaSimboloAnadeNum(lexema,NUM);}
    | FALSO { $$=localizaSimboloAnadeNum(lexema,NUM);} ; 
comp
    : expr '>' '=' expr  {int i=genTemp(); generaCodigo(COMPMAYORIGUAL,i,$1,$4);$$=i;} 
    | expr '>'  expr  {int i=genTemp(); generaCodigo(COMPMAYOR,i,$1,$3);$$=i;} 
    | expr '<'  expr  {int i=genTemp(); generaCodigo(COMPMENOR,i,$1,$3);$$=i;} 
    | expr '<' '='  expr  {int i=genTemp(); generaCodigo(COMPMENORIGUAL,i,$1,$4);$$=i;} 
    | expr IGUALDAD  expr {int i=genTemp(); generaCodigo(COMPIGUAL,i,$1,$3);$$=i;} 
    | expr DESIGUALDAD  expr {int i=genTemp(); generaCodigo(COMPDESIGUAL,i,$1,$3);$$=i;} 
    | expr AND expr {int i=genTemp(); generaCodigo(COMPAND,i,$1,$3);$$=i;}
    | expr OR expr {int i=genTemp(); generaCodigo(COMPOR,i,$1,$3);$$=i;}
    | expr NAND expr {int i=genTemp(); generaCodigo(COMPNAND,i,$1,$3);$$=i;}
    | expr XOR expr {int i=genTemp(); generaCodigo(COMPXOR,i,$1,$3);$$=i;}
    | expr NOR expr {int i=genTemp(); generaCodigo(COMPNOR,i,$1,$3);$$=i;};
else
    : ELSE bloque
    | ELIF '(' comp ')'{generaCodigo(SALTARF,$3,'?','-'); $$=cx;} bloque { tablaCodigo[$5].a2 = cx +1 ; } else
    | ;
funcion
    : DE_TIPO '(' identificador ')' {generaCodigo(RETORNAR_TIPO,$3,'-','-');}
    | NEGACION '(' expr ')' ;
%%

void imprimeTablaCodigo(){
    for(int p=0;p<35;p++)putchar('-');
    printf("\nTabla de Codigos\n");
    for(int p=0;p<35;p++)putchar('-');
    putchar('\n');
    for(int i=0;i<=cx ;i++){
        printf("%2d\t%3d\t%3d\t%3d\t%3d\t\n",
        i, tablaCodigo[i].op,tablaCodigo[i].a1, tablaCodigo[i].a2, tablaCodigo[i].a3);
    }putchar('\n');
}

void imprimeTablaSimbolo(){
    putchar('\n');
    for(int p=0;p<48;p++)putchar('-');
    printf("\nTabla de Simbolos\n");
    for(int p=0;p<48;p++)putchar('-');
    putchar('\n');
    for(int i=0;i<nSim ;i++){
        printf("%2d   %-20s %5d %16.4lf\n",
        i, tablaSimbolos[i].nombre,tablaSimbolos[i].token,tablaSimbolos[i].valor);
    }putchar('\n');
}

int genTemp(){
    int pos;
    char t[10]; 
    sprintf(t,"_T%d",nVarTemp++);
    pos= asignarSimbolo(t,ID);
    return pos;
}

void generaCodigo(int op,int a1,int a2,int a3){
    cx++;
    tablaCodigo[cx].op=op;
    tablaCodigo[cx].a1=a1;
    tablaCodigo[cx].a2=a2;
    tablaCodigo[cx].a3=a3;
}


/*codigo C*/
/*análisis léxico*/
/*localiza el lexema dentro de la tabla de simbolos*/
int asignarSimbolo(char *lexema, int token){
	int i;
	for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            printf("Error al declarar una misma variable: %s\n",lexema);
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
    else if(token == ID){ 
        printf("Variable no reconocida: %s\n", lexema);
        exit(1);
    }
    nSim++;
    return nSim-1;
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
        imprimeTablaSimbolo();
        imprimeTablaCodigo(); 
        printf("Cadena válida\n\n");
	}
	else{
        printf("Cadena inválida\n\n");	
	}
    return 0;
}
