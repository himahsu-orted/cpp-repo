#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct sArray
{
    int elements[SIZE];
};
struct Stack1
{
    int size;
    int top;
    struct sArray *obj1;
};
struct Stack2
{
    int size;
    int top;
    struct sArray *obj2;
};

void push1( struct Stack1 *S,int val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->obj1->elements[S->top]=val;
    }
}
void push2( struct Stack2 *S,int val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->obj2->elements[S->top]=val;
    }
}
int pop1(struct Stack1 *S)
{
    int t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->obj1->elements[S->top--];
    return(t); 
}
int pop2(struct Stack2 *S)
{
    int t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->obj2->elements[S->top--];
    return(t); 
}
int main()
{
    struct Stack1 *S1=new(struct Stack1);
    S1->size=SIZE-1;
    S1->top=-1;
    S1->obj1=new(struct sArray);

    struct Stack2 *S2=new(struct Stack2);
    S2->size=(SIZE-1)/2;
    S2->top=SIZE/2;
    S2->obj2=new(struct sArray);

    int n;
    char ch;
    do
    {
        cout<<"Enter number: ";
        cin>>n;
        if(n%2==0)
        push1(S1,n);
        else 
        push2(S2,n);
        cout<<"\nDo you want to add another? y/n ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    cout<<"\nOutput: ";
    while(S1->top>-1)
    {
        cout<<pop1(S1)<<" ";
    } 
    while(S2->top>(SIZE/2))
    {
        cout<<pop2(S2)<<" ";
    } 
}