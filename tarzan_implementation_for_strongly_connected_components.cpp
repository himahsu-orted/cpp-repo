#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int vertex;

} * VN;

void DFS(vector<vector<VN>> mainArray, vector<bool> &isInStack, vector<int> &low, vector<int> &visitedTime, stack<int> &scc, int n)
{
    static int visitingTime = 0;
    isInStack[n] = true;
    scc.push(n);
    visitedTime[n] = low[n] = ++visitingTime;
    int size = mainArray[n].size();
    for (int i = 0; i < size; i++)
    {
        int adjacentVertex = mainArray[n][i]->vertex;

        if (visitedTime[adjacentVertex] == -1)
        {
            DFS(mainArray, isInStack, low, visitedTime, scc, adjacentVertex);
            low[n] = min(low[n], low[adjacentVertex]);
        }
        else if (isInStack[adjacentVertex])
            low[n] = min(low[n], visitedTime[adjacentVertex]);
    }
    int lastElement = 0;
    if (low[n] == visitedTime[n])
    {
        while (!scc.empty())
        {
            int x = scc.top();
            cout << x << " ";
            scc.pop();
            isInStack[x] = false;
            if (x == n)
                break;
        }
        cout << endl;
    }
}
void controller(vector<vector<VN>> mainArray)
{
    int size = mainArray.size();
    vector<bool> isInStack(size, false);
    vector<int> low(size);
    vector<int> visitedTime(size, -1);
    stack<int> scc;
    for (int i = 0; i < size; i++)
        if (visitedTime[i] == -1)
            DFS(mainArray, isInStack, low, visitedTime, scc, i);
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

    int n, m, temp1;
    cin >> n >> m;
    vector<vector<VN>> arr(n);
    for (int i = 0; i < m; i++)
    {
        cin >> n >> temp1;
        VN add = new (struct node);
        add->vertex = temp1;
        arr[n].push_back(add);
    }
    controller(arr);
}
