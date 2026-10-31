#include <iostream>
#include <vector>
using namespace std;

// last visited cell in a matrix
int main()
{
    int n = 3, m = 4;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int i = 0, j = 0;
    string s = "RRDLLD";
    for (char c : s)
    {
        if (c == 'R')
        {
            j++;
        }
        else if (c == 'L')
        {
            j--;
        }
        else if (c == 'U')
        {
            i--;
        }
        else if (c == 'D')
        {
            i++;
        }

        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            cout << "Out of bounds" << endl;
            return 0;
        }
    }

    cout << "Last visited cell: (" << i << ", " << j << ")" << endl;

    return 0;
}