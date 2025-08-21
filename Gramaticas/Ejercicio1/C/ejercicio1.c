#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función que revisa si una cadena es capicúa y solo tiene 0 y 1
bool es_ejercicio1(char *s) {
    int n = strlen(s);

    // Recorremos la cadena para verificar que solo tenga 0 o 1
    for (int i = 0; i < n; i++) {
        if (s[i] != '0' && s[i] != '1') {
            return false;
        }
    }

    // Ahora revisamos si es capicúa
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    FILE *f = fopen("ejercicio1.txt", "r");
    if (f == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\n")] = 0; // Quitar salto
        if (es_ejercicio1(linea)) {
            printf("%s => ACEPTA\n", linea);
        } else {
            printf("%s => NO ACEPTA\n", linea);
        }
    }

    fclose(f);
    return 0;
}
