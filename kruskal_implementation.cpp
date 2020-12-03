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

    int n, e, w, temp1, temp2;
    cin >> n >> e;
    vector<int> S(n + 1, -1);
    vector<VN> sortedInput;
    vector<VN> MST;
    for (int i = 0; i < e; i++)
    {
        VN oneNode = new (struct node);
        cin >> temp1 >> temp2;
        cin >> w;
        oneNode->x = temp1;
        oneNode->y = temp2;
        oneNode->w = w;

        int j;
        for (j = 0; j < sortedInput.size(); j++)
        {
            if (sortedInput[j]->w > oneNode->w)
                break;
        }
        auto it = sortedInput.begin();
        sortedInput.insert(it + j, oneNode);
    }
    for (int i = 0; i < sortedInput.size(); i++)
    {
        if (find(S, sortedInput[i]->x) != find(S, sortedInput[i]->y))
        {
            insert(S, sortedInput[i]->x, sortedInput[i]->y);
            MST.push_back(sortedInput[i]);
        }
    }
    int sum = 0;
    for (int i = 0; i < MST.size(); i++)
        sum += MST[i]->w;
    cout << sum;
}
