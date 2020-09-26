%option noyywrap
%{
     #include<stdio.h>
     #include<stdlib.h>
%}

%%
(1*01*01*)* {
        printf("binary string of even 0's");
        printf("\n");    
        return 1;
       }
.*            {printf("Not required string"); 
               printf("\n");
                return 2;}
%%
int main()
{
     yylex();
     return 0;
}