#include<bits/stdc++.h>
using namespace std;

const int SIZE=100;
struct Stack
{
    int size;
    int top;
    string elements[SIZE];
};
void push( struct Stack *S,string val)
{
   
        S->top=S->top+1;
        S->elements[S->top]=val;
}
string pop(struct Stack *S)
{
    string t;
    
    t=S->elements[S->top--];
    return(t); 
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;
    S1->top=-1;

    string sym;
    cin>>sym;
    for(int i=sym.length()-1;i>=0;i--)
    {

        if(isdigit(sym.at(i)))
        {
            push(S1,to_string((int)sym[i]-48));
            
        }
        else
        {
            push(S1,'('+pop(S1)+sym.at(i)+pop(S1)+')');
        }
    }
    while(S1->top>-1)
    cout<<pop(S1);
}