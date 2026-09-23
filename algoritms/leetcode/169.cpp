// Majority Element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int withSorting()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int n = nums.size();

    sort(nums.begin(), nums.end());
    int freq = 1, ans = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }

        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

int moores()
{
    vector<int> nums = {2, 4, 5, 6, 8};
    int n = nums.size();

    int freq = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {

        if (freq == 0)
        {
            ans = nums[i];
        }

        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    int count = 0;

    for (int val : nums)
    {
        if (ans == val)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return ans;
    }
    else
    {
        return -1;
    }
    return ans;
}
int main()
{

    // cout << withSorting();
    cout << moores();

    return 0;
}