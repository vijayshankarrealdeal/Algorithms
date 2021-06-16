#include <iostream>
#include <chrono>

void mergeRoutine(int a[], int b[])
{
    int len_a = sizeof(a) / sizeof(*a);
    int len_b = sizeof(b) / sizeof(*b);
    int i = 0;
    int j;
    int c[len_a + len_b];
    if (len_a == len_b)
    {
        while (i != len_b)
        {
            c[i] = a[i];
        }
    }
}