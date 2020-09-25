#include<bits/stdc++.h>
using namespace std;

long long sumCheck(long long n)
{
    if(n>0)
    return (n%10+sumCheck(n/10));
    else return n;
}
bool ascendingCheck(long long n)
{
    if(n>0)
    {
        if(n%10>=(n/10)%10)
        return (ascendingCheck(n/10));
        else return false;
    }
    else return true;
}
void reFunc(long long n,long long val)
{
    static long long i=0;
    if(i<=val)
    {
        if(sumCheck(i)==n && ascendingCheck(i))
        cout<<i<<endl;
        i++;
        reFunc(n,val);
    }
}
int main()
{
    long long n;
    cin>>n;
    long long val=0;
    for(long long i=0;i<n;i++)
    val=(val*10)+1;
    
    reFunc(n,val);
}