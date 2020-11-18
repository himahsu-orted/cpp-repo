#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int min;
    int max;
    int sum;
} * stn;
int makeMinST(int A[], int S[], int sLow, int sHigh, int pos)
{
    if (sLow == sHigh)
    {
        S[pos] = A[sLow];
        return A[sLow];
    }

    int mid = (sLow + sHigh) / 2;
    S[pos] = min(makeMinST(A, S, sLow, mid, 2 * pos + 1), makeMinST(A, S, mid + 1, sHigh, 2 * pos + 2));

    return S[pos];
}
int minQuery(int S[], int sLow, int sHigh, int qLow, int qHigh, int pos)
{
    if (qLow <= sLow && qHigh >= sHigh)
        return S[pos];

    if (sHigh < qLow || sLow > qHigh)
        return INT_MAX;

    int mid = (sLow + sHigh) / 2;
    return min(minQuery(S, sLow, mid, qLow, qHigh, 2 * pos + 1),
               minQuery(S, mid + 1, sHigh, qLow, qHigh, 2 * pos + 2));
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

    int n, i;
    cin >> n;
    int A[n];
    for (i = 0; i < n; i++)
        cin >> A[i];

    cin >> n;
    int B[n];
    for (i = 0; i < n; i++)
        cin >> B[i];

    int size = 2 * (int)pow(2, (int)(ceil(log2(n)))) - 1;
    int AST[size];
    int BST[size];

    makeMinST(A, AST, 0, n - 1, 0);
    makeMinST(B, BST, 0, n - 1, 0);

    //cout << minQuery(AST, 0, n - 1, 0, 1, 0);
    for (i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (minQuery(AST, 0, n - 1, i, j, 0) == minQuery(BST, 0, n - 1, i, j, 0))
                if (i != j)
                    cout << i << " " << j << endl;
        }
    }
}