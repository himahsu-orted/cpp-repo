#include <bits/stdc++.h>
using namespace std;

void reFunc(string p, string q, int pos, string &r)
{
    if (pos > -1)
    {
        reFunc(p, q, pos - 1, r);
        r += p[pos];
        r += q[pos];
    }
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

    string p, q, r = "";
    cin >> p >> q;
    reFunc(p, q, p.size() - 1, r);
    cout << r;
}
