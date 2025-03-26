#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // Nhập số lượng phần tử
    vector<int> a(n);
    vector<multiset<int>> s; // Danh sách các tập hợp hợp lệ

    // Nhập mảng a
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sắp xếp mảng để dễ loại bỏ trùng lặp
    // Tìm các bộ ba có tổng bằng 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i] + a[j] + a[k] == 0)
                {
                    multiset<int> temp = {a[i], a[j], a[k]};

                    // Kiểm tra nếu `temp` đã tồn tại trong `s`
                    bool found = false;
                    for (auto xx : s)
                    {
                        if (xx == temp)
                        {
                            found = true;
                            break;
                        }
                    }

                    if (found == false)
                    {
                        s.push_back(temp);
                    }
                }
            }
        }
    }

    // In các bộ ba hợp lệ
    cout << "Cac bo ba co tong bang 0:\n";
    for (auto st : s)
    {
        cout << "[";
        for (int num : st)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
}
// dùng insert vector
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // Dùng `set<vector<int>>` để tránh bộ ba trùng lặp
//     set<vector<int>> s;

//     for (int i = 0; i < n ; i++)
//     {
//         for (int j = 0; j < n ; j++)
//         {
//             for (int k =0; k < n; k++)
//             {
//                 if (a[i] + a[j] + a[k] == 0)
//                 {
//                     s.insert({a[i], a[j], a[k]});
//                 }
//             }
//         }
//     }

//     // In kết quả
//     cout << "Cac bo ba co tong bang 0:\n";
//     for (aauto st : s)
//     {
//         for (int num : st)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
// }
