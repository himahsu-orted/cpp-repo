#include <bits/stdc++.h>
using namespace std;
void sort(int arr[], int n)
{
    static int i = 0;
    if (i < n)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        i++;
        sort(arr, n);
    }
    else
        i = 0;
}
void reFunc(int arr[], int n)
{
    static int j = 0;
    if (j < n)
    {
        sort(arr, n);
        j++;
        reFunc(arr, n);
    }
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
    reFunc(arr, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}