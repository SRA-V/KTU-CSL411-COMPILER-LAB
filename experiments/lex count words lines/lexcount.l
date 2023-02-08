%option noyywrap

%{
#include <stdio.h>
int line=0,word=0,cha=0;
%}
%%

[\n] {line++;cha+=yyleng;}
[^\t\n ]+ {word++;cha+=yyleng;}

%%

int main(){
    printf("\nEnter input. press CTRL+d to stop.\n\n");
    yylex();
    printf("\nNumber of lines:%d",line);
    printf("\nNumber of words:%d",word);
    printf("\nNumber of characters:%d\n",cha-line);

}
