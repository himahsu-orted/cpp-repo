#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || x > s.top())
    {
        cout << "came for " << x << endl;
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(stack<int> &s)
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, x);
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

    stack<int> a;
    a.push(3);
    a.push(1);
    a.push(23);
    a.push(6);
    a.push(9);
    a.push(2);

    sortStack(a);
    while (!a.empty())
    {
        cout << a.top() << " ";
        a.pop();
    }
}