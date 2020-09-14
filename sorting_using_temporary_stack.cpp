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
    cout<<"Stack Emptyzz";
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
void sortFunc(struct Stack *S1,struct Stack *S2)
{
    int temp;
    int pos=0;
    if(S1->top==-1)
    return;

    if(peek(S1)<=peek(S2))
    {
        push(S2, pop(S1));
    }
    else
    {
        pos=S1->top;
        temp=pop(S1);
        while(S2->top>-1)
        {
            if(peek(S2)<=temp)
            push(S1,pop(S2));
            else break;
        }
        push(S2, temp);
        while(S1->top>=pos)
        {
            push(S2, pop(S1));
        }
    }
    sortFunc(S1,S2);
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
        cout<<"\nEnter the number: ";
        cin>>n;
        push(S1,n);
        cout<<"Do you want to enter more? y/n ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
    push(S2,pop(S1));
    sortFunc(S1,S2);
    cout<<endl;
    while(S2->top>-1)
    {
        cout<<pop(S2)<<" ";
    }
}