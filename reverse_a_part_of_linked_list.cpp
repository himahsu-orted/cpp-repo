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
struct node *createList()
{
    int n;
    LL L1;

    cin>>n;
    L1=new(struct node);
    L1->data=n;
    L1->next=NULL;
    insert(L1);

    return L1;
}
void removeFirst(LL (&S))
{
    S=S->next;
}
void find(LL C, int s,int e)
{
    LL S,E,PER,R=new(struct node);
    LL CUR,END;
    CUR=R;
    END=R;
    PER=C;

    LL TEMP;
    int i=0;
    while(C!=NULL)
    {
        i++;
        if(i==s)
        S=C;

        if(i==e)
        E=C;

        C=C->next;
    }
    TEMP=S;
    int size=e-s+1;
    int arr[size];

    for(i=size-1;i>=0;i--)
    {
        arr[i]=S->data;
        S=S->next;
    }
    i=0;
    S=TEMP;
    C=PER;
    while(PER!=NULL)
    {
        if(PER->next==S)
        {
            while(S!=E)
            {
                CUR->data=arr[i];
                i++;
                CUR->next=NULL;
                END=new(struct node);
                END->next=NULL;
                CUR->next=END;
                CUR=END;
                
                S=S->next;
            }
            END->data=TEMP->data;
            PER->next=R;
            END->next=E->next;
            return;
        }
        PER=PER->next;
    }
}
int main()
{
    
    LL C;
    int s,e;
    C=createList();
    cin>>s>>e;
    find(C,s,e);
    displayAll(C);
}