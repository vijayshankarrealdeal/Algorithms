#include <iostream>
#include <chrono>

void heap(int a[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = left;
    }
    if (largest != i)
    {
        a[i], a[largest] = a[largest], a[i];
        heap(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heap(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        a[0], a[i] = a[i], a[0];
        heap(a, i, 0);
    }
}

int main()

{

    using std::chrono::duration;
    using std::chrono::high_resolution_clock;
    int a[500000];
    int n = sizeof(a) / sizeof(*a);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    std::cout << "Start Time.................................."
              << "\n";
    auto t1 = high_resolution_clock::now();
    heapsort(a, n);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2-t1;
    std::cout << "Time\t" << float(ms_double.count()) << "\t milisec";
    std::cout << "\n";
    std::cout << "Time\t" << float(ms_double.count() / 1000) << "\t sec";
    std::cout << "\n";
    std::cout << "End Time..................................";
    std::cout << "\n";
}