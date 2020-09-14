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

void stackRev(struct Stack *S)
{
    int temp;
    if(S->top>-1)
    {
        temp=pop(S);
        stackRev(S);
    }
    push(S,temp);
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
    while(S1->top>0)
    cout<<pop(S1)<<" ";
    
}