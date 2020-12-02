#include <bits/stdc++.h>
using namespace std;

typedef struct ShortestPath
{
	vector<int> path;
	vector<int> costs;
} * SP;
int getTheVertexWithLeastWeightWithFalseCheck(int *dist, bool finalDestination[], int size)
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
void getPath(vector<int> &path, vector<int> parent, int j)
{
	if (parent[j] == -1)
		return;
	getPath(path, parent, parent[j]);
	path.push_back(j);
}
bool compareTwoPaths(vector<int> a, vector<int> b, int limit)
{

	for (int i = 0; i < limit; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
void display(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << *((arr + i * size) + j) << " ";
		cout << endl;
	}
}
void getRootPath(SP source, SP destination, int limit)
{
	for (int i = 0; i < limit; i++)
	{
		destination->path.push_back(source->path[i]);
	}
}
void printKpaths(vector<SP> B)
{
	for (int i = 0; i < B.size(); i++)
	{
		cout << B[i]->costs[B[i]->costs.size() - 1] << endl;
		for (int j = 0; j < B[i]->path.size(); j++)
			cout << B[i]->path[j] + 1 << " ";
		cout << endl;
	}
}
SP Dajikstra(int *arr, int size, int source, int destination)
{
	int distanceKeeper[size];
	vector<int> parent(size);
	bool isFinalDestination[size];
	for (int i = 0; i < size; i++)
	{
		parent[i] = -1;
		distanceKeeper[i] = INT_MAX;
		isFinalDestination[i] = false;
	}

	distanceKeeper[source] = 0;

	for (int i = 0; i < size - 1; i++)
	{
		int currentWorkingVertex = getTheVertexWithLeastWeightWithFalseCheck((int *)distanceKeeper, isFinalDestination, size);

		isFinalDestination[currentWorkingVertex] = true;

		for (int j = 0; j < size; j++)
		{
			if (!isFinalDestination[j] && *((arr + currentWorkingVertex * size) + j) && distanceKeeper[currentWorkingVertex] != INT_MAX && distanceKeeper[currentWorkingVertex] + *((arr + currentWorkingVertex * size) + j) < distanceKeeper[j])

			{
				distanceKeeper[j] = distanceKeeper[currentWorkingVertex] + *((arr + currentWorkingVertex * size) + j);
				parent[j] = currentWorkingVertex;
			}
			if (j == destination)
				break;
		}
	}

	SP returningValue = new (struct ShortestPath);
	returningValue->path.push_back(source);
	returningValue->costs.push_back(0);
	for (int i = 1; i < size; i++)
		if (distanceKeeper[i] != INT_MAX)
			returningValue->costs.push_back(distanceKeeper[i]);
		else
			returningValue->costs.push_back(0);

	getPath(returningValue->path, parent, destination);
	return returningValue;
}
void yensAlgorithm(int *arr, int source, int sink, int size, int K)
{
	vector<SP> A;
	int node;
	A.push_back(Dajikstra(arr, size, source, sink));

	for (int i = 0; i < K - 1; i++)
	{
		int spurNode = A[0]->path[i];
		SP rootPath = new (struct ShortestPath);
		getRootPath(A[0], rootPath, i);

		for (int path = 0; path < A.size(); path++)
			if (compareTwoPaths(rootPath->path, A[path]->path, i))
				*((arr + i * size) + i + 1) = 0;

		SP spurPath = Dajikstra(arr, size, spurNode, sink);
		SP totalPath = new (struct ShortestPath);

		totalPath->path = rootPath->path;
		totalPath->path.insert(totalPath->path.end(), spurPath->path.begin(), spurPath->path.end());
		totalPath->costs.push_back(A[0]->costs[i] + spurPath->costs[spurPath->costs.size() - 1]);
		A.push_back(totalPath);
	}
	printKpaths(A);
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
		5. Enter the destination
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
	cin >> temp1 >> temp2;
	yensAlgorithm((int *)arr, temp1 - 1, temp2 - 1, n, k);
}
