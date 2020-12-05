#include <bits/stdc++.h>
using namespace std;
typedef struct vertex
{
    int data;
    int weight;
} * VN;

void primAlgo(vector<vector<VN>> mainArray)
{
    int size = mainArray.size();
    int totalWeight = 0;
    vector<VN> MST;
    vector<int> parent;
    vector<bool> isTouched(size);

    for (int i = 0; i < size; i++)
    {
        isTouched[i] = false;
    }

    int pos = 0;
    int min = INT_MAX;

    for (int k = 0; k < mainArray[0].size(); k++)
    {

        if (mainArray[0][k]->weight < min)
        {
            pos = mainArray[0][k]->data;
            min = mainArray[0][k]->weight;
        }
    }
    isTouched[0] = true;
    isTouched[pos] = true;
    parent.push_back(0);
    parent.push_back(pos);
    totalWeight += min;

    VN node = new (struct vertex);
    node->data = 0;
    node->weight = pos;
    MST.push_back(node);

    for (int i = 0; i < mainArray.size() - 2; i++)
    {
        int currentMinPos = 0;
        int currentParentPos = 0;
        int currentMin = INT_MAX;
        for (int j = 0; j < parent.size(); j++)
        {
            pos = 0;
            min = INT_MAX;

            for (int k = 0; k < mainArray[parent[j]].size(); k++)
            {

                if (mainArray[parent[j]][k]->weight < min && !isTouched[mainArray[parent[j]][k]->data])
                {
                    pos = mainArray[parent[j]][k]->data;
                    min = mainArray[parent[j]][k]->weight;
                }
            }
            if (min < currentMin)
            {
                currentMin = min;
                currentMinPos = pos;
                currentParentPos = parent[j];
            }
        }

        if (!isTouched[currentParentPos])
        {
            parent.push_back(currentParentPos);
        }
        if (!isTouched[currentMinPos])
        {
            parent.push_back(currentMinPos);
        }
        isTouched[currentMinPos] = true;
        isTouched[currentParentPos] = true;

        node = new (struct vertex);
        node->data = currentParentPos;
        node->weight = currentMinPos;
        MST.push_back(node);
        totalWeight += currentMin;
    }
    for (int i = 0; i < MST.size(); i++)
    {
        cout << MST[i]->data + 1 << " " << MST[i]->weight + 1 << "\n";
    }
    cout << totalWeight;
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
        add->data = temp - 1;
        add->weight = w;

        VN add2 = new (struct vertex);
        add2->data = n - 1;
        add2->weight = w;

        arr[n - 1].push_back(add);
        arr[temp - 1].push_back(add2);
    }

    primAlgo(arr);
}