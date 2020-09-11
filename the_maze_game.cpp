#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Stack
{
    int size;
    int top;
    int elements[SIZE][SIZE];
    int wayX[SIZE];
    int wayY[SIZE];
};
void push( struct Stack *S,int i,int j)
{
    if(S->top>= SIZE)
    cout<<"";
    else
    {
        S->top=S->top+1;
        S->wayX[S->top]=i;
        S->wayY[S->top]=j;

    }
}
int pop(struct Stack *S)
{
    int t;
    if(S->top<0)
    cout<<"";
    else
    {
        t=S->wayX[S->top--];
        t=t*10+S->wayY[S->top];
    } 
    return t;
}
void assignPath(struct Stack *S)
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
void navigateGame(struct Stack *S, int i,int j,int dx,int dy)
{
    if(i==dx && j==dy)
    {
        S->elements[i][j]=2;
        cout<<"Way Founded";
    }
    else if(S->elements[i][j-1]==1)
    {
        push(S,i,j-1);
        S->elements[i][j]=2;
        navigateGame(S,i,j-1,dx,dy);

    }
    else if(S->elements[i-1][j]==1)
    {
        push(S,i-1,j);
        S->elements[i][j]=2;
        navigateGame(S,i-1,j,dx,dy);
    }
    else if(S->elements[i+1][j]==1)
    {
        push(S,i+1,j);
        S->elements[i][j]=2;
        navigateGame(S,i+1,j,dx,dy);
    }
    else if(S->elements[i][j+1]==1)
    {
        push(S,i,j+1);
        S->elements[i][j]=2;
        navigateGame(S,i,j+1,dx,dy);
    }
    else if(S->elements[i][j-1]==2)
    {
        pop(S);
        S->elements[i][j]=0;
        navigateGame(S,i,j-1,dx,dy);
    }
    else if(S->elements[i-1][j]==2)
    {
        pop(S);
        S->elements[i][j]=0;
        navigateGame(S,i-1,j,dx,dy);
    }
    else if(S->elements[i+1][j]==2)
    {
        pop(S);
        S->elements[i][j]=0;
        navigateGame(S,i+1,j,dx,dy);
    }
    else if(S->elements[i][j+1]==2)
    {
        pop(S);
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
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    
    int i,j;
    int sx,sy,dx,dy;
    assignPath(S1);

    cout<<"Enter the statring point: ";
    sHere:
    cin>>sx>>sy;
    if(S1->elements[sx][sy]==0)
    {
        cout<<"Invalid Position. Enter again. \n";
        goto sHere;
    }
    cout<<"Enter the Destination point: ";
    dHere:
    cin>>dx>>dy;
    if(S1->elements[dx][dy]==0)
    {
        cout<<"Invalid Position. Enter again. \n";
        goto dHere;
    }
    push(S1,sx,sy);
    navigateGame(S1,sx,sy,dx,dy);
    cout<<endl;
    while (S1->top>0)
    {
        cout<<pop(S1)<<" ";
    }
    cout<<endl<<endl;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(S1->elements[i][j]==2)
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