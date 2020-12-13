#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] < arr[i + 1])
            return false;
    }
    return true;
}
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << " ";
    }
    cout << endl;
}
bool exitCheck(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != 1)
            return false;
    return true;
}
void sumCombination(vector<int> &arr)
{
    if (exitCheck(arr))
    {
        display(arr);
        return;
    }
    int i;
    for (i = arr.size() - 1; i >= 0; i--)
    {
        if (i > 0 && arr[i] > 1 && arr[i - 1] - arr[i] > 1)
        {
            if (check(arr))
                display(arr);

            arr[i - 1]--;
            arr[i]++;
        }
        else if (arr[i] > 1)
        {
            if (check(arr))
                display(arr);
            arr[i + 1]++;
            arr[i]--;
            break;
        }
    }
    sumCombination(arr);
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

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    arr[0] = n;
    sumCombination(arr);
}