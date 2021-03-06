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
void holdInStack(struct Stack *S,int val)
{
    if(S->top<0)
    {
        push(S,val);
    }
    else
    {
        int temp=pop(S);
        holdInStack(S,val);
        push(S,temp);
    }
}
void stackRev(struct Stack *S)
{
    
    if(S->top>-1)
    {
        int val=pop(S);
        stackRev(S);
        holdInStack(S,val);
    }
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    int n;
    char ch;
    do
    {
        cout<<"\nEnter the value: ";
        cin>>n;
        push(S1,n);
        cout<<"\nDo you want to add more? y/n ";
        cin>> ch;
    }while(ch=='y'|| ch=='Y');
    stackRev(S1);
    cout<<endl;
    while(S1->top>-1)
    cout<<pop(S1)<<" ";
    
}