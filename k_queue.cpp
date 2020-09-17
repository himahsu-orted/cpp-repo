#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Queue
{
    int size;
    int front;
    int rear;
    int elements[SIZE];
};
void enq( struct Queue *Q,int val,int s)
{
    if((Q->rear+1)%Q->size==Q->front)
    cout<<"Queue Full";
    else
    {
        if(Q->front<s)
        {
            Q->front=s;
            Q->rear=s;
        }
        else
        {
            Q->rear=(Q->rear+1)%Q->size;
        }
        Q->elements[Q->rear]=val;
    }
}
int deq(struct Queue *Q,int size)
{
    int t;
    if(Q->front<size)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->elements[Q->front];
            Q->front=size-1;
            Q->rear=size-1;
        }
        else
        {
            t=Q->elements[Q->front];
            Q->front=(Q->front+1)%Q->size;

        }
    }
    return t;
}
int main()
{
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    struct Queue *Q[k];
    for(int i=0;i<k;i++)
    {
        Q[i]=new(struct Queue);
        Q[i]->size=(i+1)*(SIZE/k);
        Q[i]->front=-1+(i)*(SIZE/k);
        Q[i]->rear=-1+(i)*(SIZE/k);
    }
    int n,val;
    char ch;
    do
    {
        cout<<"\nEnter the queue to enter value: ";
        cin>>n;
        cout<<"\nEnter the value to be enqueue: ";
        cin>>val;
        if(n==1)
        enq(Q[n-1],val,-1);
        else 
        enq(Q[n-1],val,Q[n-2]->size);
        cout<<"\nDo you want to add more? y/n ";
        cin>>ch;  
    } while (ch=='y'|| ch=='Y');
    do
    {
        cout<<"\nEnter the queue to dequeue value: \n";
        cin>>n;
        if(n==1)
        cout<<endl<<deq(Q[n-1],-1)<<"\n";
        else 
        cout<<endl<<deq(Q[n-1],Q[n-2]->size)<<"\n";
        cout<<"\nDo you want to dequeue more? y/n ";
        cin>>ch;  
    } while (ch=='y'|| ch=='Y');
    
}