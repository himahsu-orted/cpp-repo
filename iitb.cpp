#include <bits/stdc++.h>
using namespace std;

int fac(int n)
{
    if(n==0)
    return 1;
    else
    {
        return(fac(n-1)*n);
    }
}
void reFunc(int num)
{
    if (num > -1)
    {
        reFunc(num-1);
        for(int i=0;i<=num;i++)
        {
            int val=fac(num)/(fac(i)*fac(num-i));
            cout<<val<<" ";
        }
        cout<<endl;
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
    reFunc(n);
}