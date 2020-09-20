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
void displayAll(LL S)
{
    if(S!=NULL)
    {
        
        cout<<S->data<<" ";
        displayAll(S->next);
    }
}
void removeFirst(LL (&S))
{
    S=S->next;
}
void findNumber(LL S)
{
    int n;
    cin>>n;
    while(S!=NULL)
    {
        if(n==S->data)
        {
            cout<<"Found\n";
            return;
        }
        else
        {
            S=S->next;
        }
        
    }
    cout<<"Not Found\n";
}
void displayRev(LL S)
{
    if(S!=NULL)
    {
        displayRev(S->next);
        cout<<S->data<<" ";
    }
}
void addInFront(LL (&START))
{
    int n;
    cin>>n;
    LL CUR;
    CUR=new(struct node);
    CUR->data=n;
    CUR->next=START;
    START=CUR;
}
void insertBefore(LL C)
{
    cout<<"\nInsert Before Which Number? ";
    int n;
    cin>>n;
    cout<<"Insert What? ";
    int k;
    cin>>k;

    LL SP,ADD;
    SP=C;
    ADD=new(struct node);
    while(C!=NULL)
    {
        if(n==C->data)
        {
            while(SP!=NULL)
            {
                if(SP->next==C)
                {
                    ADD->data=k;
                    ADD->next=C;
                    SP->next=ADD;
                    return;
                }
                SP=SP->next;
            }
        }
        C=C->next;
    }
    cout<<"\nNUMBER NOT FOUND.\n";
}
void deleteEnd(LL C)
{
    while(C!=NULL)
    {
        if((C->next->next)==NULL)
        {
            C->next=NULL;
            break;
        }
        C=C->next;
    }
}
void findMin(LL C)
{
    int min=C->data;
    while(C!=NULL)
    {
        if(C->data<min)
        min=C->data;
        C=C->next;
    }
    cout<<"\nMinimun Data: "<<min<<endl;
}
void findMax(LL C)
{
    int max=C->data;
    while(C!=NULL)
    {
        if(C->data>max)
        max=C->data;
        C=C->next;
    }
    cout<<"\nMaximun Data: "<<max<<endl;
}
void findMiddleNode(LL C)
{
    LL SP;
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
void countNodes(LL C)
{
    int count=0;
    while(C!=NULL)
    {
        count++;
        C=C->next;
    }
    cout<<count;
}
void numberOfOdds(LL C)
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
void numberOfEvens(LL C)
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
void controller(LL (&START),int n)
{
    switch (n)
    {
        case 1:
            displayAll(START);
            break;
        case 2:
            removeFirst(START);
            break;
        case 3:
            findNumber(START);
            break;
        case 4:
            displayRev(START);
            break;
        case 5:
            addInFront(START);
            break;
        case 6:
            insertBefore(START);
            break;
        case 7:
            deleteEnd(START);
            break;
        case 8:
            findMin(START);
            break;
        case 9:
            findMax(START);
            break;
        case 10:
            findMiddleNode(START);
            break;
        case 11:
            countNodes(START);
            break;
        case 12:
            numberOfOdds(START);
            break;
        case 13:
            numberOfEvens(START);
            break;
    }
}
int main()
{
    cout<<"Enter data for linked list and -1 to terminate the input: ";
    int n;
    cin>>n;
    LL START;
    START=new(struct node);
    START->data=n;
    START->next=NULL;
    insert(START);
    char ch;
    do
    {
        cout<<"\nEnter your preference: \n";
        cout<<"1.Display All\n2.Remove First\n3.Find a number\n4.Diplay in Reverse\n5.Add in Front";
        cout<<"\n6.Insert Before\n7.Delete End\n8.Find Min\n9.Find Max\n10.Find Middle Node\n11.Count Number of Nodes";
        cout<<"\n12.Number of Odds\n13.Number of Evens\n";
        cin>>n;
        controller(START,n);
        cout<<"Do you want to continue? y/n";
        cin>>ch;
    } while (ch=='y'||ch=='Y');
    
}