#include <iostream>
#include<chrono>
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
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    int a[80000];
    int n = sizeof(a) / sizeof(*a);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    std::cout<<"Start Time.................................."<<"\n";
    auto t1 = high_resolution_clock::now();
    insertSort(a, n);
    auto t2 = high_resolution_clock::now();
    std::cout<<"End Time.................................."<<"\n";
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << float(ms_double.count()/1000) << "s";
    std::cout << "\n";
}