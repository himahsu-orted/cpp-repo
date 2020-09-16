#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Queue
{
    int size;
    int front;
    int rear;
    string elements[SIZE];
};
void enq( struct Queue *Q,string val)
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
string deq(struct Queue *Q)
{
    string t;
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
    int n;
    cin>>n;
    
    string temp1,temp2;
    enq(Q1,"1");
    for(int i=0;i<n;i++)
    {
        temp1=deq(Q1);
        cout<<temp1<<" ";
        enq(Q1,temp1+"0");
        enq(Q1,temp1+"1");
    }
}