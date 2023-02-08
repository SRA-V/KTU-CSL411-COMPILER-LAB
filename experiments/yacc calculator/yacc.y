%{
    #include <stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExpression:E{
    printf("\nResult=%d\n",$$);
    return 0;
};
E:E'+'E {$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;}
 |E'/'E {$$=$1/$3;}
 |E'%'E {$$=$1%$3;}
 |'('E')' {$$=$2;}
 |NUMBER {$$=$1;}
;
%%
void main(){
    printf("\nEnter arithmetric expression:");
    yyparse();
    printf("\n");
}
void yyerror(){
    printf("\nInvalid\n");
}