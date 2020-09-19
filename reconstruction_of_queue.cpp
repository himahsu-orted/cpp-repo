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
    
    return t;
}
int queueLeft(struct Queue *Q)
{
    int temp=Q->rear-Q->front;
    if(temp<0)
    temp=temp*-1;
    return temp;
}
void constr(struct Queue *Q1, struct Queue *Q2,int max,int flag[])
{
    if(Q1->front>-1)
    {
        for(int i=1;i<max;i++)
        {
            for(int j=0;j<queueLeft(Q1)+1;j++)
            {
                int temp=deq(Q1);
                if(temp/10<=i && flag[i]==temp%10)
                {
                    enq(Q2,temp);
                    for(int k=0;k<=i;k++)
                    flag[k]++;
                    constr(Q1,Q2,max,flag);
                }
                else enq(Q1,temp);
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

    struct Queue *Q2=new(struct Queue);
    Q2->size=SIZE-1;
    Q2->front=-1;
    Q2->rear=-1;

    int n;
    int max=0;
    int k;
    char ch;
    do
    {
        cout<<"\nEnter the height: ";
        cin>>n;
        if(n>max)
        max=n;
        cout<<"\nEnter the value of k: ";
        cin>>k;
        enq(Q1,n*10+k);
        cout<<"Do you want to enter more? y/n ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
    int flag[max+1];
    for(int i=0;i<max+1;i++)
    flag[i]=0;
    constr(Q1,Q2,max+1,flag);
    while(Q2->front>-1)
    {
        int temp=deq(Q2);
        cout<<"{"<<temp/10<<","<<temp%10<<"} ";
    }
}