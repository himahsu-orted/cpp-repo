#include <bits/stdc++.h>
using namespace std;
void permutation(string a, int l, int r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permutation(a, l + 1, r);
            swap(a[l], a[i]);
        }
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

    string a;
    cin >> a;
    permutation(a, 0, a.size() - 1);
}