#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void insert(struct node *START)
{
    struct node *END,*CUR;
    END=START;
    int n;
    cin>>n;
    while(n>-1)
    {
        CUR=new(struct node);
        CUR->data=n;
        CUR->next=NULL;
        END->next=CUR;
        END=CUR;
        cin>>n;
    }
}
void displayAll(struct node *S)
{
    if(S!=NULL)
    {
        
        cout<<S->data<<" ";
        displayAll(S->next);
    }
}
void findNumber(struct node *S)
{
    int n;
    cin>>n;
    while(S!=NULL)
    {
        if(n==S->data)
        {
            cout<<"1";
            return;
        }
        else
        {
            S=S->next;
        }
        
    }
    cout<<"0";
}
void displayRev(struct node *S)
{
    if(S!=NULL)
    {
        displayRev(S->next);
        cout<<S->data<<" ";
    }
}
void findMin(struct node *C)
{
    int min=C->data;
    while(C!=NULL)
    {
        if(C->data<min)
        min=C->data;
        C=C->next;
    }
    cout<<min;
}
void findMax(struct node *C)
{
    int max=C->data;
    while(C!=NULL)
    {
        if(C->data>max)
        max=C->data;
        C=C->next;
    }
    cout<<max;
}
void findMiddleNode(struct node *C)
{
    struct node *SP;
    SP=C;
    while(C->next!=NULL)
    {
        C=C->next;
        if(C->next!=NULL)
        {
            C=C->next;
            SP=SP->next;
        }
        else 
        break;
    }
    cout<<SP->data;
}
void countNodes(struct node *C)
{
    int count=0;
    while(C!=NULL)
    {
        count++;
        C=C->next;
    }
    cout<<count;
}
void numberOfOdds(struct node *C)
{
    int count=0;
    while(C!=NULL)
    {
        if(C->data%2!=0)
        count++;
        C=C->next;
    }
    cout<<count;
}
void numberOfEvens(struct node *C)
{
    int count=0;
    while(C!=NULL)
    {
        if(C->data%2==0)
        count++;
        C=C->next;
    }
    cout<<count;
}
int main()
{
    int n;
    cin>>n;
    struct node *START;
    START=new(struct node);
    START->data=n;
    START->next=NULL;
    insert(START);
    displayAll(START);
    cout<<endl;
    displayRev(START);
    cout<<endl;
    countNodes(START);
    cout<<endl;
    findMin(START);
    cout<<endl;
    findMax(START);
    cout<<endl;
    findMiddleNode(START);
    cout<<endl;
    numberOfOdds(START);
    cout<<endl;
    numberOfEvens(START);
    cout<<endl;
    findNumber(START);
}