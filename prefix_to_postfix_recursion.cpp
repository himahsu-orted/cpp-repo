#include<bits/stdc++.h>
using namespace std;

void reFunc(string sym, string A[])
{

    string d1,d2;
    static int i=sym.length()-1,arrPos=-1;
    if(i>=0)
    {

        if(isdigit(sym.at(i)))
        {
            A[++arrPos]=to_string((int)sym[i]-48);
        }
        else
        {
            d2=A[arrPos--];
            A[arrPos+1]='\0';
            d1=A[arrPos--];
            A[arrPos+1]='\0';
            A[++arrPos]=d2+d1+sym.at(i);
        }
        i--;
        reFunc(sym,A);
    }

}
int main()
{
    string sym;
    cin>>sym;
    string A[sym.length()];
    reFunc(sym,A);
    for(int i=0;i=='\0';i++)
    cout<<A[i]<<" ";
}