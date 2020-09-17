#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Queue
{
    int size;
    int front;
    int rear;
    int X[SIZE];
    int Y[SIZE];
    int elements[8][8];
};
void enq( struct Queue *Q,int i, int j)
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
        Q->X[Q->rear]=i;
        Q->Y[Q->rear]=j;
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
            t=Q->X[Q->front];
            t=t*10+Q->Y[Q->front];
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            t=Q->X[Q->front];
            t=t*10+Q->Y[Q->front];
            Q->front=(Q->front+1)%Q->size;
        }
    }
    return t;
}
void assignPath(struct Queue *S)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            S->elements[i][j]=0;
        }
    }

    for(i=1;i<=6;i++)
    S->elements[1][i]=1;

    for(i=3;i<=6;i++)
    S->elements[3][i]=1;

    for(i=1;i<=4;i++)
    S->elements[6][i]=1;

    S->elements[4][3]=1;

    S->elements[7][7]=1;
    S->elements[2][1]=1;

    S->elements[2][3]=1;

    S->elements[4][6]=1;

    S->elements[5][6]=1;

    S->elements[6][6]=1;

    S->elements[5][4]=1;

    S->elements[4][1]=1;

    S->elements[5][1]=1;
}
void navigateGame(struct Queue *S,int i, int j)
{
    
    if(S->elements[i][j-1]==1)
    {
        enq(S,i,j-1);
        S->elements[i][j]=2;
        navigateGame(S,i,j-1);
    }
    else if(S->elements[i-1][j]==1)
    {
        enq(S,i-1,j);
        S->elements[i][j]=2;
        navigateGame(S,i-1,j);
    }
    else if(S->elements[i+1][j]==1)
    {
        enq(S,i+1,j);
        S->elements[i][j]=2;
        navigateGame(S,i+1,j);
    }
    else if(S->elements[i][j+1]==1)
    {
        enq(S,i,j+1);
        S->elements[i][j]=2;
        navigateGame(S,i,j+1);
    }
    else if(S->elements[i][j-1]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i,j-1);
    }
    else if(S->elements[i-1][j]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i-1,j);
    }
    else if(S->elements[i+1][j]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i+1,j);
    }
    else if(S->elements[i][j+1]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i,j+1);
    }
    else
    {
        return;
    }
}
int main()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    int i,j;
    assignPath(Q1);
    int count=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(Q1->elements[i][j]==1)
            {
                enq(Q1,i,j);
                navigateGame(Q1,i,j);
                count++;
            }
        }
    }
    cout<<"Number of Islands= "<<count;
}