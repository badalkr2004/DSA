#include <iostream>
#include <vector>
using namespace std;

// Implement the painter_partition method here
bool isValid(vector<int> &arr, int n, int m, int mid)
{
    if (m > n)
        return false;

    int painter = 1;
    int timeSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (timeSum + arr[i] <= mid)
        {
            timeSum += arr[i];
        }
        else
        {
            painter++;
            timeSum = arr[i];
        }
    }

    return painter > m ? false : true;
}

int painter_partition(vector<int> &arr, long long m)
{
    long long n = arr.size();

    long long start = 0;
    long long end = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        end += arr[i];
        start = max(start, (long long)arr[i]);
    }

    while (start <= end)
    {

        long long mid = start + (end - start) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // Write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int N, k;
        cin >> N >> k;
        vector<int> boards(N);
        for (int i = 0; i < N; i++)
            cin >> boards[i];

        cout << painter_partition(boards, k) << endl;
    }
    return 0;
}