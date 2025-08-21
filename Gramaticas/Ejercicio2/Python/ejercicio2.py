# L(G2) = { a^n b^(n+1) | n >= 0 }
# Idea: contar cuántas 'a' hay al inicio, luego cuántas 'b' siguen,
# y verificar que no haya otros símbolos y que b = a + 1.

def es_ejercicio2(cadena):
    i = 0
    a_count = 0

    # Contar 'a' iniciales
    while i < len(cadena) and cadena[i] == "a":
        a_count += 1
        i += 1

    # Contar 'b' después de las 'a'
    b_count = 0
    while i < len(cadena) and cadena[i] == "b":
        b_count += 1
        i += 1

    # Si quedó algún otro símbolo, no pertenece
    if i != len(cadena):
        return False

    # Regla: debe haber exactamente una 'b' más que 'a'
    return b_count == a_count + 1

def procesar(archivo):
    with open(archivo, "r") as f:
        for linea in f:
            cad = linea.strip()
            if es_ejercicio2(cad):
                print(cad, "=> ACEPTA")
            else:
                print(cad, "=> NO ACEPTA")

if __name__ == "__main__":
    procesar("ejercicio2.txt")
