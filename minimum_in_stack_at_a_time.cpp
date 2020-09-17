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
int peek(struct Stack *S)
{
    int t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->elements[S->top];
    return(t); 
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    int n;
    cout<<"Enter -1 to exit.\n";
    do
    {
        cin>>n;
        if(n==-1)
        break;
        else
        {
            if(S1->top==-1)
            push(S1,n*10+n%10);
            else
            {
                if(n<peek(S1)%10)
                push(S1,n*10+n%10);
                else
                push(S1,n*10+peek(S1)%10);
            }
            
        }
        
    } while (n!=-1);
    while(S1->top>-1)
    {
        cout<<endl<<peek(S1)%10<<" till "<<pop(S1)/10;
    }   
}