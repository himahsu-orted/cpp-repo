#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;

union u
{
    int intVal;
    char charVal;
    bool boolVal;
    float floatVal;
};
struct Queue
{
    int size;
    int front;
    int rear;
    int flag[SIZE];
    union u *obj[SIZE];
};
struct BQ
{
    int size;
    int front;
    int rear;
    struct Queue *data[SIZE];
};

void ENQ(struct BQ *Q, struct Queue *data)
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
        Q->data[Q->rear]=data;
    }
}
struct Queue *DNQ(struct BQ *Q)
{
    struct Queue *t;
    if(Q->front==-1)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->data[Q->front];
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            t=Q->data[Q->front];
            Q->front=(Q->front+1)%Q->size;
        }
    }
    return t;
}

void enqInt( struct Queue *Q,int val)
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
        Q->flag[Q->rear]=1;
        Q->obj[Q->rear]=new(union u);
        Q->obj[Q->rear]->intVal=val;
    }
}
void enqChar( struct Queue *Q,char val)
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
        Q->flag[Q->rear]=2;
        Q->obj[Q->rear]=new(union u);
        Q->obj[Q->rear]->charVal=val;
    }
}
void enqBool( struct Queue *Q,bool val)
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
        Q->flag[Q->rear]=3;
        Q->obj[Q->rear]=new(union u);
        Q->obj[Q->rear]->boolVal=val;
    }
}
void enqFloat( struct Queue *Q,float val)
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
        Q->flag[Q->rear]=4;
        Q->obj[Q->rear]=new(union u);
        Q->obj[Q->rear]->floatVal=val;
    }
}
int deqInt(struct Queue *Q)
{
    int t;
    if(Q->front==-1)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->obj[Q->front]->intVal;
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            t=Q->obj[Q->front]->intVal;
            Q->front=(Q->front+1)%Q->size;
        }
    }
    return t;
}
char deqChar(struct Queue *Q)
{
    char t;
    if(Q->front==-1)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->obj[Q->front]->charVal;
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            t=Q->obj[Q->front]->charVal;
            Q->front=(Q->front+1)%Q->size;
        }
    }
    return t;
}
bool deqBool(struct Queue *Q)
{
    bool t;
    if(Q->front==-1)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->obj[Q->front]->boolVal;
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            t=Q->obj[Q->front]->boolVal;
            Q->front=(Q->front+1)%Q->size;
        }
    }
    return t;
}
float deqFloat(struct Queue *Q)
{
    float t;
    if(Q->front==-1)
    cout<<"Queue Empty";
    else
    {
        if(Q->front==Q->rear)
        {
            t=Q->obj[Q->front]->floatVal;
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            t=Q->obj[Q->front]->floatVal;
            Q->front=(Q->front+1)%Q->size;
        }
    }
    return t;
}
int flagCheck(struct Queue *Q)
{
    return Q->flag[Q->front];
}

struct Queue *inp()
{
    struct Queue *Q1=new(struct Queue);
    Q1->size=SIZE-1;
    Q1->front=-1;
    Q1->rear=-1;

    int ival;
    char cval;
    float fval;
    bool bval;

    char ch;
    
    do
    {
        cout<<"\nStore what? 1.Integer\n2.Character\n3.Bool\n4.Float...";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cin>>ival;
                enqInt(Q1,ival);
                break;
            case 2:
                cin>>cval;
                enqChar(Q1,cval);
                break;
            case 3:
                cin>>bval;
                enqBool(Q1,bval);
                break;
            case 4:
                cin>>fval;
                enqFloat(Q1,fval);
                break;
            default:
                cout<<"Invalid Input !";
        }
        cout<<"\nDo you want to enter more? y/n... ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
    cout<<endl;
    return Q1;
    
}
void oup( struct Queue *Q1)
{
    while(Q1->front>-1)
    {
        if(flagCheck(Q1)==1)
        cout<<deqInt(Q1)<<" ";
        else if(flagCheck(Q1)==2)
        cout<<deqChar(Q1)<<" ";
        else if(flagCheck(Q1)==3)
        cout<<deqBool(Q1)<<" ";
        else
        cout<<deqFloat(Q1)<<" ";
    }
}
int main()
{
    struct BQ *Q=new(struct BQ);
    Q->size=SIZE-1;
    Q->front=-1;
    Q->rear=-1;

    char ch;
    cout<<"ENQUE:\n";
    do
    {
        ENQ(Q,inp());
        cout<<"Do you want to continue? y/n";
        cin>>ch;
    } while (ch=='y'||ch=='Y');
    cout<<"\nDENQUE:\n";
    do
    {
        oup(DNQ(Q));
        cout<<"Do you want to continue? y/n";
        cin>>ch;
    } while (ch=='y'||ch=='Y');
}
