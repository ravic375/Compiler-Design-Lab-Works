%option noyywrap
%{
    #define MAIN 1
    #define NUMBER 2
    #define RELOP 3
    #define IF 4
    #define ELSE 5
    #define FOR 6
    #define WHILE 7
    #define ID 8
    #define READ 9
    #define PRINT 10
    #define INT 11
    #define FLOAT 12
    #define INORDE 13
    #define ASSIGNMENT 15
    #define OPERATOR 16
    #define SEPARATOR 17
%}
whitespace ([ \t\r]*)
main (main)
number ([+-]?[0-9]*([.][0-9]*)?(E[+-]?[0-9]*)?)
operator [*/%+-]
assignment (=|[+][=]|[-][=]|[*][=]|[/][=]|[%]=)
inorde ([+][+]|[-][-])
relop (!=|<=|>=|<|>|==)
if (if)
else (else)
for (for)
while (while)
read (read)
print (print)
int (int|INT)
float (float|FLOAT)
separator [;,(){}]
id ([A-Za-z][A-Za-z0-9]*)

%%
{main} {return MAIN;}
{number} {return NUMBER;}
{operator} {return OPERATOR;}
{assignment} {return ASSIGNMENT;}
{inorde} {return INORDE;}
{relop} {return RELOP;}
{if} {return IF;}
{else} {return ELSE;}
{for} {return FOR;}
{while} {return WHILE;}
{read} {return READ;}
{print} {return PRINT;}
{int} {return INT;}
{float} {return FLOAT;}
{separator} {return SEPARATOR;}
{id} {return ID;}
{whitespace} {}
. {return -1;}
%%
int main()
{
    int token;
    yyin=fopen("q3.txt","r");
    while((token=yylex())!=0)
     printf("%2d %s \n",token,yytext);
}