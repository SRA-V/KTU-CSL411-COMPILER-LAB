%{
#include <stdio.h>
int line=0,word=0,cha=0;
%}
%%
"end" return 0;
[\n]    {line++;cha+=yyleng;}
[^\t\n ]+ {word++;cha+=yyleng;}

%%
int yywrap(){
    return 1;
}
int main(){
    printf("Enter input:");
    yylex();//ctrl+d to end input
    printf("Number of lines:%d",line);
    printf("\nNumber of words:%d",word);
    printf("\nNumber of characters:%d",cha);

}