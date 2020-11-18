#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int min;
    int max;
    int sum;
} * stn;
stn makeAll(vector<int> A, stn S[], int sLow, int sHigh, int pos)
{
    if (sLow == sHigh)
    {
        S[pos]->max = A[sLow];
        S[pos]->min = A[sLow];
        S[pos]->sum = A[sLow];
        return S[pos];
    }

    int mid = (sLow + sHigh) / 2;
    stn prev = makeAll(A, S, sLow, mid, 2 * pos + 1);
    stn later = makeAll(A, S, mid + 1, sHigh, 2 * pos + 2);
    S[pos]->min = min(prev->min, later->min);
    S[pos]->max = max(prev->max, later->max);
    S[pos]->sum = prev->sum + later->sum;

    return S[pos];
}
int sumQuery(stn S[], int sLow, int sHIgh, int qLow, int qHigh, int pos)
{

    if (qLow <= sLow && qHigh >= sHIgh)
        return S[pos]->sum;

    if (sHIgh < qLow || sLow > qHigh)
        return 0;

    int mid = (sLow + sHIgh) / 2;
    return sumQuery(S, sLow, mid, qLow, qHigh, 2 * pos + 1) +
           sumQuery(S, mid + 1, sHIgh, qLow, qHigh, 2 * pos + 2);
}
int minQuery(stn S[], int sLow, int sHIgh, int qLow, int qHigh, int pos)
{

    if (qLow <= sLow && qHigh >= sHIgh)
        return S[pos]->min;

    if (sHIgh < qLow || sLow > qHigh)
        return INT_MAX;

    int mid = (sLow + sHIgh) / 2;
    return min(minQuery(S, sLow, mid, qLow, qHigh, 2 * pos + 1),
               minQuery(S, mid + 1, sHIgh, qLow, qHigh, 2 * pos + 2));
}
int maxQuery(stn S[], int sLow, int sHIgh, int qLow, int qHigh, int pos)
{

    if (qLow <= sLow && qHigh >= sHIgh)
        return S[pos]->max;

    if (sHIgh < qLow || sLow > qHigh)
        return INT_MIN;

    int mid = (sLow + sHIgh) / 2;
    return max(maxQuery(S, sLow, mid, qLow, qHigh, 2 * pos + 1),
               maxQuery(S, mid + 1, sHIgh, qLow, qHigh, 2 * pos + 2));
}
void updateS(stn S[], int sLow, int sHigh, int diff, int pos, int i)
{
    if (i < sLow || i > sHigh)
        return;

    S[pos]->sum += diff;
    if (sLow != sHigh)
    {
        int mid = (sLow + sHigh) / 2;
        updateS(S, sLow, mid, diff, (2 * pos) + 1, i);
        updateS(S, mid + 1, sHigh, diff, (2 * pos) + 2, i);
    }
}
void updateMinMaxST(stn S[], int sLow, int sHigh, int val, int pos, int i)
{
    if (i < sLow || i > sHigh)
        return;

    if (sLow == sHigh)
    {

        S[pos]->max = val;
        S[pos]->min = val;
    }

    else
    {
        int mid = (sLow + sHigh) / 2;

        if (i >= sLow && i <= mid)
            updateMinMaxST(S, sLow, mid, val, (2 * pos) + 1, i);
        else
            updateMinMaxST(S, mid + 1, sHigh, val, (2 * pos) + 2, i);

        S[pos]->min = min(S[(2 * pos) + 1]->min, S[(2 * pos) + 2]->min);
        S[pos]->max = max(S[(2 * pos) + 1]->max, S[(2 * pos) + 2]->max);
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
    stn S[max_size];
    for (int i = 0; i < max_size; i++)
        S[i] = new (struct node);

    makeAll(A, S, 0, A.size() - 1, 0);

    // cout << maxQuery(S, 0, A.size() - 1, 2, 9, 0);

    cin >> max_size;
    int l, m;
    for (int i = 0; i < max_size; i++)
    {
        cin >> n >> l >> m;
        if (n == 0)
        {
            int diff = m - A[l];
            A[l] = m;
            updateS(S, 0, A.size() - 1, diff, 0, l);
            updateMinMaxST(S, 0, A.size() - 1, m, 0, l);
        }
        else if (n == 1)
        {
            cout << minQuery(S, 0, A.size() - 1, l, m, 0);
            cout << endl;
        }
        else if (n == 2)
        {
            cout << maxQuery(S, 0, A.size() - 1, l, m, 0);
            cout << endl;
        }
        else if (n == 3)
        {
            cout << sumQuery(S, 0, A.size() - 1, l, m, 0);
            cout << endl;
        }
        else if (n == 4)
        {
            cout << (float)sumQuery(S, 0, A.size() - 1, l, m, 0) / (m - l + 1);
            cout << endl;
        }
    }
}