%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void yyerror(char *s);
int yylex();
void interpretaCodigo();
void imprimeTablaCodigo();
void imprimeTablaSimbolo();
int genTemp();
int esEntero(int tipo);
void generaCodigo(int op,int a1,int a2,int a3);
int asignarSimbolo(char *lexema, int token);
int localizaSimboloAnadeNum(char *lexema , int token);
char lexema[100];
typedef struct{
        char nombre[100];
        int token;
        double valor;
        int tipo; // 0:sintipo 1: int    2: float    3: double   4: char   5: long     6: bool      7:short
        int noConstante; //0: constante    1: variable
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

int vuelta[100]={0};
int cont_v=0;

int retornos[100]={0};
int numRetorn=0;

int avance[100]={0};
int contAvances=0;

int actualLoop[100]={0};
int numLoop=0;

int esConst=0;
%}


%token  WHILE IF ID NUM DO FOR
%token  IGUALDAD ELSE ELIF CONTINUE
%token  INT LONG SHORT DOUBLE FLOAT CHAR BOOL VERDAD FALSO CONST BITSIZ BITSDE
%token RETURN BREAK PASS
%token  INCREMENTO DECREMENTO AUMENTO DISMINUCION MULTI DIVI MOD
%token PRINT COMENTARIOSIMPLE COMENTARIOCOMPLEJO
%token  DE_TIPO DESIGUALDAD SCAN
%token NEGACION AND OR NAND XOR NOR;
//tokens de pedro C
%token COMPMAYOR COMPMENOR COMPMAYORIGUAL COMPMENORIGUAL COMPIGUAL COMPDESIGUAL SALTARF SALTAR COMPAND COMPOR COMPNAND
%token ASIGNAR INCREMENTAR DECREMENTAR COMPXOR COMPNOR DECLARARINT DECLARARDOUBLE DECLARARCHAR DECLARARLONG 
%token DECLARARSHORT DECLARARFLOAT DECLARARBOOL
//tokens de Pedro C y cbas
%token MULTIPLICAR DIVIDIR MODULAR SUMAR RESTAR
//tokens de cbas
%token MOVERBDE MOVERBIZ
//tokens de gerar
%token IMPRIMIR DECLARARCONST DECLARARCONSTINT DECLARARCONSTDOUBLE DECLARARCONSTCHAR DECLARARCONSTLONG DECLARARCONSTSHORT
%token DECLARARCONSTFLOAT DECLARARCONSTBOOL 
//token de pedro Y
%token SALTARV CONTINUAR
//token de omar
%token PASAR RETORNAR FIN ROMPER
//token de Marcelo Jara
%token RETORNAR_TIPO NEGAR LEER

%%
prog
    : listainst {generaCodigo(FIN,'-','-','-'); int i=0; for(i=0;i<numRetorn;i++){tablaCodigo[retornos[i]].a1 = cx;} };
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
    | CONTINUE {generaCodigo(CONTINUAR,vuelta[cont_v-1],'-','-');}
    | RETURN {generaCodigo(RETORNAR,'?','-','-'); retornos[numRetorn++]=cx;}
    | BREAK {generaCodigo(ROMPER,'?','-','-'); actualLoop[numLoop-1]++; avance[contAvances++]=cx;}
    | PASS {generaCodigo(PASAR,'-','-','-');}
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
    : SCAN '(' otrofactor ')'{generaCodigo(LEER,$3,'-','-');};
iterativa_do
    : DO {vuelta[cont_v++]=cx+1; numLoop++; $$=cx+1;} bloque WHILE '(' {$$=cx+1;} comp {generaCodigo(SALTARV,$7,$2,'-'); cont_v--; $$=cx; int i; for(i=0;i<actualLoop[numLoop-1];i++){tablaCodigo[avance[--contAvances]].a1 = cx +1;} numLoop--;} ')' ;
iterativa_for
    : FOR '(' asignacion ';' 
            {numLoop++; $$=cx+1;} comp {generaCodigo(SALTARF,$6,'?','-'); $$=cx;} {generaCodigo(SALTAR,'?','-','-'); $$=cx;} ';' 
            {vuelta[cont_v++]=cx+1; $$=cx+1;} asignacion {generaCodigo(SALTAR,$5,'-','-'); $$=cx;} ')' 
            { tablaCodigo[$8].a1= cx + 1; } {$$=cx+1;} bloque {generaCodigo(SALTAR,$10,'-','-'); $$=cx;} { tablaCodigo[$7].a2 = cx +1 ; cont_v--;int i; for(i=0;i<actualLoop[numLoop-1];i++){tablaCodigo[avance[--contAvances]].a1 = cx +1;} numLoop--;} ;             
