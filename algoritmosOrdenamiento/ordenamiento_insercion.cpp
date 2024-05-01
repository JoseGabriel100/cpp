#include <iostream>

using namespace std;

void ordenamientoInsercion(int v[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int pos = i;
    int aux = v[i];

    while (pos > 0 && v[pos - 1] > aux)
    {
      v[pos] = v[pos - 1];
      pos--;
    }

    v[pos] = aux;
  }
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

  ordenamientoInsercion(v, n);

  print(v, n);

  return 0;
}