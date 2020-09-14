#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Stack
{
    int size;
    int top;
    int elements[SIZE];
};
void push( struct Stack *S,int val)
{
    
        S->top=S->top+1;
        S->elements[S->top]=val;
}
int pop(struct Stack *S)
{
    int t;
    t=S->elements[S->top--];
    return(t); 
}
int peek(struct Stack *S)
{
    int t;
    t=S->elements[S->top];
    return(t); 
}
void strr(string s)
{
    static int count=0;
    int pos=-1;
    if(s.length()>0)
    {
        pos=s.find("()");
        if(pos>-1)
        {
            s.erase(pos+1,pos+1);
            s.insert(pos,"1");
            pos=-1;
        }
    }
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;
    
    string sym;
    cin>>sym;
    int d1,d2;
    int i=0;  
    while(i<sym.length())
    {
        if(sym[i]=='(')
        {
            push(S1,-1);
        }
        else
        {
            if(peek(S1)==-1)
            {
                pop(S1);
                push(S1,1);
            }
            else
            {
                d1=pop(S1);
                d2=pop(S1);
                if(d2>-1)
                {
                    push(S1,d1+d2);
                    i--;
                }
                else
                {
                    push(S1,2*d1);
                }
            }
        }
        i++;
    }
    i=0;
    while(S1->top>-1)
    i+=pop(S1);
    cout<<i;
}