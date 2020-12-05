#include <bits/stdc++.h>
using namespace std;
typedef struct vertex
{
    int vertex;
    float weight;
} * VN;

void earliestCompletionTime(vector<vector<VN>> mainArray)
{
    int size = mainArray.size();
    vector<float> time(size, -1);

    time[0] = 0; //Time to reach the source is always zero.

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < mainArray[i].size(); j++)
        {
            if (time[mainArray[i][j]->vertex] < mainArray[i][j]->weight + time[i])
                time[mainArray[i][j]->vertex] = mainArray[i][j]->weight + time[i];
        }
    }
    cout << time[size - 1];
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

    int n, e, temp;
    cin >> n >> e;

    float w;
    vector<vector<VN>> arr(n);
    vector<bool> isVisited(n, false);
    stack<int> tsort;
    for (int i = 0; i < e; i++)
    {
        cin >> n >> temp >> w;
        VN add = new (struct vertex);
        add->vertex = temp;
        add->weight = w;

        arr[n].push_back(add);
    }

    earliestCompletionTime(arr);
}