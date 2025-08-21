#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// L(G5) = { a (ab)^n b | n >= 0 }
bool es_ejercicio5(char *s) {
    int n = strlen(s);

    if (n < 2) return false;

    if (s[0] != 'a' || s[n-1] != 'b') {
        return false;
    }

    int i = 1;
    while (i < n-1) {
        if (s[i] == 'a' && s[i+1] == 'b') {
            i += 2;
        } else {
            return false;
        }
    }

    return i == n-1;
}

int main() {
    FILE *f = fopen("ejercicio5.txt", "r");
    if (!f) {
        printf("Error al abrir ejercicio5.txt\n");
        return 1;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\n")] = 0;
        if (es_ejercicio5(linea)) printf("%s => ACEPTA\n", linea);
        else printf("%s => NO ACEPTA\n", linea);
    }
    fclose(f);
    return 0;
}
