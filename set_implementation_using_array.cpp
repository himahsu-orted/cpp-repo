#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int x, y, w;

} * VN;
int find(vector<int> S, int x)
{
    if (S[x] == -1)
        return x;
    else
    {
        return find(S, S[x]);
    }
}
void insert(vector<int> &S, int x, int y)
{
    if (S[x] == -1)
        S[x] = y;
    else if (S[y] == -1)
        S[y] = x;
    else
        S[find(S, x)] = find(S, y);
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

    int n;
    cin >> n;
    vector<int> S(n, -1);
}
