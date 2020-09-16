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
    cout<<"Stack(Meaning the queue) is full.";
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
    cout<<"Stack(Meaning the queue) is empty.";
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
void push(struct Queue *Q1,struct Queue *Q2)
{
    int n;
    cin>>n;
    while(Q1->rear>-1)
    enq(Q2,deq(Q1));
    enq(Q1,n);
    while(Q2->rear>-1)
    enq(Q1,deq(Q2));
}
int pop(struct Queue *Q)
{
    return deq(Q);
}
int main()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    struct Queue *Q2=new(struct Queue);
    Q2->size=SIZE-1;
    Q2->front=-1;
    Q2->rear=-1;

    char ch;
    do
    {
        cout<<"1. Push\n2. Pop   ";
        int choice;
        cin>>choice;
        if(choice==1)
        push(Q1,Q2);
        else 
        cout<<pop(Q1);
        cout<<"\nDo you want to continue? ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}