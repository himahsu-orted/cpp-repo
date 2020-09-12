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
    t='n';
    else
    t=S->elements[S->top--];
    return(t); 
}
char bracketList(char ch)
{
    char val;
    char openSet[4]={'(','{','[','<'};
    char closedSet[4]={')','}',']','>'};
    for(int i=0;i<4;i++)
    {
        if(ch==closedSet[i])
        val=openSet[i];
    }
    return val;
}
int main()
{
    struct Stack *S1=new(struct Stack);
    S1->size=SIZE-1;      
    S1->top=-1;
    int count=0;

    string sym;
    cin>>sym;
    for(int i=0;i<sym.length();i++)
    {
        if(sym.at(i)=='('||sym.at(i)=='{'||sym.at(i)=='['||sym.at(i)=='<')
        push(S1,sym.at(i));
        else if(sym.at(i)==')'||sym.at(i)=='}'||sym.at(i)==']'||sym.at(i)=='>')
        {
            if(pop(S1)!=bracketList(sym.at(i)))
            {
                goto here;
            }
            else
            count++;
        }
    }
    here:
    cout<<endl;
    if(count==sym.length()/2)
    cout<<"BALANCED";
    else cout<<"NEED "<<S1->top+count+1<<" BRACKETS TO BALANCE.";
}
