#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = INT_MAX;
    int n, t, m;
    cin >> n >> t; // Nhập số lượng phần tử
    vector<int> a(n);
    vector<multiset<int>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int c = abs(a[i] + a[j] + a[k] - t);

                if (c <= sum)
                {
                    s.clear();
                    s.push_back({a[i], a[j], a[k]});
                    sum = c;
                    m = a[i] + a[j] + a[k];
                }
                        }
        }
    }
    cout << "bo ba so co tong gan target nhat:" << m << endl;
    for (auto &st : s)
    {
        for (auto num : st)
        {
            cout << num << " ";
        }
    }
    cout << endl;
}
