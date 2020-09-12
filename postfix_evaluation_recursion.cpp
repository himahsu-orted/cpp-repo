#include<bits/stdc++.h>
using namespace std;

int eval(int a,int b, char optr)
{
    switch(optr)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
        case '%':
            return a%b;
            break;
        default:
            return 0;
    }
}

void reFunc(string sym,int A[])
{
    static int i=0,arrPos=-1;
    int d1,d2;

    if(i<sym.length())
    {
        if(isdigit(sym.at(i)))
        {
            A[++arrPos]=(int)sym[i]-48;
        }
        else
        {
            d2=A[arrPos--];
            d1=A[arrPos--];
            A[++arrPos]=eval(d1,d2,sym.at(i));
        }
        i++;
        reFunc(sym,A);
    }
}
int main()
{

    string sym;
    cin>>sym;
    int A[sym.length()];
    reFunc(sym,A);
    cout<<A[0];
}