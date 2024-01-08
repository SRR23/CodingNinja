#include <bits/stdc++.h>
using namespace std;

// Both solution has complexity N^2.
// But space complexity is better in BruteForce

// etai optimal solution, karon array size 1e3. BruteForce e standard
// vector<vector<int>> pairSum(vector<int> &a, int s)
// {
//     vector<vector<int>> v;
//     sort(a.begin(),a.end());
//     for(int i=0;i<a.size();i++)
//     {
//        for(int j=i+1;j<a.size();j++)
//        {
//           if(a[i]+a[j]==s)
//           {
//              v.push_back({{a[i],a[j]}});
//           }
//        }
//     }
//     return v;
// }

vector<vector<int>> pairSum(vector<int> &a, int s)
{
    vector<vector<int>> v;
    unordered_map<int, int> mp, mp2;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
        mp2[a[i]] = i;
    }
    for (int i = 0; i < a.size(); i++)
    {
        int p = a[i];
        int q = s - p;
        if (mp[q] > 0 && p != q)
        {
            if (mp2[p] < mp2[q])
            {
                int x = mp[q];
                if (p > q)
                {
                    swap(p, q);
                }
                while (x--)
                {
                    v.push_back({{p, q}});
                }
            }
        }
        else
        {
            int x = mp[q]-1;
            int y=x*(x+1)/2;
            while (y--)
            {
                v.push_back({{p, q}});
            }
            mp[q]=0;
        }
    }
    sort(v.begin(), v.end());
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
        vector<vector<int>> p = pairSum(v, s);
        for (int i = 0; i < p.size(); i++)
        {
            for (int j = 0; j < p[i].size(); j++)
            {
                cout << p[i][j] << " ";
            }
            cout << '\n';
        }
    }
}