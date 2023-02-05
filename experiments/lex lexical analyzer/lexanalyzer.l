%{
	int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.*	{printf("%s is a preprocessor directive",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do | 
if |
break |
continue |
void |
switch |
return |
else |
goto	{printf("keyword" );}
"/*"	{COMMENT=1;printf("comment ");}
\+	{if(!COMMENT)printf("plus ");}
\-	{if(!COMMENT)printf("minus ");}
\*	{if(!COMMENT)printf("multiplication ");}
\/	{if(!COMMENT)printf("division ");}
\".*\"	{if(!COMMENT)printf("String ");}
[0-9]+	{if(!COMMENT)printf("Number ");}
\<= |
\>= |
\< |
== |
\> 	{if(!COMMENT) printf("Relational_operator ");}
=	{if(!COMMENT) printf("Asssignment_operator ");}
\{	{if(!COMMENT) printf("Block_begin ");}
\}	{if(!COMMENT) printf("Block_end ");}
{identifier}(\[[0-9]*\])?	{if(!COMMENT) printf("Identifier ");}
%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
}