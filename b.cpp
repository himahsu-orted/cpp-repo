#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    int data;
    struct node *next;
} * LL;
void insert(LL START)
{
    LL END,CUR;
    END=START;


    int k;
    char ch,n;
    cin>>n;

    if(n=='#')
    return;

    if(n=='0')
    cin>>ch;
    else 
    cin>>k;

    while(n!='#')
    {
        
        CUR=new(struct node);
        if(n=='0')
        CUR->data=(int)ch;
        else 
        CUR->data=k;
        CUR->next=NULL;
        END->next=CUR;
        END=CUR;
        cout<<"herer";
        if(n=='#')
        return;
    
        if(n=='0')
        cin>>ch;
        else 
        cin>>k;
    }
}
void displayAll(LL S)
{
    if(S!=NULL)
    {
        
        cout<<S->data<<" ";
        displayAll(S->next);
    }
}

struct node *createList()
{
    char ch;
    LL L1;

    cin>>ch;
    L1=new(struct node);
    L1->data=-1;
    L1->next=NULL;
    insert(L1);
    return L1;
}
void removeFirst(LL (&S))
{
    S=S->next;
}
int main()
{
    
    LL C;
    C=createList();
    removeFirst(C);
    displayAll(C);
}