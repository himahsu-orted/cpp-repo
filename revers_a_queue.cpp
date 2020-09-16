#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Queue
{
    int size;
    int front;
    int rear;
    char elements[SIZE];
};
void enq( struct Queue *Q,char val)
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
char deq(struct Queue *Q)
{
    char t;
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

void rev(struct Queue *Q)
{
    char temp;
    if(Q->rear!=-1)
    {
        temp=deq(Q);
        rev(Q);
        enq(Q,temp);
    }
}
int main()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;
    char ch;
    do
    {
        cin>>ch;
        if(ch!=' ' && ch!='#')
        enq(Q1,ch);
    } while (ch!='#');
    rev(Q1);
    while(Q1->front>-1)
    {
        cout<<deq(Q1)<<" ";
    }
}