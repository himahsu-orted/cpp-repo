#include <bits/stdc++.h>
using namespace std;

int getTheVertexWithLeastWeight(int *dist, bool finalDestination[], int size)
{
    int pos = 0;
    int min = INT_MAX;
    for (int j = 0; j < size; j++)
    {
        if (*(dist + j) <= min && !finalDestination[j])
        {
            min = *(dist + j);
            pos = j;
        }
    }
    return pos;
}
void Dajikstra(int *arr, int size, int source)
{
    int distanceKeeper[size];
    bool isFinalDestination[size];
    for (int i = 0; i < size; i++)
    {
        distanceKeeper[i] = INT_MAX;
        isFinalDestination[i] = false;
    }

    distanceKeeper[source] = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int currentWorkingVertex = getTheVertexWithLeastWeight((int *)distanceKeeper, isFinalDestination, size);

        isFinalDestination[currentWorkingVertex] = true;

        for (int j = 0; j < size; j++)
        {
            if (!isFinalDestination[j] && *((arr + currentWorkingVertex * size) + j) && distanceKeeper[currentWorkingVertex] != INT_MAX && distanceKeeper[currentWorkingVertex] + *((arr + currentWorkingVertex * size) + j) < distanceKeeper[j])

            {
                distanceKeeper[j] = distanceKeeper[currentWorkingVertex] + *((arr + currentWorkingVertex * size) + j);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
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

    /* INPUT CONDTITIONS 
		1. Enter the number of nodes
		2. Enter the number of edges
		3. Enter edges (u,v) and w for the edge.4
		4. Enter source
	*/
    int n, e, k, temp1, temp2;
    cin >> n >> e >> k;

    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    for (int i = 0; i < e; i++)
    {
        cin >> temp1 >> temp2;
        cin >> arr[temp1 - 1][temp2 - 1];
    }

    cin >> temp1;
    Dajikstra((int *)arr, n, temp1 - 1);
}
