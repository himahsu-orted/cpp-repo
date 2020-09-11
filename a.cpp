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
    int temp;

    int n;
    cout<<"Enter the number of small Interevals: ";
    cin>>n;
    int res[2*n];
    int j=0;
    int lBound,uBound;
    
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter lower bound: ";
        cin>>lBound;
        cout<<"\nEnter upper bound: ";
        cin>>uBound;
        if(S1->top==-1)
        {
            push(S1,lBound);
            push(S1,uBound);
        }
        else
        {
            if(peek(S1)>=lBound)
            {
                temp=pop(S1);
                push(S1,lBound);
                if(temp<=uBound)
                {
                    push(S1,temp);
                    push(S1,uBound);
                }
                else
                {
                    push(S1,uBound);
                    push(S1,temp);
                }
            }
            else
            {
                res[j++]=pop(S1);
                while(S1->top>1)
                {
                    pop(S1);
                }
                pop(S1);
                res[j++]=pop(S1);
                push(S1,lBound);
                push(S1,uBound);
            }
            
        }
        
    }
    res[j++]=pop(S1);
    while(S1->top>1)
    {
        pop(S1);
    }
    res[j++]=pop(S1);
    for(int i=0;i<j;i++)
    {
        cout<<res[i+1]<<"-"<<res[i]<<"   ";
        i++;
    }
}