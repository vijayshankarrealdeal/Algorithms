#include <iostream>

void insertSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        if (a[key] < a[i - 1])
        {
            for (int j = i; j > 0; j--)
            {
                std::swap(a[j], a[key]);
            }
        }
    }
}

int main()
{
    int a[20];
    int n = sizeof(a) / sizeof(*a);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << "\n";
    insertSort(a, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << "\n";
}