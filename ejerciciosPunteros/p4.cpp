#include <iostream>

using namespace std;

int main()
{
    // número
    int n;
    // puntero que almacena la dirección de memoria del número
    int *p = &n;

    cout << "Digite un numero: ";
    cin >> *p;

    cout << "numero: " << *p << endl;

    return 0;
}