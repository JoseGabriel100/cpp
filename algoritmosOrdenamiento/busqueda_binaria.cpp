#include <iostream>

using namespace std;

void ordenamientoBurbuja(int v[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (v[j] > v[j + 1])
      {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

int busquedaBinaria(int v[], int n, int valor)
{
  int sup = n - 1, medio, inf = 0;
  medio = (sup + inf) / 2;

  while (inf <= sup)
  {
    cout << inf << ", " << medio << ", " << sup << endl;
    if (v[medio] == valor)
    {
      return medio;
    }

    if (v[medio] < valor)
    {
      inf = medio + 1;
    }
    else
    {
      sup = medio - 1;
    }
    medio = (inf + sup) / 2;
  }
  return -1;
}

void print(int v[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int v[] = {5, 4, 3, 2, 1};
  int n = sizeof(v) / sizeof(v[0]);

  ordenamientoBurbuja(v, n);

  int valor = 2;
  int pos = busquedaBinaria(v, n, valor);
  if (pos != -1)
  {
    cout << "El numero " << valor << " fue encontrado en la posicion " << pos << endl;
  }
  else
  {
    cout << "El numero " << valor << " no fue encontrado" << endl;
  }

  print(v, n);

  return 0;
}