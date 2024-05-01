#include <iostream>

using namespace std;

void ordenamientoSeleccion(int v[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (v[minIndex] > v[j])
      {
        minIndex = j;
      }
    }
    int temp = v[minIndex];
    v[minIndex] = v[i];
    v[i] = temp;
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

  ordenamientoSeleccion(v, n);

  print(v, n);

  return 0;
}