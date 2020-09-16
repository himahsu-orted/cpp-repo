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
bool isSecondLast(struct Queue *Q)
{
    if(Q->rear==Q->front)
    return true;
    else 
    return false;
}
void push(struct Queue *Q)
{
    int val;
    cin>>val;
    enq(Q,val);
}
void pop(struct Queue *Q1,struct Queue *Q2)
{
    while(!isSecondLast(Q1))
    enq(Q2,deq(Q1));
    cout<<deq(Q1);
    while(Q2->rear>-1)
    enq(Q1,deq(Q2));
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
        push(Q1);
        else 
        pop(Q1,Q2);
        cout<<"\nDo you want to continue? ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}