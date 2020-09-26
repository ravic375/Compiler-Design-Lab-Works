%option noyywrap
%{
    #include<stdio.h>
    #include<stdlib.h>

%}

%%
(0|1(01*0)*1)* {printf("Number divisible by 3"); printf("\n"); return 1;}
.*             {printf("Number not divisible by 3"); printf("\n"); return 2;}

%%
int main()
{
    yylex();
    return 0;
}