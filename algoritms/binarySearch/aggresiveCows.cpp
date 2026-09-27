#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{

    int cows = 1;
    int lastStallPos = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastStallPos >= mid)
        {
            cows++;
            lastStallPos = arr[i];
        }

        if (cows == m)
        {
            return true;
        }
    }
    return false;
}

int aggressvieCows(vector<int> &arr, int m)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int st = 0;
    int end = arr[n - 1] - arr[0];
    int ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << aggressvieCows(stalls, cows) << endl;
    return 0;
}