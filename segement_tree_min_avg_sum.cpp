#include <bits/stdc++.h>
using namespace std;

int makeSumST(vector<int> A, int S[], int sLow, int sHigh, int pos)
{
    if (sLow == sHigh)
    {
        S[pos] = A[sLow];
        return A[sLow];
    }

    int mid = (sLow + sHigh) / 2;
    int prev = makeSumST(A, S, sLow, mid, 2 * pos + 1);
    int later = makeSumST(A, S, mid + 1, sHigh, 2 * pos + 2);
    //S[pos] = makeSumST(A, S, sLow, mid, 2 * pos + 1) + makeSumST(A, S, mid + 1, sHigh, 2 * pos + 2);

    cout << prev << " " << later << endl;
    S[pos] = prev + later;

    return S[pos];
}
int makeMinST(vector<int> A, int S[], int sLow, int sHigh, int pos)
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
int sumQuery(int S[], int sLow, int sHIgh, int qLow, int qHigh, int pos)
{

    if (qLow <= sLow && qHigh >= sHIgh)
        return S[pos];

    if (sHIgh < qLow || sLow > qHigh)
        return 0;

    int mid = (sLow + sHIgh) / 2;
    return sumQuery(S, sLow, mid, qLow, qHigh, 2 * pos + 1) +
           sumQuery(S, mid + 1, sHIgh, qLow, qHigh, 2 * pos + 2);
}
int minQuery(int S[], int sLow, int sHIgh, int qLow, int qHigh, int pos)
{

    if (qLow <= sLow && qHigh >= sHIgh)
        return S[pos];

    if (sHIgh < qLow || sLow > qHigh)
        return INT_MAX;

    int mid = (sLow + sHIgh) / 2;
    return min(minQuery(S, sLow, mid, qLow, qHigh, 2 * pos + 1),
               minQuery(S, mid + 1, sHIgh, qLow, qHigh, 2 * pos + 2));
}
void updateSumST(int S[], int sLow, int sHigh, int diff, int pos, int i)
{
    if (i < sLow || i > sHigh)
        return;

    S[pos] += diff;
    if (sLow != sHigh)
    {
        int mid = (sLow + sHigh) / 2;
        updateSumST(S, sLow, mid, diff, (2 * pos) + 1, i);
        updateSumST(S, mid + 1, sHigh, diff, (2 * pos) + 2, i);
    }
}
void updateMinST(int S[], int sLow, int sHigh, int val, int pos, int i)
{
    if (i < sLow || i > sHigh)
        return;

    if (sLow == sHigh)
        S[pos] = val;
    else
    {
        int mid = (sLow + sHigh) / 2;

        if (i >= sLow && i <= mid)
            updateMinST(S, sLow, mid, val, (2 * pos) + 1, i);
        else
            updateMinST(S, mid + 1, sHigh, val, (2 * pos) + 2, i);

        S[pos] = min(S[(2 * pos) + 1], S[(2 * pos) + 2]);
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

    int n;
    int max_size;

    vector<int> A;
    cin >> max_size;
    for (int i = 0; i < max_size; i++)
    {
        cin >> n;
        A.push_back(n);
    }

    max_size = 2 * (int)pow(2, (int)(ceil(log2(A.size())))) - 1;
    int sumST[max_size];
    int minST[max_size];
    int avgST[max_size];

    makeSumST(A, sumST, 0, A.size() - 1, 0);
    makeMinST(A, minST, 0, A.size() - 1, 0);

    for (int i = 0; i < max_size; i++)
    {
        cout << minST[i] << endl;
    }
    cin >> max_size;
    int l, m;
    for (int i = 0; i < max_size; i++)
    {
        cin >> n >> l >> m;
        if (n == 0)
        {
            int diff = m - A[l - 1];
            A[l - 1] = m;
            updateSumST(sumST, 0, A.size() - 1, diff, 0, l - 1);
            updateMinST(minST, 0, A.size() - 1, m, 0, l - 1);
        }
        else if (n == 1)
        {
            cout << sumQuery(sumST, 0, A.size() - 1, l - 1, m - 1, 0);
            cout << endl;
        }
        else if (n == 2)
        {
            cout << minQuery(minST, 0, A.size() - 1, l - 1, m - 1, 0);
            cout << endl;
        }
        else if (n == 3)
        {
            cout << sumQuery(sumST, 0, A.size() - 1, l - 1, m - 1, 0) / (m - l + 1);
            cout << endl;
        }
    }
}