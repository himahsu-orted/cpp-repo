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
struct node *unionFunc(LL L1,LL L2)
{
    LL R,CUR,END;
    CUR=new(struct node);
    R=CUR;
    END=R;
    while(L1!=NULL)
    {
        while(L2!=NULL)
        {
            if(L2->data<L1->data)
            {
                CUR->data=L2->data;
                END=new(struct node);
                CUR->next=END;
                CUR=END;
                L2=L2->next;
            }
            else if(L2->data==L1->data)
            L2=L2->next;
            else
            {
                break;
            }
        }
        CUR->data=L1->data;
        END=new(struct node);
        CUR->next=END;
        CUR=END;

        L1=L1->next;
    }
    while(L2!=NULL)
    {
        CUR->data=L2->data;
        END=new(struct node);
        CUR->next=END;
        CUR=END;
        L2=L2->next;
    }
    deleteEnd(R);
    return R;
}
struct node *un(LL L1,LL L2)
{
    LL R,CUR,END;
    CUR=new(struct node);
    R=CUR;
    END=R;

    LL B1;
    B1=L1;
    while(L1!=NULL)
    {
        CUR->data=L1->data;
        END=new(struct node);
        CUR->next=END;
        CUR=END;

        L1=L1->next;
    }
    L1=B1;
    int count=0;
    while(L2!=NULL)
    {
        while(L1!=NULL)
        {
            if(L2->data==L1->data)
            {
                count++;
            }
            L1=L1->next;
        }
        if(count==0)
        {
            CUR->data=L2->data;
            END=new(struct node);
            CUR->next=END;
            CUR=END;
        }
        else count=0;
        L1=B1;
        L2=L2->next;
    }
    deleteEnd(R);
    return R;
}
struct node *diff(LL L1,LL L2)
{
    LL R,CUR,END;
    CUR=new(struct node);
    R=CUR;
    END=R;

    LL B1;
    B1=L1;
    int count=0;
    while(L2!=NULL)
    {
        while(L1!=NULL)
        {
            if(L2->data==L1->data)
            {
                count++;
            }
            L1=L1->next;
        }
        if(count==0)
        {
            CUR->data=L2->data;
            END=new(struct node);
            CUR->next=END;
            CUR=END;
        }
        else count=0;
        L1=B1;
        L2=L2->next;
    }
    deleteEnd(R);
    return R;
}
struct node *intersectionFunc(LL L1,LL L2)
{
    LL R,CUR,END,S=L2;
    CUR=new(struct node);
    R=CUR;
    END=R;
    while(L1!=NULL)
    {
        L2=S;
        while(L2!=NULL)
        {
            if(L2->data==L1->data)
            {
                CUR->data=L2->data;
                END=new(struct node);
                CUR->next=END;
                CUR=END;
                break;
            }
            else
            L2=L2->next;
        }
        L1=L1->next;
    }
    if(R->next!=NULL)
    deleteEnd(R);
    return R;
}

int main()
{
    int n;
    cin>>n;
    LL L1,L2,R;

    L1=new(struct node);
    L1->data=n;
    L1->next=NULL;
    insert(L1);
    
    cin>>n;
    L2=new(struct node);
    L2->data=n;
    L2->next=NULL;
    insert(L2);
    if(L1->data>L2->data)
    R=unionFunc(L1,L2);
    else
    R=unionFunc(L2,L1); 
    
    cout<<endl;
    displayAll(R);

    R=intersectionFunc(L1,L2);
    
    cout<<endl;
    displayAll(R);

    R=diff(L2,L1);
    
    cout<<endl;
    displayAll(R);

    
    LL L3,L4;

    cin>>n;
    L3=new(struct node);
    L3->data=n;
    L3->next=NULL;
    insert(L3);
    
    cin>>n;
    L4=new(struct node);
    L4->data=n;
    L4->next=NULL;
    insert(L4);

    R=un(L3,L4);
    
    
    displayAll(R);

    R=intersectionFunc(L3,L4);
    
    cout<<endl;
    displayAll(R);

    R=diff(L4,L3);
    
    cout<<endl;
    displayAll(R);

}