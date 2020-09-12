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
        S->top=S->top+1;
        S->elements[S->top]=val;
    }
}

char pop(struct Stack *S)
{
    char t;
    if(S->top<0)
    cout<<"Stack Empty";
    else
    t=S->elements[S->top--];
    return(t); 
}
void push2( struct Stack *S,int val)
{
    if(S->top>= SIZE)
    cout<<"Stack Full";
    else
    {
        S->top=S->top+1;
        S->elements[S->top]=val;
    }
}
int pop2(struct Stack *S)
{
    int t;
    if(S->top<0)
    cout<<"Stack Empty";
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
int eval(int a,int b, char optr)
{
    switch(optr)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
        case '%':
            return a%b;
            break;
        default:
            return 0;
    }
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;      
    S1->top=-1;
    char res[20];
    int pos=0;
    
    string sym;
    cin>>sym;
    for(int i=0;i<sym.length();i++)
    {
        if(isdigit(sym.at(i)))
        {
            res[pos++]=sym.at(i);
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
                    res[pos++]=pop(S1);
                    else pop(S1);
                    if(S1->top==-1)
                    break;
                }
                if(peek(S1)!='(')
                res[pos++]=pop(S1);
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
                    res[pos++]=pop(S1);
                    push(S1,sym.at(i));
                }
            }
            
        }
        
    }
    while(S1->top>-1)
    res[pos++]=pop(S1);

    int len=strlen(res);
    int d1,d2;
    for(int i=0;i<len;i++)
    {
        if(isdigit(res[i]))
        {
            push2(S1,(int)res[i]-48);
        }
        else
        {
            d2=pop2(S1);
            d1=pop2(S1);
            push2(S1,eval(d1,d2,res[i]));
        }
    }
    cout<<endl<<endl<<pop2(S1);
}
