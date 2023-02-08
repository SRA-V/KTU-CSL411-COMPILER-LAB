#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isDelimiter(char ch){
    char ops[]=" +-*/,;<=>{}[]%";
    return strchr(ops,ch)!=NULL;

}
bool isOperator(char ch){
    char ops[]="+-*/%<>=";
    return strchr(ops,ch)!=NULL;

}
bool isIdentifier(char *str){
    return !isdigit(str[0])&&!isDelimiter(str[0]);

}
bool isKeyword(char *str){
    char *Keyword[32]={"auto", "break", "case", "char", "const", "continue", "default",
                          "do", "double", "else", "enum", "extern", "float", "for", "goto",
                          "if", "int", "long", "register", "return", "short", "signed",
                          "sizeof", "static", "struct", "switch", "typedef", "union",
                          "unsigned", "void", "volatile", "while"};
    for(int i=0;i<32;i++){
        if(strcmp(Keyword[i],str)==0)
        return true;
    }
    return false;
}
bool isIntiger(char *str){
    char *endptr;
    strtol(str,&endptr,10);
    return !*endptr;


}
bool isReal(char *str){
    char *endptr;
    strtod(str,&endptr);
    return !*endptr;

}
char* substr(char *str,int start,int end){
    int i;
    char* sub=(char *)malloc(sizeof(char)*(end-start+2));
    for(i=start;i<=end;i++){
        sub[i-start]=str[i];
    }sub[i-start]='\0';
    return sub;

}
void parse(char *str){
    int left=0,right=0;
    int len=strlen(str);
    while (right<len&&left<=right){
        if(isDelimiter(str[right])==false)
        right++;
        if(isDelimiter(str[right])&&left==right){
            if(isOperator(str[right]))
            printf("\nOperator:%c",str[right]);
            right++;
            left=right;
            
        }
        else if(isDelimiter(str[right])&&left!=right||(right==len&&left!=right)){
            char *subStr=substr(str,left,right-1);
            if(isKeyword(subStr))
            printf("\nKeyword:%s",subStr);
            else if(isIntiger(subStr))
            printf("\nInteger:%s",subStr);
            else if(isReal(subStr))
            printf("\nReal:%s",subStr);
            else if(isIdentifier(subStr))
            printf("\nidentifier:%s",subStr);
            else{printf("\nInvalid:%s",subStr);}
            left=right;

        }
    }
    
}
int main(){
    char str[]="int a = 10.0 + 1c ;";
    parse(str);
    return 0;
}
