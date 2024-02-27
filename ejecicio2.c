#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int automata_pushdown(char* expr)
{
    int len = strlen(expr);
    int pila = 0;

    for (int i = 0; i < len; ++i) {
        if (expr[i] == '(') {
            pila++;
        } else if (expr[i] == ')' && pila > 0) {
            pila--;
        } else if ((expr[i] == ')' && pila <= 0)) {
            return 0;
        }
    }

    return (pila == 0);
}

int main()
{
    char expresion[MAX_SIZE];

    printf("Ingrese una expresion matematica con parentesis: ");
    scanf("%s", expresion);
    printf("%s", expresion);

    if (automata_pushdown(expresion)) {
        printf("\nExpresion valida.\n");
    } else {
        printf("\nExpresion invalida.\n");
    }

    return 0;
}
