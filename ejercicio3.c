#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Definición de tokens
typedef enum {
    TOKEN_NUMERO,
    TOKEN_SUMA,
    TOKEN_RESTA,
    TOKEN_MULTIPLICACION,
    TOKEN_DIVISION,
    TOKEN_PARENTESIS_IZQ,
    TOKEN_PARENTESIS_DER,
    TOKEN_FIN_EXPRESION,
    TOKEN_DESCONOCIDO
} TokenType;

// Definición de la estructura del token
typedef struct {
    TokenType type;
    int value; // Solo para TOKEN_NUMERO
} Token;

// Función para leer un token
Token getNextToken(char c)
{
    Token token;

    switch (c) {
    case '+':
        token.type = TOKEN_SUMA;
        break;
    case '-':
        token.type = TOKEN_RESTA;
        break;
    case '*':
        token.type = TOKEN_MULTIPLICACION;
        break;
    case '/':
        token.type = TOKEN_DIVISION;
        break;
    case '(':
        token.type = TOKEN_PARENTESIS_IZQ;
        break;
    case ')':
        token.type = TOKEN_PARENTESIS_DER;
        break;
    case '\n':
    case EOF:
        token.type = TOKEN_FIN_EXPRESION;
        break;
    case ' ': // ignoramos los espacios en blanco
        break;
    default:
        if (isdigit(c)) {
            token.value = c;
            token.type = TOKEN_NUMERO;
        } else {
            token.type = TOKEN_DESCONOCIDO;
        }
        break;
    }

    return token;
}

// Función principal para probar el lexer
int main()
{
    Token token;
    char expresion[MAX_SIZE];
    printf("Ingrese una expresión aritmética (presione Enter al finalizar):\n");
    scanf("%[^\n]s", expresion);

    for (int i = 0; i < strlen(expresion); i++) {
        token = getNextToken(expresion[i]);
        switch (token.type) {
        case TOKEN_NUMERO:
            printf("TOKEN_NUMERO: %c\n", token.value);
            break;
        case TOKEN_SUMA:
            printf("TOKEN_SUMA\n");
            break;
        case TOKEN_RESTA:
            printf("TOKEN_RESTA\n");
            break;
        case TOKEN_MULTIPLICACION:
            printf("TOKEN_MULTIPLICACION\n");
            break;
        case TOKEN_DIVISION:
            printf("TOKEN_DIVISION\n");
            break;
        case TOKEN_PARENTESIS_IZQ:
            printf("TOKEN_PARENTESIS_IZQ\n");
            break;
        case TOKEN_PARENTESIS_DER:
            printf("TOKEN_PARENTESIS_DER\n");
            break;
        case TOKEN_FIN_EXPRESION:
            printf("FIN DE LA EXPRESION\n");
            break;
        case TOKEN_DESCONOCIDO:
            printf("TOKEN_DESCONOCIDO\n");
            break;
        }
    }

    return 0;
}
