#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                smallestIdx = j;
            }
        }
        swap(arr[smallestIdx], arr[i]);
    }
}

int main()
{
    int arr[] = {3, 2, 5, 1, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    selectionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}