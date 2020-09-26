%option noyywrap
%{
     #include<stdio.h>
     #include<stdlib.h>
%}

%%
(00|11|(01|10)(00|11)*(01|10))* {
        printf("binary string of even 0's and even 1's");
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