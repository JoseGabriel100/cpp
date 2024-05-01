#include <iostream>
#include <string>

using namespace std;

const int numeroNombres = 5;

void ingresarNombres(string nombres[])
{
    for (int i = 0; i < numeroNombres; i++)
    {
        cout << "Ingresar alumno " << i + 1 << ": ";
        getline(cin, nombres[i]);
    }
}

void mostrarListaAlumnos(string nombres[])
{
    cout << "La lista de alumnos ingresados es " << endl;
    for (int i = 0; i < numeroNombres; i++)
        cout << nombres[i] << endl;
}

string mayusculaLetraInicial(string nombre)
{
    nombre[0] = toupper(nombre[0]);
    return nombre;
}

void mayusculaLetraInicial(string nombres[])
{
    for (int i = 0; i < numeroNombres; i++)
        nombres[i] = mayusculaLetraInicial(nombres[i]);
}

bool buscarNombre(string nombre, string nombres[])
{
    for (int i = 0; i < numeroNombres; i++)
        if (nombre.compare(nombres[i]) == 0)
            return true;
    return false;
}

int main()
{
    string nombres[numeroNombres];
    string nombreBuscar;

    // nombres
    ingresarNombres(nombres);
    mostrarListaAlumnos(nombres);
    mayusculaLetraInicial(nombres);
    mostrarListaAlumnos(nombres);

    cout << "Ingrese el nombre a buscar: ";
    getline(cin, nombreBuscar);

    nombreBuscar = mayusculaLetraInicial(nombreBuscar);

    bool respuesta = buscarNombre(nombreBuscar, nombres);

    if (respuesta)
        cout << "El nombre se encuentra en la lista" << endl;
    else
        cout << "El nombre NO se encuentra en la lista" << endl;

    return 0;
}