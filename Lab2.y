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

void imprimeTablaCodigo();
int genTemp();
void generaCodigo(int op,int a1,int a2,int a3);

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
%}

%token MIENTRAS IF ID NUM SUMAUN
%token IGUALDAD ELSE ELIF CONTINUE
%token INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO VOID CONST BITSIZ BITSDE
%token DE_TIPO DESIGUALDAD SCAN
%token NEGACION AND OR NAND XOR NOR
%token COMPMAYOR COMPMENOR COMPMAYORIGUAL COMPMENORIGUAL COMPIGUAL COMPDESIGUAL COMPLOGICO SALTARF SALTAR COMPAND COMPOR COMPNAND
%token ASIGNAR INCREMENTAR DECREMENTAR AUMENTAR DISMINUIR SUMAR RESTAR MULTIPLICAR DIVIDIR MODULAR COMPXOR COMPNOR

%%
prog
    : listainst;
listainst
    : instr listainst 
    | ;
instr
    : declaracion 
    | asignacion
    | incremento 
    | decrementar
    | aumentavalor
    | disminuyevalor
    | multiplicavalor
    | dividevalor
    | modulavalor
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
    : IF '(' comp ')' {generaCodigo(SALTARF,$3,'?','-'); $$=cx;} bloque { tablaCodigo[$5].a2 = cx +1 ; } else;
bloque
    : '{' listainst '}' ; 
declaracion
    : identificador ID {$$=asignarSimbolo(lexema,ID); }
    | CONST identificador ID {$$=asignarSimbolo(lexema,ID);} '=' expresion ;
  
asignacion
    : ID '=' expresion {generaCodigo(ASIGNAR,$1,$3,'-');};
incremento
    : ID INCREMENTO {generaCodigo(INCREMENTAR,$1,$1,1);};

decrementar
    : ID DECREMENTO {generaCodigo(DECREMENTAR,$1,$1,1);};

aumentavalor
    : ID AUMENTO expresion {generaCodigo(AUMENTAR,$1,$1,$3);};

disminuyevalor
    : ID DISMINUCION expresion {generaCodigo(DISMINUIR,$1,$1,$3);};
    
multiplicavalor
    : ID MULTI expresion {generaCodigo(MULTIPLICAR,$1,$1,$3);};

dividevalor
    : ID DIVI expresion {generaCodigo(DIVIDIR,$1,$1,$3);};

modulavalor
    : ID MOD expresion {generaCodigo(MODULAR,$1,$1,$3);};
    
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
    : expr '>' '=' expr  {int i=genTemp(); generaCodigo(COMPMAYORIGUAL,i,$1,$4);$$=i;} 
    | expr '>'  expr  {int i=genTemp(); generaCodigo(COMPMAYOR,i,$1,$3);$$=i;} 
    | expr '<'  expr  {int i=genTemp(); generaCodigo(COMPMENOR,i,$1,$3);$$=i;} 
    | expr '<' '='  expr  {int i=genTemp(); generaCodigo(COMPMENORIGUAL,i,$1,$4);$$=i;} 
    | expr IGUALDAD  expr {int i=genTemp(); generaCodigo(COMPIGUAL,i,$1,$3);$$=i;} 
    | expr DESIGUALDAD  expr {int i=genTemp(); generaCodigo(COMPDESIGUAL,i,$1,$3);$$=i;} 
    | expresion AND expr {int i=genTemp(); generaCodigo(COMPAND,i,$1,$3);$$=i;}
    | expresion OR expr {int i=genTemp(); generaCodigo(COMPOR,i,$1,$3);$$=i;}
    | expresion NAND expr {int i=genTemp(); generaCodigo(COMPNAND,i,$1,$3);$$=i;}
    | expresion XOR expr {int i=genTemp(); generaCodigo(COMPXOR,i,$1,$3);$$=i;}
    | expresion NOR expr {int i=genTemp(); generaCodigo(COMPNOR,i,$1,$3);$$=i;};
else
    : ELSE bloque
    | ELIF '(' comp ')'{generaCodigo(SALTARF,$3,'?','-'); $$=cx;} bloque { tablaCodigo[$5].a2 = cx +1 ; } else
    | ;
funcion
    : DE_TIPO '(' identificador ')' 
    | NEGACION '(' expr ')' ;
%%

/*codigo C*/
void imprimeTablaCodigo(){
         printf("Tabla Codigos\n");
        for(int i=0;i<=cx ;i++){
                printf("%d\t%d\t%d\t%d\t%d\t\n",i, tablaCodigo[i].op,tablaCodigo[i].a1, tablaCodigo[i].a2, tablaCodigo[i].a3);
        }

}
void imprimeTablaSimbolo(){
        printf("Tabla Simbolos\n");
        for(int i=0;i<nSim ;i++){
                printf("%d\t%s\t%d\t%lf\n",i, tablaSimbolos[i].nombre,tablaSimbolos[i].token,tablaSimbolos[i].valor);
        }
}
int genTemp(){
        int pos;
        char t[10]; 
        sprintf(t,"_T%d",nVarTemp++);
        pos= localizaSimboloAnadeNum(t,ID);
        return pos;
}
void generaCodigo(int op,int a1,int a2,int a3){
        cx++;
        tablaCodigo[cx].op=op;
        tablaCodigo[cx].a1=a1;
        tablaCodigo[cx].a2=a2;
        tablaCodigo[cx].a3=a3;
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
        ImprimeTablaSimbolo();
        printf("cadena valida\n");
	}
	else{
        printf("cadena invalida\n");	
	}
    return 0;
}
