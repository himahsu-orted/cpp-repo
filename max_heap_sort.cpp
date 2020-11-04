#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef struct node
{
    int freq;
    string letter;
    struct node *lChild;
    struct node *rChild;
} * BST;

void makeHeap(vector<int> &arr)
{
    int i, j;
    for (int i = 1; i < arr.size(); i++)
    {
        j = i;
        int x = arr[j];
        while (j > 0 && arr[j / 2] < x)
        {
            arr[j] = arr[j / 2];
            j = j / 2;
        }

        arr[j] = x;
    }
}
vector<int> maxHeapSort(vector<int> arr)
{
    vector<int> sortedArray;

    while (arr.size() > 0)
    {
        sortedArray.push_back(arr[0]);
        auto it = arr.end() - 1;
        arr[0] = *it;
        arr.erase(it);
        makeHeap(arr);
    }

    return sortedArray;
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

    cout << endl;

    vector<int> maxHeapSortedArray = maxHeapSort(arr);

    for (int i = 0; i < maxHeapSortedArray.size(); i++)
        cout << maxHeapSortedArray[i] << " ";

    cout << endl;

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
