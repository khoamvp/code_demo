#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
int minnn(int c, int b) { return (c > b) ? b : c; } // toan tu 3 ngoi
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
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                a[i][j] = a[i][j];
            }
            if (i == 0)
            {
                a[i][j] += a[i][j - 1];
            }
            if (j == 0)
                a[i][j] += a[i - 1][j];
            else
                a[i][j] += minnn(a[i - 1][j], a[i][j - 1]);
        }
    }
    int sum = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        sum = minnn(a[n - 1][j], sum);
    }
    cout << sum;
}
// 1 6 5 7
// 2 4 1 9
// 3 2 2 5
// 5 8 1 7
// 1 3 1
// 1 5 1
// 4 2 1