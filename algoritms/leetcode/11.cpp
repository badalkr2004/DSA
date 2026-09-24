// 11. Container with most water

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
int maxArea(vector<int> &height)
{
    int maxWater = 0;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int w = j - i;
            int h = min(height[i], height[j]);
            int area = w * h;
            maxWater = max(maxWater, area);
        }
    }

    return maxWater;
}

// optimised approach
int maxArea2(vector<int> &height)
{
    int maxWater = 0;

    int i = 0;
    int j = height.size() - 1;

    while (i < j)
    {
        int w = j - i;
        int h = min(height[i], height[j]);
        int area = w * h;

        maxWater = max(maxWater, area);
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxWater;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    cout << maxArea2(height) << endl;
    return 0;
}
