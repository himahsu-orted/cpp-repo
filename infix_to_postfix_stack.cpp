#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Stack
{
    int size;
    int top;
    char elements[SIZE];
};
void push( struct Stack *S,char val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        //cout<<" val "<<val;
        S->top=S->top+1;
        S->elements[S->top]=val;
    }
}
char pop(struct Stack *S)
{
    char t;
    if(S->top<0)
    cout<<"Stack Emptyzzz";
    else
    t=S->elements[S->top--];
    return(t); 
}
char peek(struct Stack *S)
{
    char t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->elements[S->top];
    return(t); 
}
int priorityCheck(char ch)
{
    if(ch=='+' || ch=='-')
    return 1;
    else if(ch=='*' || ch=='/' ||ch=='%')
    return 2;
    else return 0;
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;      
    S1->top=-1;
    
    string sym;
    cin>>sym;
    for(int i=0;i<sym.length();i++)
    {
        if(isdigit(sym.at(i)))
        {
            cout<<(int)sym.at(i)-48;
        }
        else
        {
            if(sym.at(i)=='(')
            {
                push(S1,sym.at(i));
            }
            else if(sym.at(i)==')')
            {
                while(peek(S1)!='(')
                {
                    if(peek(S1)!='(')
                    cout<<pop(S1);
                    else pop(S1);
                    if(S1->top==-1)
                    break;
                }
                if(peek(S1)!='(')
                cout<<pop(S1);
                else pop(S1);
            }
            else if(S1->top==-1)
            {
                push(S1,sym.at(i));
            }
            else
            {
                if(priorityCheck(sym.at(i))>priorityCheck(peek(S1)))
                {
                    push(S1,sym.at(i));
                }
                else
                {
                    cout<<pop(S1);
                    push(S1,sym.at(i));
                }
            }
            
        }
        
    }
    while(S1->top>-1)
    cout<<pop(S1);
}
