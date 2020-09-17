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
void enq( struct Queue *Q,int val)
{
    if((Q->rear+1)%Q->size==Q->front)
    cout<<"Queue Full";
    else
    {
        if(Q->front==-1)
        {
            Q->front=0;
            Q->rear=0;
        }
        else
        {
            Q->rear=(Q->rear+1)%Q->size;
        }
        Q->elements[Q->rear]=val;
    }
}
int deq(struct Queue *Q)
{
    int t;
    if(Q->front==-1)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->elements[Q->front];
            Q->front=-1;
            Q->rear=-1;
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
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    int m,count=0,p2,p1;
    char ch;
    do
    {
        cout<<"\nEnter the number: ";
        cin>>m;
        enq(Q1,m);
        cout<<"Do you want to enter more? y/n ";
        cin>>ch;
        count++;
    }while(ch=='y'|| ch=='Y');

    for(int m=0;m<count-1;m++)
    {
        p1=deq(Q1);
        for(int i=0;i<count-1;i++)
        {
            p2=deq(Q1);
            if(p1>p2)
            {
                enq(Q1,p2);
            }
            else 
            {
                enq(Q1,p1);
                p1=p2;
            }
        }
        enq(Q1,p1);
    }
    while(Q1->front>-1)
    cout<<deq(Q1)<<" ";
}