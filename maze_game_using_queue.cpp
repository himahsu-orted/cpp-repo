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

    S->elements[2][1]=1;

    S->elements[2][3]=1;

    S->elements[4][6]=1;

    S->elements[5][6]=1;

    S->elements[6][6]=1;

    S->elements[5][4]=1;

    S->elements[4][1]=1;

    S->elements[5][1]=1;
}
void navigateGame(struct Queue *S,int i, int j, int dx,int dy)
{
    if(i==dx && j==dy)
    {
        S->elements[i][j]=2;
        cout<<"Way Founded";
    }
    else if(S->elements[i][j-1]==1)
    {
        enq(S,i,j-1);
        S->elements[i][j]=2;
        navigateGame(S,i,j-1,dx,dy);

    }
    else if(S->elements[i-1][j]==1)
    {
        enq(S,i-1,j);
        S->elements[i][j]=2;
        navigateGame(S,i-1,j,dx,dy);
    }
    else if(S->elements[i+1][j]==1)
    {
        enq(S,i+1,j);
        S->elements[i][j]=2;
        navigateGame(S,i+1,j,dx,dy);
    }
    else if(S->elements[i][j+1]==1)
    {
        enq(S,i,j+1);
        S->elements[i][j]=2;
        navigateGame(S,i,j+1,dx,dy);
    }
    else if(S->elements[i][j-1]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i,j-1,dx,dy);
    }
    else if(S->elements[i-1][j]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i-1,j,dx,dy);
    }
    else if(S->elements[i+1][j]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i+1,j,dx,dy);
    }
    else if(S->elements[i][j+1]==2)
    {
        deq(S);
        S->elements[i][j]=0;
        navigateGame(S,i,j+1,dx,dy);
    }
    else
    {
        cout<<"No Way Out!";
    }
}
int main()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    int i,j;
    int sx,sy,dx,dy;
    assignPath(Q1);

    cout<<"Enter the statring point: ";
    sHere:
    cin>>sx>>sy;
    if(Q1->elements[sx][sy]==0)
    {
        cout<<"Invalid Position. Enter again. \n";
        goto sHere;
    }
    cout<<"Enter the Destination point: ";
    dHere:
    cin>>dx>>dy;
    if(Q1->elements[dx][dy]==0)
    {
        cout<<"Invalid Position. Enter again. \n";
        goto dHere;
    }
    enq(Q1,sx,sy);
    navigateGame(Q1,sx,sy,dx,dy);
    cout<<endl;
    while (Q1->front>-1)
    {
        cout<<deq(Q1)<<" ";
    }
    cout<<endl<<endl;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(Q1->elements[i][j]==2)
            {
                if(i==sx && j==sy)
                cout<<"S ";
                else if(i==dx && j==dy)
                cout<<"D ";
                else
                cout<<"*"<<" ";
            }
            else
            cout<<"0"<<" ";
        }
        cout<<endl;
    }
    
}