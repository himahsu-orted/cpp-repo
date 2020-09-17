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
bool isSecondLast(struct Stack *S)
{
    if(S->top==0)
    return true;
    else 
    return false;
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
void enq(struct Stack *S)
{
    int num;
    cin>>num;
    stackRev(S);
    push(S,num);
    stackRev(S);
}
int deq(struct Stack *S)
{
    return pop(S);
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    
    struct Stack *S2=new(struct Stack);
    S2->size=SIZE-1;
    S2->top=-1;

    int n;
    char ch;
    do
    {
        cout<<"1. Push\n2. Pop   ";
        int choice;
        cin>>choice;
        if(choice==1)
        enq(S1);
        else 
        cout<<deq(S1);
        cout<<"\nDo you want to continue? ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}