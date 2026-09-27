#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, long long mid)
{

    int studentCount = 1;
    long long pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;

        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;

            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> &arr, int m)
{
    int n = arr.size();
    if (m > n)
        return -1;
    int st = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    long long end = sum;
    int ans = -1;

    while (st <= end)
    {
        long long mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
}