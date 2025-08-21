# Solo acepta exactamente "abb" o "ab"

def es_ejercicio4(cadena):
    if cadena == "abb" or cadena == "ab":
        return True
    else:
        return False

def procesar(archivo):
    with open(archivo, "r") as f:
        for linea in f:
            cad = linea.strip()
            if es_ejercicio4(cad):
                print(cad, "=> ACEPTA")
            else:
                print(cad, "=> NO ACEPTA")

if __name__ == "__main__":
    procesar("ejercicio4.txt")
