#include<bits/stdc++.h>
using namespace std;

void reFunc(char a[],int l, int r)
{
    if(l==r)
    cout<<a[l];
    else
    {
        for(int i=l;i<r;i++)
        {
            swap(a[l],a[i]);
            reFunc(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
    
}
int main()
{
    cout<<"Enter the string for the permutation: ";
    char str[20];
    cin>>str;
    reFunc(str,0,strlen(str));
}