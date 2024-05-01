#include <iostream>
#include <string.h>
using namespace std;

const int numeroLetrasAbecedario = 26; // abecedario ingles


void iniciarConteoLetras(int conteoLetras[])
{
    for (int i = 0; i < numeroLetrasAbecedario; i++)
        conteoLetras[i] = 0;
}

int obtenerIndice(char letra)
{
    if (letra >= 'a' && letra <= 'z')
        return letra - 'a';
    return -1;
}

void rellenarConteoLetras(char palabra[], int longitud, int conteoLetras[])
{
    for (int i = 0; i < longitud; i++)
    {
        int indice = obtenerIndice(palabra[i]);
        conteoLetras[indice]++;
    }
}

bool esAlfagrama(char palabra1[], char palabra2[])
{
    int longitud1 = strlen(palabra1);
    int longitud2 = strlen(palabra2);

    if (longitud1 != longitud2)
        return false;

    // letras: a b ... z (26 letras)
    int conteoLetras1[numeroLetrasAbecedario];
    int conteoLetras2[numeroLetrasAbecedario];

    // iniciar contadores a 0
    iniciarConteoLetras(conteoLetras1);
    iniciarConteoLetras(conteoLetras2);

    rellenarConteoLetras(palabra1, longitud1, conteoLetras1);
    rellenarConteoLetras(palabra2, longitud2, conteoLetras2);

    // número de cantidad de letras igual
    for (int i = 0; i < numeroLetrasAbecedario; i++)
        if (conteoLetras1[i] != conteoLetras2[i])
            return false;

    // orden alfabetico
    for (int i = 0; i < longitud2 - 1; i++)
        if (palabra2[i] > palabra2[i + 1])
            return false;

    return true;
}

int main()
{
    char palabra1[30] = "hola";
    char palabra2[30] = "aloh";

    bool respuesta = esAlfagrama(palabra1, palabra2);

    if (respuesta)
        cout << "La palabra " << palabra1 << " es un alfagrama de " << palabra2 << "." << endl;
    else
        cout << "La palabra " << palabra1 << " NO es un alfagrama de " << palabra2 << "." << endl;
    return 0;
}