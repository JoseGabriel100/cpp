#include <iostream>

using namespace std;

void intercambiar(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void intercambiar(int n1, int n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    int n1 = 5;
    int n2 = 10;

    cout << "Numero 1: " << n1 << endl;
    cout << "Numero 2: " << n2 << endl;

    intercambiar(&n1, &n2);
    // intercambiar(n1, n2);

    cout << "Despues del intercambio" << endl;
    cout << "Numero 1: " << n1 << endl;
    cout << "Numero 2: " << n2 << endl;

    // observación: si realizas la función "intercambiar" sin punteros,
    // el valor de n1 y n2 no cambiarán, porque solo estás pasando los valores,
    // no la dirección de memoria (la variable)
    return 0;
}