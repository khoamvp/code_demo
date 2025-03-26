#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
int maxx(int c, int b) { return (c > b) ? c : b; } // toan tu 3 ngoi
// {
//     int max;
//     if (a > b)
//         max = a;
//     else
//         max = b;
//     return max;
// }
using namespace std;
int main()
{

    int m, n;
    cin >> n >> m;
    vector<int> a[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                a[i][j] += maxx(a[i - 1][j], a[i - 1][j + 1]);
            }
            else if (j == m - 1)
            {
                a[i][j] += maxx(a[i - 1][j], a[i - 1][j - 1]);
            }
            else
                a[i][j] += maxx(maxx(a[i - 1][j], a[i - 1][j - 1]), a[i - 1][j + 1]);
        }
    }
    int sum = INT_MIN;
    cout << *max_element(a[n - 1], a[n - 1] + m);
}