iterativa_while
    : WHILE '(' {vuelta[cont_v++]=cx+1; numLoop++; $$=cx+1;} comp {generaCodigo(SALTARF,$4,'?','-'); $$=cx;} ')' 
            bloque {generaCodigo(SALTAR,$3,'-','-'); $$=cx;} { tablaCodigo[$5].a2 = cx +1 ; cont_v--; int i; for(i=0;i<actualLoop[numLoop-1];i++){tablaCodigo[avance[--contAvances]].a1 = cx +1;} numLoop--;};    
condicional
    : IF '(' comp ')' {generaCodigo(SALTARF,$3,'?','-'); $$=cx;} bloque {generaCodigo(SALTARV,$3,'?','-'); $$=cx;} { tablaCodigo[$5].a2 = cx +1 ; }  else { tablaCodigo[$7].a2 = cx +1 ; };
bloque
    : '{' listainst '}' ; 
declaracion
    : identificador ID {$$=asignarSimbolo(lexema,ID); } {if($1==1)generaCodigo(DECLARARINT,$3,'-','-');
                                                                else if($1==2)generaCodigo(DECLARARFLOAT,$3,'-','-');
                                                                else if($1==3)generaCodigo(DECLARARDOUBLE,$3,'-','-');
                                                                else if($1==4)generaCodigo(DECLARARCHAR,$3,'-','-');
                                                                else if($1==5)generaCodigo(DECLARARLONG,$3,'-','-');
                                                                else if($1==6)generaCodigo(DECLARARBOOL,$3,'-','-');
                                                                else if($1==7)generaCodigo(DECLARARSHORT,$3,'-','-');}
                                                                
    | CONST identificador ID {esConst=1;$$=asignarSimbolo(lexema,ID);esConst=0;} '=' expresion {if($2==1)generaCodigo(DECLARARCONSTINT,$4,$6,'-');
                                                                else if($2==2)generaCodigo(DECLARARCONSTFLOAT,$4,$6,'-');
                                                                else if($2==3)generaCodigo(DECLARARCONSTDOUBLE,$4,$6,'-');
                                                                else if($2==4)generaCodigo(DECLARARCONSTCHAR,$4,$6,'-');
                                                                else if($2==5)generaCodigo(DECLARARCONSTLONG,$4,$6,'-');
                                                                else if($2==6)generaCodigo(DECLARARCONSTBOOL,$4,$6,'-');
                                                                else if($2==7)generaCodigo(DECLARARCONSTSHORT,$4,$6,'-'); };
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
    : INT {$$=1;}
    | FLOAT {$$=2;}
    | DOUBLE {$$=3;}
    | CHAR {$$=4;}
    | LONG {$$=5;}
    | BOOL {$$=6;}
    | SHORT {$$=7;}; 
    
expresion
    : comp ;

comp
    : comp '>' '=' expr  {int i=genTemp(); generaCodigo(COMPMAYORIGUAL,i,$1,$4);$$=i;} 
    | comp '>'  expr  {int i=genTemp(); generaCodigo(COMPMAYOR,i,$1,$3);$$=i;} 
    | comp '<'  expr  {int i=genTemp(); generaCodigo(COMPMENOR,i,$1,$3);$$=i;} 
    | comp '<' '='  expr  {int i=genTemp(); generaCodigo(COMPMENORIGUAL,i,$1,$4);$$=i;} 
    | comp IGUALDAD  expr {int i=genTemp(); generaCodigo(COMPIGUAL,i,$1,$3);$$=i;} 
    | comp DESIGUALDAD  expr {int i=genTemp(); generaCodigo(COMPDESIGUAL,i,$1,$3);$$=i;} 
    | comp AND expr {int i=genTemp(); generaCodigo(COMPAND,i,$1,$3);$$=i;}
    | comp OR expr {int i=genTemp(); generaCodigo(COMPOR,i,$1,$3);$$=i;}
    | comp NAND expr {int i=genTemp(); generaCodigo(COMPNAND,i,$1,$3);$$=i;}
    | comp XOR expr {int i=genTemp(); generaCodigo(COMPXOR,i,$1,$3);$$=i;}
    | comp NOR expr {int i=genTemp(); generaCodigo(COMPNOR,i,$1,$3);$$=i;}
    | expr;   
    
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
    | '(' expresion')'  {$$=$2;}
    |  otrofactor
    | VERDAD { $$=localizaSimboloAnadeNum(lexema,VERDAD);}
    | FALSO { $$=localizaSimboloAnadeNum(lexema,FALSO);} ; 
