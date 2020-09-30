#include <bits/stdc++.h>
using namespace std;

int reFunc(int arr[], int n)
{
    static int min = arr[0];
    static int max = arr[0];
    static float sum = 0;
    static int i = 0;
    if (i < n)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];

        sum = sum + (float)arr[i];

        i++;
        reFunc(arr, n);
    }
    else
    {
        cout << "\nMax=" << max;
        cout << "\nMin=" << min;
        cout << "\nAverage=" << sum / i;
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
    reFunc(arr, n);
}