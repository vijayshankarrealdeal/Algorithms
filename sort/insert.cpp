#include <iostream>

void insertSort(int a[], int n)
{
    int i =1;
   while (i<n)
   {
        int key = i;
        if (a[key] < a[i - 1])
        {

            for (int j = i-1; j >= 0; j--)
            {
                if(a[key] < a[j])
                {
                    std::swap(a[j], a[key]);
                    key = j;
                }
            }
            i++;
        }else{
            i++;
        }
    }
}

int main()
{
    int a[217];
    int n = sizeof(a) / sizeof(*a);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << "\n"<<"Sorted List-------------------------"<<"\n";
    insertSort(a, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << "\n";
}