#include <iostream>
#include <chrono>

void merge(int arr[], int lb, int mid, int ub)
{
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[lb + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = lb;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    if (j > n2)

    {
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

void mergeSort(int arr[], int lb, int ub)
{
    if (lb >= ub)
    {
        return;
    }
    int mid = lb + (ub - lb) / 2;
    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, ub);
    merge(arr, lb, mid, ub);
}

int main()
{

    using std::chrono::duration;
    using std::chrono::high_resolution_clock;
    int a[100000];
    int arr_size = sizeof(a) / sizeof(*a);
    std::cout << "Start Time.................................."
              << "\n";
    auto t1 = high_resolution_clock::now();
    mergeSort(a, 0, arr_size - 1);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "Time\t" << float(ms_double.count()) << "\t milisec";
    std::cout << "\n";
    std::cout << "Time\t" << float(ms_double.count() / 1000) << "\t sec";
    std::cout << "\n";
    std::cout << "End Time.................................."
              << "\n";
    std::cout << "\n";
}
