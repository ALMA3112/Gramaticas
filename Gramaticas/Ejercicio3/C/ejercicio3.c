#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// L(G3) = { a^n b^(n+1) | n > 0 }
bool es_ejercico3(char *s) {
    int i = 0, a = 0, b = 0;

    while (s[i] == 'a') {
        a++;
        i++;
    }
    while (s[i] == 'b') {
        b++;
        i++;
    }

    if (s[i] != '\0') return false;

    return (a > 0 && b == a + 1);
}

int main() {
    FILE *f = fopen("ejercicio3.txt", "r");
    if (!f) {
        printf("Error al abrir g3.txt\n");
        return 1;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\n")] = 0;
        if (es_ejercico3(linea)) printf("%s => ACEPTA\n", linea);
        else printf("%s => NO ACEPTA\n", linea);
    }
    fclose(f);
    return 0;
}
