%{
  #include <stdio.h>
  extern int yylex();
%}

%option noyywrap

%%
[ \t\n]        { ; } // Ignorar espacios en blanco
"agregar"      { printf("Token: AGREGAR\n"); }
"mostrar"      { printf("Token: MOSTRAR\n"); }
"completar"    { printf("Token: COMPLETAR\n"); }
"eliminar"     { printf("Token: ELIMINAR\n"); }
[a-zA-Z0-9-]+  { printf("Token nombre de la tarea: %s\n", yytext); }
.              { printf("Token no reconocido: %s\n", yytext); }
%%

int main()
{
  while (yylex());
}
