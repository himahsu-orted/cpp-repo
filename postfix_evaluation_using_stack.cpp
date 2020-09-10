#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Stack
{
    int size;
    int top;
    int elements[SIZE];
};
void push( struct Stack *S,int val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->elements[S->top]=val;
    }
}
int pop(struct Stack *S)
{
    int t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->elements[S->top--];
    return(t); 
}
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
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;      
    S1->top=-1;
    
    int d1,d2;
    string sym;
    cin>>sym;
    for(int i=0;i<sym.length();i++)
    {
        if(isdigit(sym.at(i)))
        {
            push(S1,(int)sym[i]-48);
        }
        else
        {
            d2=pop(S1);
            d1=pop(S1);
            push(S1,eval(d1,d2,sym.at(i)));
        }
    }
    cout<<endl<<endl<<pop(S1);
}
