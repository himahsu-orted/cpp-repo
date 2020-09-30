#include <bits/stdc++.h>
using namespace std;

void swapChar(char a[], int l, int i)
{
    char temp = a[l];
    a[l] = a[i];
    a[i] = temp;
}
void per(char a[], int l, int r)
{
    if (l == r)
    {
        cout << a[l];
    }
    else
    {
        for (int i = l; i < r; i++)
        {
            swapChar(a, l, i);
            per(a, l + 1, r);
            swapChar(a, l, i);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    char ch[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ch[i];
    }
    per(ch, 0, n - 1);
}
