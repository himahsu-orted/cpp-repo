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

        S->top=S->top+1;
        S->elements[S->top]=val;
}
int pop(struct Stack *S)
{
    int t;
    t=S->elements[S->top--];
    return(t); 
}
int peekAtPos(struct Stack *S,int pos)
{
    int t;
    t=S->elements[pos];
    return(t); 
}
void stackKeeper(struct Stack *S,int n)
{
    int max=peekAtPos(S,S->top);
    int temp;
    if(S->top>=n-1)
    {
        for(int i=0;i<n;i++)
        {
            if(peekAtPos(S,S->top-i)>max)
            {
                max=peekAtPos(S,S->top-i);
            }
        }
        pop(S);
        cout<<max;
        stackKeeper(S,n);
    }
    
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    
    int n=3;
    int arr[8]={1,3,-1,-3,5,3,6,7};
    for(int i=7;i>=0;i--)
    push(S1,arr[i]);
    stackKeeper(S1,n);
}