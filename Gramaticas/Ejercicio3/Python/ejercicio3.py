# L(G3) = { a^n b^(n+1) | n > 0 }

def es_ejercicio3(cadena):
    i = 0
    a_count = 0

    # Contar 'a'
    while i < len(cadena) and cadena[i] == "a":
        a_count += 1
        i += 1

    b_count = 0
    # Contar 'b'
    while i < len(cadena) and cadena[i] == "b":
        b_count += 1
        i += 1

    # Si queda otro símbolo, no pertenece
    if i != len(cadena):
        return False

    # Condición: n > 0 y b = a + 1
    return a_count > 0 and b_count == a_count + 1

def procesar(archivo):
    with open(archivo, "r") as f:
        for linea in f:
            cad = linea.strip()
            if es_ejercicio3(cad):
                print(cad, "=> ACEPTA")
            else:
                print(cad, "=> NO ACEPTA")

if __name__ == "__main__":
    procesar("ejercicio3.txt")
