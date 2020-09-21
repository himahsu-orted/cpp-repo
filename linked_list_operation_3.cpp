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
void addInFront(LL (&START),int n)
{
    LL CUR;
    CUR=new(struct node);
    CUR->data=n;
    CUR->next=START;
    START=CUR;
}
int countNodes(LL C)
{
    int count=0;
    while(C!=NULL)
    {
        count++;
        C=C->next;
    }
    return count;
}
void palindrome(LL C)
{
    LL SP,CON;
    SP=C;
    CON=C;
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
    int count=0;
    if(countNodes(SP)%2==0)
    {
        SP=SP->next;
        count=1;
    }
    
    while(SP!=NULL)
    {
        addInFront(CON,SP->data);
        count++;
        SP=SP->next;
    }
    while(count>1)
    {  
        deleteEnd(CON);
        count--;
    }
    
    LL CP,LP;
    CP=CON;
    LP=CON;
    while(CP->next!=NULL)
    {
        CP=CP->next;
        if(CP->next!=NULL)
        {
            CP=CP->next;
            LP=LP->next;
        }
        else 
        break;
    }
    LP=LP->next;
    while(LP!=NULL)
    {
        if(LP->data!=CON->data)
        {
            cout<<0;
            return;
        }
        else
        {
            LP=LP->next;
            CON=CON->next;
        }
    }
    cout<<1;
}
void deleteK(LL C,int k)
{
    LL SP;
    SP=C;
    
        while(C!=NULL)
        {
            if(C->data==k)
            {
                while(SP!=NULL)
                {
                    if(SP->next==C)
                    {
                        SP->next=C->next;
                        return;
                    }
                    SP=SP->next;
                }
            }
            C=C->next;
        }
    
}void removeLastDup(LL C)
{
    LL PER=C;
    LL FOUND=C;
    while(PER->next!=NULL)
    {
        while(C->next!=NULL)
        {
            if(C->next->data==PER->data)
            {
                FOUND=C;
            }
            C=C->next;
        }
        if(FOUND!=PER)
        {
            if(FOUND->next->next!=NULL)
            FOUND->next=FOUND->next->next;
            else 
            {
                FOUND->next=NULL;
            }
        }
        if(PER->next!=NULL)
        {
            PER=PER->next;
            C=PER;
            FOUND=C;
        }
        else break;
        
    }
}
void removeUnsortedDup(LL C)
{
    LL PER=C;
    while(PER->next!=NULL)
    {
        while(C->next!=NULL)
        {
            if(C->next->data==PER->data)
            {
                if(C->next->next!=NULL)
                C->next=C->next->next;
                else 
                {
                    C->next=NULL;
                    break;
                }
            }
            C=C->next;
        }
        if(PER->next!=NULL)
        PER=PER->next;
        else break;
        C=PER;
    }
}
void removeSortedDup(LL C,LL PER)
{

    if(C->next!=NULL)
    {
        if(PER->data==C->next->data)
        {
            C=C->next;
        }
        else
        {
            PER->next=C->next;
            C=C->next;
            PER=C;
        }
        removeSortedDup(C,PER);
    }
    else 
    PER->next=NULL;
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
struct node *evenOdd(LL C)
{
    LL R=new(struct node),TEMP=C;
    LL END,CUR;
    END=R;
    CUR=R;
    while(C!=NULL)
    {
        if(C->data%2==0)
        {
            CUR->data=C->data;
            END=new(struct node);
            CUR->next=END;
            CUR=END;
        }
        C=C->next;
    }
    while(TEMP!=NULL)
    {
        if(TEMP->data%2!=0)
        {
            CUR->data=TEMP->data;
            if(TEMP->next!=NULL)
            END=new(struct node);
            CUR->next=END;
            CUR=END;
        }
        TEMP=TEMP->next;
    }
    deleteEnd(R);
    return R;
    
}
void insertBefore(LL C,int n,int k)
{
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
}
struct node *insSort(LL C)
{
    LL R=new(struct node);
    LL END,CUR,TEMP;
    END=R;
    CUR=R;

    R->data=C->data;
    R->next=NULL;

    C=C->next;
    while(C!=NULL)
    {
        if(C->data>=END->data)
        {
            CUR=new(struct node);
            CUR->data=C->data;
            END->next=CUR;
            END=CUR;
        }
        else 
        {
            TEMP=R;
            if(C->data<R->data)
            {
                addInFront(R,C->data);
            }   
            else
            {
                while(TEMP!=NULL)
                {
                    if(TEMP->data>C->data)
                    {
                        insertBefore(R,TEMP->data,C->data);
                        break;
                    }
                    TEMP=TEMP->next;
                }
            }
        }
        C=C->next;
    }
    return R;


}
struct node *rev(LL C)
{
    static LL PER;
    if(C->next==NULL)
    {
        PER=C;
        return PER;
    }
    else
    {
        rev(C->next);  
        LL P=C->next;
        P->next=C;
        C->next=NULL;
        return PER;
    }
}
void swapK(LL C)
{
    int k,i=0,j=0;
    cin>>k;

    LL S=C;
    LL E=C;
    LL TEMP;
    while(C!=NULL)
    {
        i++;
        if(i==k)
        S=C;

        TEMP=C;
        while(TEMP!=NULL)
        {
            j++;
            TEMP=TEMP->next;
        }
        if(j==k)
        {
            E=C;
            break;
        }
        else 
        {
            j=0;
        }

        C=C->next;
    }

    k=S->data;
    S->data=E->data;
    E->data=k;
}
void inL1(LL C, LL D)
{
    LL TEMP=D;
    while(C!=NULL)
    {
        TEMP=D;
        if(C->data==TEMP->data)
        {
            while(TEMP!=NULL)
            {
                if(TEMP->data==C->data)
                {
                    C=C->next;
                    TEMP=TEMP->next;
                }
                else
                {
                    break;
                }
            }
            if(TEMP==NULL)
            {
                cout<<1;
                return;
            }
        }
        C=C->next;
    }
    cout<<0;
}
void comb(LL C, LL D)
{
    while(C!=NULL && D!=NULL)
    {
        cout<<C->data<<" "<<D->data<<" ";
        C=C->next;
        D=D->next;
    }
    while(C!=NULL)
    {
        cout<<C->data<<" ";
        C=C->next;
    }
    while(D!=NULL)
    {
        cout<<D->data<<" ";
        D=D->next;
    }
}
int main()
{
    
    LL C,D;
    C=createList();
    palindrome(C);

    C=createList();
    removeSortedDup(C,C);
    displayAll(C);

    C=createList();
    removeUnsortedDup(C);
    displayAll(C);

    C=createList();
    removeLastDup(C);
    displayAll(C);

    C=createList();
    C=evenOdd(C);
    displayAll(C);

    C=createList();
    C=insSort(C);
    displayAll(C);
    
    C=createList();
    LL PER=C;
    C=rev(C);
    displayAll(C);

    C=createList();
    swapK(C);
    displayAll(C);

    C=createList();
    D=createList();
    inL1(C,D);

    C=createList();
    D=createList();
    comb(C,D);
}