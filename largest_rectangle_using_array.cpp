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
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    
    
    int arr[6]={21, 1, 6, 7, 5, 3};
    int max=arr[0];
    for(int i=5;i>=0;i--)
    {
        push(S1,arr[i]);
        if(arr[i]>max)
        max=arr[i];
    }
    int maxArea=0;
    int temp;
    int count=0;
    for(int i=0;i<6;i++)
    {
        temp=arr[i];
        for(int j=0;j<6;j++)
        {
            if(arr[j]>=temp)
            {
                count++;
            }
            else
            {
                if(count*temp>=maxArea)
                maxArea=count*temp;

                if(temp>maxArea)
                maxArea=temp;

                count=0;
            }   
        }
        count=0;
    }
    cout<<maxArea;
}