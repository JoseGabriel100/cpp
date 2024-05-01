#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int filas = 4;
const int cols = 5;

int **reservarMemoria()
{
    int **p = new int *[filas];

    for (int i = 0; i < filas; i++)
        p[i] = new int[cols];

    return p;
}

int *reservarMemoria(int longitud)
{
    return new int[longitud];
}

void liberarMemoria(int **p)
{
    for (int i = 0; i < filas; i++)
        delete p[i];
    delete[] p;
}

void liberarMemoria(int *p)
{
    delete[] p;
}

void iniciarTablero(int **tablero)
{
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            tablero[i][j] = rand() % 2;
}

void mostrarTablero(int **tablero)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}

int moverNorte(int fila)
{
    if (fila == 0)
        return filas - 1; // última fila
    return fila - 1;
}

int moverSur(int fila)
{
    if (fila == filas - 1)
        return 0;
    return fila + 1;
}

int moverEste(int col)
{
    if (col == cols - 1)
        return 0;
    return col + 1;
}

int moverOeste(int col)
{
    if (col == 0)
        return cols - 1;
    return col - 1;
}

int *mover(int **tablero, char letra, int fila, int col)
{
    // siguiente fila, siguiente columna
    int *posicion = reservarMemoria(2);

    switch (letra)
    {
    case 'n':
        fila = moverNorte(fila);
        break;
    case 's':
        fila = moverSur(fila);
        break;
    case 'e':
        col = moverEste(col);
        break;
    case 'o':
        col = moverOeste(col);
        break;
    }

    posicion[0] = fila;
    posicion[1] = col;

    return posicion;
}

bool esMovimiento(char letra)
{
    return letra == 'n' || letra == 's' || letra == 'e' || letra == 'o' ||
           letra == 'N' || letra == 'S' || letra == 'E' || letra == 'O';
}

void recorrido(int **tablero, int fila, int col, string mensaje)
{
    int *posicion;
    int puntos = 0;
    puntos += tablero[fila][col];
    // puntuacion cero al ya pasar por esa posición
    tablero[fila][col] = 0;

    cout << "Ruta: (" << fila << "," << col << ") ";

    for (int i = 0; i < mensaje.length(); i++)
    {
        if (esMovimiento(mensaje[i]))
        {
            posicion = mover(tablero, mensaje[i], fila, col);
            fila = posicion[0];
            col = posicion[1];
            cout << " (" << fila << "," << col << ") ";
            puntos += tablero[fila][col];

            // puntuacion cero al ya pasar por esa posición
            tablero[fila][col] = 0;
        }
    }

    liberarMemoria(posicion);

    cout << "\nTotal ganado: " << puntos << endl;
}

int main()
{

    srand(time(NULL));

    int **tablero;
    int fila = 3;
    int col = 3;
    string mensaje = "el joven de pecaS usa el asNo";

    tablero = reservarMemoria();

    iniciarTablero(tablero);
    mostrarTablero(tablero);
    recorrido(tablero, fila, col, mensaje);
    liberarMemoria(tablero);

    return 0;
}