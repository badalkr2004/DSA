// Permutation in a string

#include <iostream>
#include <string>
using namespace std;

bool isMatched(int map1[], int map2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (map1[i] != map2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1 = "aib";
    string s2 = "eidbaooo";

    int n = s1.length();
    int m = s2.length();
    if (n > m)
    {
        cout << "Not possible to find";
        return 0;
    }

    int map1[26] = {0};
    for (int i = 0; i < n; i++)
    {
        map1[s1[i] - 'a']++;
    }

    for (int i = 0; i <= m - n; i++)
    {
        int map2[26] = {0};
        for (int j = 0; j < n; j++)
        {
            map2[s2[i + j] - 'a']++;
        }

        if (isMatched(map1, map2))
        {
            cout << "yes available";
            return 0;
        }
    }
    cout << "not available";

    return 0;
}