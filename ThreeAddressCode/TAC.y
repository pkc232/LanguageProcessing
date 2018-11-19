%{
//Headers
#include <bits/stdc++.h>
using namespace std;


//Structure to be used
struct exprType{
	char *place;
	char *code;
};

//global Variables
int varNo=1;
int labNo=1;
map<string,int> symBol;
char *s,*s1,*s2;
char* switchCaseVar;
struct exprType *to_return_expr;

void yyerror(char* s);
int yylex(void);

char* concat(char* a,char *b,char c);
char* newVar();
char* newLabel();
char* toStr(int x);
void replace(char* og,char* oldS,char* newS);
exprType* operate(exprType* e1,exprType* e2,char oprt);
exprType* assignOperate(char* e1,exprType* e2,char oprt);
%}

%start startSym

%union {
	int ival;
	float fval;
	char *sval;
	struct exprType *EXPRTYPE;
}

%token<ival> DIGIT
%token<fval> FLOAT
%token<sval>ID IF ELSE WHILE FOR TYPES REL_OPT OR AND NOT TRUE FALSE PE CASE SWITCH INCR DECR BOR BAND BXOR
%token<sval> '+' '-' '*' '/' '^' '%' '\n' '=' ';' DEFAULT
%type<sval> list text number construct block dec program startSym bool caseList 
%type<EXPRTYPE> expr stat

%left OR
%left AND
%left NOT
%left REL_OPT
%left BOR
%left BAND
%left BXOR
%right PE ME IE DE
%right '='
%left '+' '-'
%left '*' '/' '%'
%right '^'
%right '@'
%%

startSym: program
{
	char* s1 = $1;
	char* lab = newLabel();
	replace(s1,"NEXT",lab);
	s1=concat(s1,lab,'\n');
	s1=concat(s1,"TERMINATE",':');
	s = s1;
	cout<<"The final Three Address Code is :"<<endl;
	cout<<s<<endl;
	$$=s;
}
;
program : program construct
{
	char* s1= $1;
	char* s2= $2;
	char* lab= newLabel();
	replace(s1,"NEXT",lab);
	s=concat(s1,lab,'\n');
	s=concat(s,s2,':');
	$$=s;
}
|
construct
{
	$$ = $1;
}
;
construct: block
{
	$$=$1;
}
|
IF '(' bool ')' block
{
	char* lab = newLabel();
	char* s1 = $3;
	replace(s1,"TRUE",lab);
	replace(s1,"FAIL","NEXT");
	s=concat($3,lab,'\n');
	s=concat(s,$5,':');
	$$=s;
}
|
WHILE '(' bool ')' block 
{
	char* b1=$3;
	char* s1=$5;
	char* beg= newLabel();
	char* lab= newLabel();
	replace(b1,"TRUE",lab);
	replace(b1,"FAIL","NEXT");
	replace(s1,"NEXT",beg);
	s=concat(beg,b1,':');
	s=concat(s,lab,'\n');
	s=concat(s,s1,':');
	s=concat(s,"jump ",'\n');
	s=concat(s,beg,' ');
	$$=s;
}
|
IF '(' bool ')' block ELSE block
{
	char* b1=$3;
	char* lab1=newLabel();
	replace(b1,"TRUE",lab1);
	char* lab2=newLabel();
	replace(b1,"FAIL",lab2);
	char* stp;
	stp=concat(b1,lab1,'\n');
	stp=concat(stp,$5,':');
	stp=concat(stp,"jump NEXT",'\n');
	char* tp=concat(lab2,$7,':');
	strcat(stp,"\n");
	strcat(stp,tp);
	$$=stp;
}
|
SWITCH '(' expr ')' '{' caseList '}'
{
	char* s1= $6;
	replace(s1,"VARI",$3->place);
	char* lab=newLabel();
	replace(s1,"NEXT",lab);
	char* stp;
	stp=concat(s1,lab,'\n');
	char* cd;
	cd=concat($3->code,stp,':');
	$$=cd;
}
|
FOR '(' stat bool  
;

