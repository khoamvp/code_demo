#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int MAX_N = 100; // Giới hạn kích thước ma trận

int main()
{
    int n;
    cin >> n;

    vector<int> a[n + 1];
    int ch[MAX_N + 1][MAX_N + 1] = {0}; // Lưu tổng đường chéo chính
    int ph[MAX_N + 1][MAX_N + 1] = {0}; // Lưu tổng đường chéo phụ

    // Nhập ma trận
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    // Tính tổng đường chéo chính (↘)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1)
            {
                ch[i][j] = a[i][j];
            }
            else
            {
                ch[i][j] = a[i][j] + ch[i - 1][j - 1];
            }
        }
    }

    // Tính tổng đường chéo phụ (↙)
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (i == 1 || j == n)
            {
                ph[i][j] = a[i][j];
            }
            else
            {
                ph[i][j] = a[i][j] + ph[i - 1][j + 1];
            }
        }
    }
    // Tìm hiệu số lớn nhất giữa các đường chéo chính và phụ
    int max_sum = INT_MIN;
    for (int i = 2; i <= n; i++)
    { // Bắt đầu từ hàng thứ 2 (tránh chỉ có 1 phần tử)
        for (int j = i; j <= n; j++)
        {
            for (int k = i; k <= n; k++)
            {
                int diff = ch[j][k] - ph[j][k - i + 1];
                max_sum = max(max_sum, diff);
            }
        }
    }

    // In kết quả
    cout << max_sum << endl;
    return 0;
}