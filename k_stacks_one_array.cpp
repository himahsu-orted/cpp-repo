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
    if(S->top>= S->size)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->elements[S->top]=val;
    }
}
int pop(struct Stack *S, int size)
{
    int t;
    if(S->top>=size)
    t=S->elements[S->top--];
    else
    cout<<"Stack Empty";
    return(t); 
}
int main()
{
    int k;
    cout<<"The value of k : ";
    cin>>k;

    struct Stack *S1[k];
    for(int i=0;i<k;i++)
    {
        S1[i]=new(struct Stack);
        S1[i]->size=(i+1)*(SIZE/k);
        S1[i]->top=-1+(i)*(SIZE/k);
    }
    int n,val;
    char ch;
    do
    {
        cout<<"\nEnter the stack to enter value: ";
        cin>>n;
        cout<<"\nEnter the value to be pushed: ";
        cin>>val;
        push(S1[n-1],val);
        cout<<"\nDo you want to add more? y/n ";
        cin>>ch;  
    } while (ch=='y'|| ch=='Y');
    do
    {
        cout<<"\nEnter the stack to pop value: \n";
        cin>>n;
        if(n==1)
        cout<<endl<<pop(S1[n-1],-1)<<"\n";
        else 
        cout<<endl<<pop(S1[n-1],S1[n-2]->size)<<"\n";
        cout<<"\nDo you want to pop more? y/n ";
        cin>>ch;  
    } while (ch=='y'|| ch=='Y');
    
}