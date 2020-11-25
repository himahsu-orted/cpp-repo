#include <bits/stdc++.h>
using namespace std;
#define min(x, y, z) min(min(x, y), z)

int editDistance(string a, string b)
{
    int m = a.length(), n = b.length();
    int dp[m + 1][n + 1];

    // filling base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    // populating matrix using dp-approach
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] != b[j - 1])
            {
                dp[i][j] = min(1 + dp[i - 1][j],    // deletion
                               1 + dp[i][j - 1],    // insertion
                               1 + dp[i - 1][j - 1] // replacement
                );
            }
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << editDistance("sort", "sport");
}