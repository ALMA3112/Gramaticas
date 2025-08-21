#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// L(G2) = { a^n b^(n+1) | n >= 0 }
bool es_ejercicio2(char *s) {
    int i = 0;
    int a = 0;
    int b = 0;

    // Contar 'a' del inicio
    while (s[i] == 'a') {
        a++;
        i++;
    }

    // Contar 'b' que siguen
    while (s[i] == 'b') {
        b++;
        i++;
    }

    // Si hay otros símbolos, no pertenece
    if (s[i] != '\0') {
        return false;
    }

    // Regla: b = a + 1
    return (b == a + 1);
}

int main() {
    FILE *f = fopen("ejercicio2.txt", "r");
    if (!f) {
        printf("Error al abrir g2.txt\n");
        return 1;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        // quitar salto de línea
        linea[strcspn(linea, "\n")] = 0;

        if (es_ejercicio2(linea)) {
            printf("%s => ACEPTA\n", linea);
        } else {
            printf("%s => NO ACEPTA\n", linea);
        }
    }

    fclose(f);
    return 0;
}