block : '{' list '}'
{
	$$=$2;
}
|
'{' construct '}'
{
	$$=$2;
}
|
'{' program '}'
{
	$$=$2;
}
|
list
{
	$$=$1;
}
;
caseList : caseList CASE expr ':' block
{

	char* s1= $1;
	char* lab=newLabel();
	replace(s1,"NEXT",lab);
	char* str = $3->place;
	char* stp;
	stp=concat(s1,lab,'\n');
	stp=concat(stp,$3->code,':');
	stp=concat(stp,"if(",'\n');
	strcat(stp,"VARI");
	stp=concat(stp,"!=",' ');
	strcat(stp,str);
	strcat(stp,")");
	stp=concat(stp,"jump NEXT",' ');
	stp=concat(stp,$5,'\n');
	$$=stp;
}
|
caseList DEFAULT ':' block
{
	char* s1= $1;
	char* lab=newLabel();
	replace(s1,"NEXT",lab);
	char* str = " ";
	char* stp;
	stp=concat(s1,lab,'\n');
	stp=concat(stp," ",':');
	stp=concat(stp,"jump NEXT",' ');
	stp=concat(stp,$4,'\n');
	$$=stp;
}
|
CASE expr ':' block
{
	char* stp;
	stp=concat("if(","VARI",' ');
	stp=concat(stp,"!=",' ');
	strcat(stp,$2->place);
	strcat(stp,")");
	stp=concat(stp,"jump NEXT",' ');
	stp=concat(stp,$4,'\n');
	$$=concat($2->code,stp,'\n');
}
|
DEFAULT ':' block
{
	$$=concat($3," ",'\n');	
}
;
list: stat
{
	$$=$1->code;
}
|
list stat
{
	s1=$1;
	s2=$2->code;
	$$=concat(s1,s2,'\n');
}
|
list error '\n'
{
  yyerrok;
}
;


stat: ';'
{
	to_return_expr = new exprType();
	to_return_expr->place = $1;
	to_return_expr->code = new char[20];
	to_return_expr->code[0]=0;

	$$=to_return_expr;
}
|
expr ';'
{
	$$=$1;
}
|
dec ';'
{
	to_return_expr = new exprType();
	to_return_expr->place = $1;
	to_return_expr->code = new char[20];
	to_return_expr->code[0]=0;
	$$ = to_return_expr;
}
|
text '=' expr ';'
{
	to_return_expr = new exprType();
	to_return_expr->place =  newVar();
	char *tp = concat($1,$3->place,'=');

	s=concat($3->code,tp,'\n');
	to_return_expr->code = s;
	$$ = to_return_expr;
	
}
|
dec '=' expr ';'
{
	to_return_expr = new exprType();
	to_return_expr->place =  newVar();
	char *tp = concat($1,$3->place,'=');
	s=concat($3->code,tp,'\n');
	to_return_expr->code = s;
	$$ = to_return_expr;
} 
|
text PE expr ';'
{
	$$=assignOperate($1,$3,'+');		
}
|
text ME expr ';'
{
	$$=assignOperate($1,$3,'-');
}
|
text IE expr ';'
{
	$$=assignOperate($1,$3,'*');
}
|
text DE expr ';'
{
	$$=assignOperate($1,$3,'/');
}
|
text INCR ';'
{
	to_return_expr = new exprType();
	to_return_expr->place=newVar();
	char* tp =concat(to_return_expr->place,$1,'=');
	tp=concat(tp,"1",'+');
	strcat(tp,"\n");
	char* stp;
	stp=concat(" ",tp,'\n');
	s=concat($1,to_return_expr->place,'=');
	strcat(stp,s);
	to_return_expr->code=stp;		
	$$=to_return_expr;
}
|
text DECR ';'
{
	to_return_expr = new exprType();
	to_return_expr->place=newVar();
	char* tp =concat(to_return_expr->place,$1,'=');
	tp=concat(tp,"1",'-');
	strcat(tp,"\n");
	char* stp;
	stp=concat(" ",tp,'\n');
	s=concat($1,to_return_expr->place,'=');
	strcat(stp,s);
	to_return_expr->code=stp;		
	$$=to_return_expr;	
}
;


dec : TYPES text
{
	$$=$2;
}
|
TYPES text ',' text 
{
	// cout<<"Here \n";
	// $$=concat($1,$2,'\n');
}
;
bool : expr REL_OPT expr
{
	char* tp;
	tp=concat("if(",$1->place,' ');
	tp=concat(tp,$2,' ');
	tp=concat(tp,$3->place,' ');
	tp=concat(tp,") jump TRUE \n jump FAIL",' ');
	char* st;
	st=concat($1->code,$3->code,'\n');
	st=concat(st,tp,'\n');
	$$=st;
}
|
bool OR bool 
{
	char* tp;
	char* s1=$1;
	char* s2=$3;
	char* lab=newLabel();
	replace(s1,"FAIL",lab);
	tp=concat(s1,lab,'\n');
	tp=concat(tp,s2,':');
	$$=tp;
}
|
bool AND bool
{
	char* tp;
	char* s1=$1;
	char* s2=$3;
	char* lab=newLabel();
	replace(s1,"TRUE",lab);
	tp=concat(s1,lab,'\n');
	tp=concat(tp,s2,':');
	$$=tp;
}
|
TRUE
{
	s = (char *)malloc(20);
	s[0] = 0;
	strcat(s,"\njump TRUE");
	$$ = s;
}
|
FALSE
{
	s = (char *)malloc(20);
	s[0] = 0;
	strcat(s,"\njump FAIL");
	$$ = s;
}
|
NOT '(' bool ')'
{
	char* lab="TEMP";
	char* sl=$3;
	replace(sl,"TRUE",lab);
	replace(sl,"FAIL","TRUE");
	replace(sl,lab,"FAIL");
	$$=sl;
}
;


