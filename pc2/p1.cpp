#include <iostream>
using namespace std;

// programación dinamica
int valores[100];

int padovan(int *p)
{
    if (*p <= 2)
        return 1;

    int nminus2 = *p - 2;
    int nminus3 = *p - 3;

    // programación dinámica
    if (valores[*p] != 0)
        return valores[*p];

    return padovan(&nminus2) + padovan(&nminus3);
}

void mostarSusecionPadovan(int *p)
{
    for (int i = 0; i < *p; i++)
        cout << padovan(&i) << " ";
    cout << endl;
}

int main()
{
    int n = 10;
    mostarSusecionPadovan(&n);

    return 0;
}