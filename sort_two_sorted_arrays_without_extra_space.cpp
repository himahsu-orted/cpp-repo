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

    int X[] = {1, 4, 7, 8, 10};
    int Y[] = {2, 3, 9};
    int a = sizeof(X) / sizeof(X[0]);
    int b = sizeof(Y) / sizeof(Y[0]);
    for (int i = b - 1; i >= 0; i--)
    {
        int j;
        int last = X[a - 1];
        for (j = a - 2; j >= 0 && X[j] > Y[i]; j--)
            X[j + 1] = X[j];

        if (j != a - 2 || last > Y[i])
        {
            X[j + 1] = Y[i];
            Y[i] = last;
        }
    }
    for (int i = 0; i < a; i++)
        cout << X[i] << " ";
    for (int i = 0; i < b; i++)
        cout << Y[i] << " ";
}