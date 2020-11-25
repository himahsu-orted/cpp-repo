#include <bits/stdc++.h>
#include <vector>
using namespace std;

void makeHeap(vector<int> &arr)
{
    int i, j;
    for (int i = 1; i < arr.size(); i++)
    {
        j = i;
        int x = arr[j];
        while (j > 0 && arr[j / 2] > x)
        {
            arr[j] = arr[j / 2];
            j = j / 2;
        }

        arr[j] = x;
    }
}

void insertInHeap(vector<int> &arr, int x)
{
    arr.push_back(x);

    int j = arr.size() - 1;
    while (j > 0 && arr[j / 2] < x)
    {
        arr[j] = arr[j / 2];
        j = j / 2;
    }
    arr[j] = x;
}

void deleteFromHeap(vector<int> &arr)
{
    auto it = arr.end() - 1;
    arr[0] = *it;
    arr.erase(it);

    makeHeap(arr);
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

    vector<int> arr;
    int n;

    cin >> n;
    while (n != 0)
    {
        arr.push_back(n);
        cin >> n;
    }

    makeHeap(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
