# L(G5) = { a (ab)^n b | n >= 0 }

def es_ejercicio5(cadena):
    if len(cadena) < 2:
        return False

    # Debe empezar en 'a' y terminar en 'b'
    if not (cadena[0] == "a" and cadena[-1] == "b"):
        return False

    # Quitamos la primera y la última letra
    medio = cadena[1:-1]

    # Revisamos que esté compuesto únicamente por repeticiones de "ab"
    i = 0
    while i < len(medio):
        if i + 1 < len(medio) and medio[i] == "a" and medio[i+1] == "b":
            i += 2
        else:
            return False

    return True

def procesar(archivo):
    with open(archivo, "r") as f:
        for linea in f:
            cad = linea.strip()
            if es_ejercicio5(cad):
                print(cad, "=> ACEPTA")
            else:
                print(cad, "=> NO ACEPTA")

if __name__ == "__main__":
    procesar("ejercicio5.txt")
