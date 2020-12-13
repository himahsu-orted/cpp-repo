#include <iostream>
using namespace std;

void bracketPermutation(int pos, int n, int open, int close)
{
    static char str[CHAR_MAX];
    if (close == n)
    {
        cout << str;
        cout << endl;
        return;
    }
    else
    {
        if (open > close)
        {
            str[pos] = ')';
            bracketPermutation(pos + 1, n, open, close + 1);
        }

        if (open < n)
        {
            str[pos] = '(';
            bracketPermutation(pos + 1, n, open + 1, close);
        }
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

    int n;
    cin >> n;
    bracketPermutation(0, n, 0, 0);
    return 0;
}