otrofactor
    : ID  { $$=localizaSimboloAnadeNum(lexema,ID);} ;
    
else
    : ELSE bloque
    | ELIF '(' comp ')'{generaCodigo(SALTARF,$3,'?','-'); $$=cx;} bloque {generaCodigo(SALTARV,$3,'?','-'); $$=cx;} { tablaCodigo[$5].a2 = cx +1 ; }  else { tablaCodigo[$7].a2 = cx +1 ; }
    | ;
funcion
    : DE_TIPO '(' expr ')' {int i=genTemp(); generaCodigo(RETORNAR_TIPO,i,$3,'-'); $$=i;}
    | NEGACION '(' expr ')' {int i=genTemp(); generaCodigo(NEGAR,i,$3,'-'); $$=i;};
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

int esEntero(int tipo){
    if(tipo==1){
        return 1;
    }
    if(tipo==4){
        return 1;
    }
    if(tipo==5){
        return 1;
    }
    if(tipo==6){
        return 1;
    }
    if(tipo==7){
        return 1;
    }return 0;
}

/*codigo C*/
/*análisis léxico*/

void interpretaCodigo(){
    int op,a1,a2,a3,imprimio=0;
    double aux1, aux2;
    for(int i=0;i<=cx ;i++){
        op=tablaCodigo[i].op;
        a1=tablaCodigo[i].a1;
        a2=tablaCodigo[i].a2;
        a3=tablaCodigo[i].a3;
        if (op==ASIGNAR){
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            }
        }
        if(op==SALTARF){
            if (fabs(tablaSimbolos[a1].valor-0)<=0.0001){
                i=a2-1;
            }
        }
        if(op==SALTARV){
            if (fabs(tablaSimbolos[a1].valor-1)<=0.0001){
                i=a2-1;
            }
        }
        if(op==SALTAR){
            i=a1-1;
        }
        if(op==COMPMENOR){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) < tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor < (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) < (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor < tablaSimbolos[a3].valor;
        }
        if(op==COMPMAYOR){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) > tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor > (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) > (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor > tablaSimbolos[a3].valor;
        }
        if(op==COMPMAYORIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) >= tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor >= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) >= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor >= tablaSimbolos[a3].valor;
        }
        if(op==COMPMENORIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) <= tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor <= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) <= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor <= tablaSimbolos[a3].valor;
        }
        if(op==COMPIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) == tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor == (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) == (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor == tablaSimbolos[a3].valor;
        }
        if(op==COMPDESIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) != tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor != (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) != (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor != tablaSimbolos[a3].valor;
        }
        if(op==COMPAND){
            tablaSimbolos[a1].valor = ((int)(tablaSimbolos[a2].valor+0.5)) && ((int)(tablaSimbolos[a3].valor+0.5)); 
        }
        if(op==COMPOR){
            tablaSimbolos[a1].valor = ((int)(tablaSimbolos[a2].valor+0.5)) || ((int)(tablaSimbolos[a3].valor+0.5)); 
        }
        if(op==COMPNAND){
            tablaSimbolos[a1].valor = !(((int)(tablaSimbolos[a2].valor+0.5)) && ((int)(tablaSimbolos[a3].valor+0.5)));
        }
        if(op==COMPXOR){
            tablaSimbolos[a1].valor = (!((int)(tablaSimbolos[a2].valor+0.5)) && ((int)(tablaSimbolos[a3].valor+0.5))) || (((int)(tablaSimbolos[a2].valor+0.5)) && !((int)(tablaSimbolos[a3].valor+0.5)));
        }
        if(op==COMPNOR){
            tablaSimbolos[a1].valor = !(((int)(tablaSimbolos[a2].valor+0.5)) || ((int)(tablaSimbolos[a3].valor+0.5)));
        }
        if(op==INCREMENTAR){
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = tablaSimbolos[a1].valor + 1;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            }
        }
        if(op==DECREMENTO){
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = tablaSimbolos[a1].valor - 1;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==SUMAR){
            if(tablaSimbolos[a1].noConstante) {
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor + tablaSimbolos[a3].valor; 
            }
            else {
                printf("Error al intentar cambiar una constante %d \n",a1);
                exit(1);
            }
        }
        if(op==RESTAR){
            if(tablaSimbolos[a1].noConstante){
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor - tablaSimbolos[a3].valor;
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MULTIPLICAR){
            if(tablaSimbolos[a1].noConstante){
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor * tablaSimbolos[a3].valor;
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==DIVIDIR){
            if(tablaSimbolos[a1].noConstante) {
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor / tablaSimbolos[a3].valor;
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MODULAR){
            aux1 = tablaSimbolos[a2].valor + 0.5;
            aux2 = tablaSimbolos[a3].valor + 0.5;
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = (int)aux1 % (int)aux2;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MOVERBIZ){
            int auxbits1=(int)(tablaSimbolos[a2].valor+0.5);
            int auxbits2=(int)(tablaSimbolos[a3].valor+0.5);
            if(tablaSimbolos[a1].noConstante) {
                tablaSimbolos[a1].valor = (double)(auxbits1<<auxbits2);
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MOVERBDE){
            int auxbits1=(int)(tablaSimbolos[a2].valor+0.5);
            int auxbits2=(int)(tablaSimbolos[a3].valor+0.5);
            if(tablaSimbolos[a1].noConstante) {
                tablaSimbolos[a1].valor = (double)(auxbits1>>auxbits2);
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        
        if(op==DECLARARCONSTINT){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 1;
        }
        if(op==DECLARARCONSTFLOAT){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 2;
        }
        if(op==DECLARARCONSTDOUBLE){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 3;
        }        
        if(op==DECLARARCONSTCHAR){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 4;
        }
        if(op==DECLARARCONSTLONG){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 5;
        }
        if(op==DECLARARCONSTBOOL){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 6;
        }
        if(op==DECLARARCONSTSHORT){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 7;
        }
        if(op == IMPRIMIR){
            if(!imprimio){
                printf("+-----------------------------------+\n");
                printf("| Terminal                          |\n");
            }imprimio=1;
            if(esEntero(tablaSimbolos[a1].tipo))
                printf("| >  %-30d |\n",(int)tablaSimbolos[a1].valor);
            else printf("| >  %-30lf |\n",tablaSimbolos[a1].valor);
        }
        if(op == CONTINUAR) {
            i = a1 - 1;
        }
        
        if(op==DECLARARINT){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 1;
        }
        if(op==DECLARARFLOAT){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 2;
        }
        if(op==DECLARARDOUBLE){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 3;
        }
        if(op==DECLARARCHAR){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 4;
        }
        if(op==DECLARARLONG){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 5;
        }
        if(op==DECLARARBOOL){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 6;
        }
        if(op==DECLARARSHORT){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 7;
        }
        if(op==RETORNAR){
            i=a1-1;
        }
        if(op==ROMPER){
            i=a1-1;
        }
    }
    if(imprimio) printf("+-----------------------------------+\n");
}

/*localiza el lexema dentro de la tabla de simbolos*/
int asignarSimbolo(char *lexema, int token){
	int i;
	for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            printf("Error al declarar dos veces una misma variable: %s\n",lexema);
            exit(1);
        }
    }
    strcpy(tablaSimbolos[i].nombre,lexema);
    tablaSimbolos[i].valor=0.0;
    tablaSimbolos[i].token=token;
    tablaSimbolos[i].noConstante=!esConst;
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
        tablaSimbolos[i].tipo = 2;
    } 
    if(token == VERDAD ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); 
        tablaSimbolos[i].valor=1; 
        tablaSimbolos[i].token=token;  
        tablaSimbolos[i].tipo = 1;
    } 
    if(token == FALSO ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); 
        tablaSimbolos[i].valor=0; 
        tablaSimbolos[i].token=token;  
        tablaSimbolos[i].tipo = 1;
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
        printf("Luego de la interpretacion\n");
        interpretaCodigo();
        imprimeTablaSimbolo(); 
        printf("Cadena válida\n\n");
	}
	else{
        printf("Cadena inválida\n\n");	
	}
    return 0;
}
