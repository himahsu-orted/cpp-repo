#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int vertex;

} * VN;

void DFS(vector<vector<VN>> mainArray, vector<bool> &isVisited, vector<int> &articulationPoints, vector<int> &low, vector<int> &visitedTime, vector<int> &parent, int n)
{
    static int visitingTime = 0;
    int child = 0;
    isVisited[n] = true;
    visitedTime[n] = low[n] = ++visitingTime;
    int size = mainArray[n].size();

    for (int i = 0; i < size; i++)
    {
        int adjacentVertex = mainArray[n][i]->vertex;
        if (!isVisited[adjacentVertex])
        {
            child++;
            parent[adjacentVertex] = n;
            DFS(mainArray, isVisited, articulationPoints, low, visitedTime, parent, adjacentVertex);

            low[n] = min(low[n], low[adjacentVertex]);

            if (parent[n] == -1 && child > 1)
                articulationPoints.push_back(n);

            if (parent[n] != -1 && visitedTime[n] <= low[adjacentVertex])
                articulationPoints.push_back(n);
        }
        else if (adjacentVertex != parent[n])
            low[n] = min(low[n], visitedTime[adjacentVertex]);
    }
}
void controller(vector<vector<VN>> mainArray)
{
    int size = mainArray.size();
    vector<bool> isVisited(size, false);
    vector<int> articulationPoints;
    vector<int> low(size);
    vector<int> parent(size, -1);
    vector<int> visitedTime(size);
    for (int i = 0; i < size; i++)
        if (!isVisited[i])
            DFS(mainArray, isVisited, articulationPoints, low, visitedTime, parent, i);

    for (int i = 0; i < articulationPoints.size(); i++)
        cout << articulationPoints[i] << " ";
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

        add = new (struct node);
        add->vertex = n;
        arr[temp1].push_back(add);
    }
    controller(arr);
}
