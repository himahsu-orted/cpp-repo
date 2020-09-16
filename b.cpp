#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Queue
{
    int size;
    int front;
    int rear;
    float elements[SIZE];
};
void enq( struct Queue *Q,float val)
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
float deq(struct Queue *Q)
{
    float t;
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
void takeInput(struct Queue *Q1)
{
    string sym;
    cin>>sym;
    for(int i=0;i<sym.length();i++)
    {
        if(isdigit(sym[i]))
        {
            enq(Q1,(int)sym[i]-48);
        }
        else
        {
            switch(sym[i])
            {
                case '+':
                    enq(Q1,0.1);
                    break;
                case '-':
                    enq(Q1,0.2);
                    break;
                case '*':
                    enq(Q1,0.3);
                    break;
                case '/':
                    enq(Q1,0.4);
                    break;
            }
        }
    }
}
bool checkOperator(float f)
{
    if(f==0.1||f==0.2||f==0.3||f==0.4)
    return true;
    else 
    return false;
}
bool checkOperand(float f)
{
    if(f==0.1||f==0.2||f==0.3||f==0.4)
    return false;
    else 
    return true;
}
void storeVal(struct Queue *Q, float p1,float p2, float p3)
{
    if(fabs(p1-0.1)<0.0005)
    {enq(Q,p2+p3);cout<<"+";}
    else if(fabs(p1-0.2)<0.0005)
    {enq(Q,p2-p3);cout<<"-";}
    else if(fabs(p1-0.3)<0.0005)
    {enq(Q,p2*p3);cout<<"*";}
    else
    {enq(Q,p2/p3);cout<<"/";}
}
void calculate(struct Queue *Q)
{
    static int i=0;
    if(Q->front!=Q->rear)
    {
        cout<<"Front: "<<Q->front<<"Rear: "<<Q->rear;
        float p1,p2,p3,temp;
        p1=deq(Q);
        p2=deq(Q);
        while(Q->front!=Q->rear)
        {
            p3=deq(Q);
            if(p2>1&& p3>1)
            { 
                storeVal(Q,p1,p2,p3);
                calculate(Q);
            }
            else
            {
                enq(Q,p1);
                p1=p2;
                p2=p3;
            }
        }
    }
    else
    return;
    
}
int main()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    takeInput(Q1);
    calculate(Q1);

    while(Q1->front>-1)
    {
        cout<<deq(Q1)<<" ";
    }
}