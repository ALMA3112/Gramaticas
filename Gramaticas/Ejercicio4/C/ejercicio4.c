#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Solo acepta exactamente "abb" o "ab"
bool es_ejercicio4(char *s) {
    if (strcmp(s, "abb") == 0 || strcmp(s, "ab") == 0) {
        return true;
    }
    return false;
}

int main() {
    FILE *f = fopen("ejercicio4.txt", "r");
    if (f == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\n")] = 0;
        if (es_ejercicio4(linea)) {
            printf("%s => ACEPTA\n", linea);
        } else {
            printf("%s => NO ACEPTA\n", linea);
        }
    }

    fclose(f);
    return 0;
}
