#include <bits/stdc++.h>
using namespace std;
int findMin(int arr[], int n, int pos)
{
    static int findMin_i = pos;
    static int minPos = pos;
    if (findMin_i < n)
    {
        if (arr[findMin_i] < arr[minPos])
            minPos = findMin_i;

        findMin_i++;
        findMin(arr, n, pos);
    }
    else
    {
        findMin_i = 0;
        minPos = pos + 1;
    }

    return minPos;
}
void reFunc(int arr[], int n)
{
    static int i = 0;
    if (i < n)
    {
        int temp = findMin(arr, n, i);
        if (arr[temp] < arr[i])
        {
            int t = arr[temp];
            arr[temp] = arr[i];
            arr[i] = t;
        }
    }
    i++;
    reFunc(arr, n);
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reFunc(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}