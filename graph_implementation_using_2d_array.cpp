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

    int n, m, v, temp;
    cin >> n >> m;

    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> temp;
        arr[v - 1][temp - 1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "The vertex " << i + 1 << " has vertexes: \n";
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                cout << j + 1 << endl;
        }
        cout << endl;
    }
}