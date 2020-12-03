#include <bits/stdc++.h>
using namespace std;

void controller(string a)
{
    string command;
    int space = 0;
    string b;
    string c;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ')
            space++;
        else if (space == 0)
            command.push_back(a[i]);
        else if (space == 1)
            b.push_back(a[i]);
        else if (space == 2)
            c.push_back(a[i]);
    }

    int x = 0;
    int y = 0;
    for (int i = b.length() - 1; i >= 0; i--)
        x = x * 10 + (b[i] - 48);
    for (int i = c.length() - 1; i >= 0; i--)
        y = y * 10 + (c[i] - 48);

    cout << command << endl
         << x << endl
         << y;
}
int main()
{

    while (1)
    {
        cout << ">>> ";
        string a;
        cin >> a;
        controller(a);
    }
}