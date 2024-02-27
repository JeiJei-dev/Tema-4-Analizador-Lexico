#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    char cadena[MAX_SIZE];
    int top = -1;

    printf("Ingrese una cadena con ceros y unos: ");
    scanf("%s", cadena);

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '0') {
            top++;
        } else if (cadena[i] == '1' && top >= 0) {
            top--;
        } else {
            printf("La cadena no pertenece al lenguaje\n");
            return 0;
        }
    }

    if (top == -1) {
        printf("La cadena pertenece al lenguaje\n");
    } else {
        printf("La cadena no pertenece al lenguaje\n");
    }

    return 0;
}