expr: '('expr')'
{
	$$=$2;
}
|
expr '+' expr 
{
	$$=operate($1,$3,'+');
}
|
expr '-' expr 
{
	$$=operate($1,$3,'-');
}
|
expr '/' expr 
{
	$$=operate($1,$3,'/');
}
|
expr '*' expr 
{
	$$=operate($1,$3,'*');
}
|
expr '%' expr 
{
	$$=operate($1,$3,'%');
}
|
expr '@' expr 
{
	$$=operate($1,$3,'@');
}
|
expr BOR expr
{
	$$=operate($1,$3,'|');
}
|
expr BAND expr
{
	$$=operate($1,$3,'&');
}
|
expr BXOR expr
{
	$$=operate($1,$3,'^');
}
|
text
{
	to_return_expr = new exprType();
	to_return_expr->place = $1;
	to_return_expr->code = new char[2];
	to_return_expr->code[0]=0;
	$$ = to_return_expr;
}
|
number 
{
	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
	to_return_expr->place = $1;
	to_return_expr->code = new char[2];
	to_return_expr->code[0] = 0;
	$$ = to_return_expr;
}
;

text : ID{
	$$=$1;
}
;
number:  DIGIT
{
	s = new char[20];
   	snprintf(s, 10,"%d",$1);
	$$ = s;        
} 
|
FLOAT
{
	s = (char *)malloc(20);
   	snprintf(s, 10,"%f",$1);
	$$ = s;          
} 
;
%%


char* concat(char *a,char *b,char c){
	s =new char[strlen(a)+strlen(b)+10];
	s[0]=0;
	string str="";
	str+=c;
	if(a[0]){
	strcat(s,a);
	strcat(s,str.c_str());
	}
	if(b[0])
	strcat(s,b);
	return s;
}

char* newVar(){
	s = new char[10];
	s[0]=0;
	strcat(s,"t");
	strcat(s,toStr(varNo));
	varNo++;
	return s;
} 

char* newLabel(){
	s = new char[10];
	s[0]=0;
	strcat(s,"L");
	strcat(s,toStr(labNo));
	labNo++;
	return s;
}

extern int yyparse();
extern FILE *yyin;

int main() {
	FILE *myfile = fopen("input.txt", "r");
	if (!myfile) {
		printf("Unable to open file");
		return -1;
	}
	yyin = myfile;	
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(char *s) {
	printf("Parsing error.  Message: %s ",s);
	exit(-1);
}

char* toStr(int x){
	char* arr = new char[5];
	string sp="";
	sp+=to_string(x);
	arr[0]=0;
	strcat(arr,sp.c_str());
	return arr;
}

void replace(char* og,char* oldS,char* newS){
	char* pos = strstr(og,oldS);
	int l =strlen(newS);
	while(pos){
		strncpy (pos,newS,l);
		strncpy (pos+strlen(newS),"    ",max(4-l,0));
		pos = strstr(og,oldS);
	}
}
exprType* operate(exprType* e1,exprType* e2,char oprt)
{
	exprType* tmp;
	tmp = new exprType();
	tmp->place=newVar();
	char* sl;
	sl=concat(tmp->place,e1->place,'=');
	sl=concat(sl,e2->place,oprt);
	char *tp = concat(e1->code,e2->code,'\n');
	tp = concat(tp,sl,'\n');
	tmp->code=tp;
	return tmp; 	
}
exprType* assignOperate(char* e1,exprType* e2,char oprt){
	exprType* tmp;
	tmp = new exprType();
	tmp->place=newVar();
	char* tp =concat(tmp->place,e1,'=');
	tp=concat(tp,e2->place,oprt);
	strcat(tp,"\n");
	char* stp;
	// stp=concat($3->code,$1,'\n');
	stp=concat(e2->code,tp,'\n');
	s=concat(e1,tmp->place,'=');
	strcat(stp,s);
	tmp->code=stp;
	return tmp;
}
