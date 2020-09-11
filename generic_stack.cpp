#include <bits/stdc++.h> 
  
using namespace std;

union u
{
    int intVal;
    char charVal;
    bool boolVal;
    float floatVal;
};

const int SIZE=100;

struct Stack
{
    int size;
    int top;
    int flag[SIZE];
    union u *obj[SIZE];
};
void pushInt( struct Stack *S,int val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->flag[S->top]=1;
        S->obj[S->top]=new(union u);
        S->obj[S->top]->intVal=val;
    }
}
void pushChar( struct Stack *S,char val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->flag[S->top]=2;
        S->obj[S->top]=new(union u);
        S->obj[S->top]->charVal=val;
    }
}
void pushBool( struct Stack *S,bool val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->flag[S->top]=3;
        S->obj[S->top]=new(union u);
        S->obj[S->top]->boolVal=val;
    }
}
void pushFloat( struct Stack *S,float val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->flag[S->top]=4;
        S->obj[S->top]=new(union u);
        S->obj[S->top]->floatVal=val;
    }
}
int popInt(struct Stack *S)
{
    int t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->obj[S->top--]->intVal;
    return(t); 
}
char popChar(struct Stack *S)
{
    char t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->obj[S->top--]->charVal;
    return(t); 
}
bool popBool(struct Stack *S)
{
    bool t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->obj[S->top--]->boolVal;
    return(t); 
}
float popFloat(struct Stack *S)
{
    float t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->obj[S->top--]->floatVal;
    return(t); 
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;

    int ival;
    float fval;
    char cval,ch;
    bool bval;

    do
    {
        cout<<"\nStore what? 1.Integer\n2.Character\n3.Bool\n4.Float...";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cin>>ival;
                pushInt(S1,ival);
                break;
            case 2:
                cin>>cval;
                pushChar(S1,cval);
                break;
            case 3:
                cin>>bval;
                pushBool(S1,bval);
                break;
            case 4:
                cin>>fval;
                pushFloat(S1,fval);
                break;
            default:
                cout<<"Invalid Input !";
        }
        cout<<"\nDo you want to enter more? y/n... ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
    cout<<endl;
    while(S1->top>-1)
    {
        if(S1->flag[S1->top]==1)
        cout<<popInt(S1)<<" ";
        else if(S1->flag[S1->top]==2)
        cout<<popChar(S1)<<" ";
        else if(S1->flag[S1->top]==3)
        cout<<popBool(S1)<<" ";
        else
        cout<<popFloat(S1)<<" ";
    }
}


