#include<bits/stdc++.h>
using namespace std;

int reFunc(int val)
{
    
}
int main()
{
    int n;
    cin>>n;
    int s[n];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        s[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            cout<<"(";
        }
        for(j=0;j<i;j++)
        {
            cout<<')';
        }
        cout<<endl;
    }
}