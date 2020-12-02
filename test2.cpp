#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> a;

    vector<int> b = {9, 64, 56, 9};
    vector<int> c = {1, 2, 3, 4, 66, 45, 234};
    vector<int> d = {6, 7, 8};
    a.push_back(b);
    a.push_back(c);
    a.push_back(d);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    make_heap(a.begin(), a.end());

    cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}