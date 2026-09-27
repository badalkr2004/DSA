#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}
int main()
{

    int arr[] = {3, 2, 5, 1, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}