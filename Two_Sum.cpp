#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    unordered_map<int, int> mp;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int p = arr[i];
        int q = target - p;
        if (p != q && mp[p] > 0 && mp[q] > 0)
        {
            v.push_back({p, q});
            mp[q]--;
            mp[p]--;
        }
        else
        {
            if (p == q && mp[p] > 1)
            {
                v.push_back({p, q});
                mp[p] -= 2;
            }
        }
    }
    if (v.size() == 0)
    {
        return vector<pair<int, int>>{{-1, -1}};
    }
    return v;
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
        int n, s;
        cin >> n >> s;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<pair<int, int>> p = twoSum(v, s, n);
        for (auto it : p)
        {
            cout << it.first << " " << it.second << '\n';
        }
    }
}