#include <bits/stdc++.h>
using namespace std;

// Modifying Array IN-PLACE
// Time=O(N)
// space=O(1)
// Because array elements are between 1 and n-1
// int findDuplicate(vector<int> &a, int n)
// {

//     for (int i = 0; i < n; i++)
//     {
//         int idx = abs(a[i]) - 1;
//         a[idx] *= -1;
//         if (a[idx] > 0)
//         {
//             return abs(a[i]);
//         }
//     }
//     return -1;
// }

// Time=O(N)
// Space=O(N)
int findDuplicate(vector<int> &a, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        if (mp[a[i]] > 1)
        {
            return a[i];
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << findDuplicate(a, n) << '\n';
    }
}