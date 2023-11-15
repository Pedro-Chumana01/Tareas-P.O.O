#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif
}

void moveTextUpDown(int *posY, int *direction) {
    *posY += *direction;

    if (*posY <= 0 || *posY >= 20) {
        *direction *= -1;
    }
}

void printTextAtPosition(int posY, const char *text) {
    for (int i = 0; i < posY; i++) {
        printf("\n");
    }
    printf("%s\n", text);
}

double calcularPotencia(double base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else {
        return base * calcularPotencia(base, exponente - 1);
    }
}

void convertirAMayusculas(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] -= 32;
        }
        i++;
    }
}

void convertirAMinusculas(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] += 32;
        }
        i++;
    }
}

void alternarMayusculasYMinusculas(char cadena[]) {
    int i = 0;
    bool mayuscula = true;
    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z' && mayuscula) {
            cadena[i] -= 32;
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z' && !mayuscula) {
            cadena[i] += 32;
        }
        mayuscula = !mayuscula;
        i++;
    }
}

void dividirYRestar() {
    int dividendo, divisor;
    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);

    printf("Resultados:\n");
    while (divisor >= 1) {
        printf("%d / %d = %.2lf\n", dividendo, divisor, (double)dividendo / divisor);
        divisor--;
    }
}

int calcularLongitudCadena(const char cadena[]) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

int main() {
    int opcion;

    do {
        printf("\tMenu de opciones\n\n");
        printf("1. Realizar potencia\n");
        printf("2. Convertir frase a mayusculas\n");
        printf("3. Convertir frase a minusculas\n");
        printf("4. Dividir y restar\n");
        printf("5. Alternar mayusculas y minusculas\n");
        printf("6. Mover frase automaticamente\n");
        printf("0. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
            	system("cls");
                double base;
                int exponente;
                printf("Ingrese la base: ");
                scanf("%lf", &base);
                printf("Ingrese el exponente: ");
                scanf("%d", &exponente);
                double resultado = calcularPotencia(base, exponente);
                printf("Resultado: %.2lf\n", resultado);
                break;
            }
            case 2: {
            	system("cls");
                char cadena[100];
                printf("Ingrese una frase: ");
                scanf(" %99[^\n]", cadena);
                convertirAMayusculas(cadena);
                printf("Frase en mayúsculas: %s\n", cadena);
                break;
            }
            case 3: {
            	system("cls");
                char cadena[100];
                printf("Ingrese una frase: ");
                scanf(" %99[^\n]", cadena);
                convertirAMinusculas(cadena);
                printf("Frase en minúsculas: %s\n", cadena);
                break;
            }
            case 4:
            	system("cls");
                dividirYRestar();
                break;
            case 5: {
            	system("cls");
                char cadena[100];
                printf("Ingrese una frase: ");
                scanf(" %99[^\n]", cadena);
                alternarMayusculasYMinusculas(cadena);
                printf("Frase alternada: %s\n", cadena);
                break;
            }
            case 6: {
                system("cls");
                const char *text = "Hola, mundo!";
                int posY = 0;
                int direction = 1;

                while (!_kbhit()) {
                    clearScreen();
                    moveTextUpDown(&posY, &direction);
                    printTextAtPosition(posY, text);
                    Sleep(100);
                }
                break;
            }
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

    } while (opcion != 0);

    return 0;
}
