# Este programa revisa si las cadenas que están en el archivo g1.txt
# son números capicúas formados únicamente por los símbolos 0 y 1.

def es_ejercicio1(cadena):
    # Recorremos cada caracter de la cadena y verificamos que sea 0 o 1
    for caracter in cadena:
        if caracter != "0" and caracter != "1":
            # Si aparece otro símbolo, ya no pertenece al lenguaje
            return False
    
    # Revisamos si la cadena es igual de adelante hacia atrás y de atrás hacia adelante
    if cadena == cadena[::-1]:
        return True
    else:
        return False

def procesar(archivo):
    # Abrimos el archivo de prueba
    with open(archivo, "r") as f:
        for linea in f:
            # Quitamos espacios en blanco y saltos de línea
            cad = linea.strip()
            # Verificamos con la función
            if es_ejercicio1(cad):
                print(cad, "=> ACEPTA")
            else:
                print(cad, "=> NO ACEPTA")

if __name__ == "__main__":
    procesar("ejercicio1.txt")
