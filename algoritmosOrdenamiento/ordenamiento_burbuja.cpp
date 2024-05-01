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

  print(v, n);

  return 0;
}