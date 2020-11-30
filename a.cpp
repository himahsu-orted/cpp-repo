#include <bits/stdc++.h>
using namespace std;
static int cycleCount = 0;
void findCycles(vector<vector<int>> mainArray, vector<int> insideArray, int targetNumeber, vector<int> temp)
{
	for (int i = 0; i < insideArray.size(); i++)
	{
		temp.push_back(insideArray[i]);
		if (insideArray[i] == targetNumeber)
		{
			for (int j = 0; j < temp.size(); j++)
				cout << temp[j] + 1 << " ";
			cycleCount++;
			cout << endl;
			return;
		}
		findCycles(mainArray, mainArray[insideArray[i]], targetNumeber, temp);
		temp.pop_back();
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

	int n, e, temp;
	cin >> n >> e;

	vector<vector<int>> arr(n);
	for (int i = 0; i < e; i++)
	{
		cin >> n >> temp;
		arr[n - 1].push_back(temp - 1);
	}
	vector<int> cycleArray;
	cycleArray.push_back(0);
	findCycles(arr, arr[0], 0, cycleArray);
	cout << cycleCount;
}