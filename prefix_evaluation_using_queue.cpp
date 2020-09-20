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
            Q->elements[Q->front]=0;
            Q->front=-1;
            Q->rear=-1;
        }
        else 
        {
            t=Q->elements[Q->front];
            Q->elements[Q->front]=0;
            Q->front=(Q->front+1)%Q->size;
        }
    }

    return t;
}
bool isSecondLast(struct Queue *Q)
{
    if(Q->front==Q->rear)
    return true;
    else 
    return false;
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
                    enq(Q1,5001);
                    break;
                case '-':
                    enq(Q1,5002);
                    break;
                case '*':
                    enq(Q1,5003);
                    break;
                case '/':
                    enq(Q1,5004);
                    break;
            }
        }
    }
}
bool checkOperator(int f)
{
    if(f==5001||f==5002||f==5003||f==5004)
    return true;
    else 
    return false;
}
bool checkOperand(int f)
{
    if(f==5001||f==5002||f==5003||f==5004)
    return false;
    else 
    return true;
}
void storeVal(struct Queue *Q, int p1,int p2, int p3)
{
    switch (p1)
    {
        case 5001:
            enq(Q,p2+p3);
            break;
        case 5002:
            enq(Q,p2-p3);
            break;
        case 5003:
            enq(Q,p2*p3);
            break;
        case 5004:
            enq(Q,p2/p3);
            break;
        default:
            break;
    }
}
void calculate(struct Queue *Q)
{
    if(!isSecondLast(Q))
    {
        int p1,p2,p3,temp;
        p1=deq(Q);
        p2=deq(Q);
        while(Q->front>-1)
        {
            p3=deq(Q);
            if(checkOperator(p1) && checkOperand(p2) && checkOperand(p3))
            { 
                storeVal(Q,p1,p2,p3);
                if(Q->front==Q->rear)
                {
                    cout<<deq(Q)<<endl;
                    exit(0);
                }
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
    
}
int main()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    takeInput(Q1);
    calculate(Q1);
}