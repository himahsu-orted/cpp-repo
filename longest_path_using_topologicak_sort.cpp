#include <bits/stdc++.h>
using namespace std;
typedef struct vertex
{
    int data;
    int weight;
} * VN;
static int atCount = 0;
void topologicalSort(vector<vector<VN>> mainArray, vector<VN> insideArray, vector<bool> &isVisited, stack<int> &tsort)
{
    for (int i = 0; i < insideArray.size(); i++)
    {
        if (!isVisited[insideArray[i]->data])
        {
            tsort.push(insideArray[i]->data);
            isVisited[insideArray[i]->data] = true;
        }
        topologicalSort(mainArray, mainArray[insideArray[i]->data], isVisited, tsort);
    }
}
void longestPath(vector<vector<VN>> mainArray, stack<int> tsort, int source)
{
    int size = mainArray.size();
    int distanceKeeper[size];
    bool isFinalDestination[size];
    for (int i = 0; i < size; i++)
    {
        distanceKeeper[i] = INT_MAX;
        isFinalDestination[i] = false;
    }

    distanceKeeper[source] = 0;
    while (!tsort.empty())
    {
        int currentWorkingVertex = tsort.top();
        tsort.pop();
        if (distanceKeeper[currentWorkingVertex] != INT_MAX)
        {
            for (int j = 0; j < mainArray[currentWorkingVertex].size(); j++)
            {
                if (distanceKeeper[mainArray[currentWorkingVertex][j]->data] > distanceKeeper[currentWorkingVertex] + mainArray[currentWorkingVertex][j]->weight)
                {
                    distanceKeeper[mainArray[currentWorkingVertex][j]->data] = distanceKeeper[currentWorkingVertex] + mainArray[currentWorkingVertex][j]->weight;
                }
            }
        }
    }
    for (int i = 0; i < mainArray.size(); i++)
    {
        if (distanceKeeper[i] == INT_MAX)
            cout << "INF ";
        if (distanceKeeper[i] == 0)
            cout << "";
        else
            cout << distanceKeeper[i] << " ";
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

    int n, e, temp, w;
    cin >> n >> e;

    vector<vector<VN>> arr(n);
    vector<bool> isVisited(n, false);
    stack<int> tsort;
    for (int i = 0; i < e; i++)
    {
        cin >> n >> temp >> w;
        VN add = new (struct vertex);
        add->data = temp;
        add->weight = w;

        arr[n].push_back(add);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!isVisited[i])
        {
            VN add = new (struct vertex);
            add->data = i;
            add->weight = 0;
        }
        topologicalSort(arr, arr[i], isVisited, tsort);
        if (isVisited[i] == false)
        {
            isVisited[i] = true;
            tsort.push(i);
        }
    }
    longestPath(arr, tsort, 7);
}