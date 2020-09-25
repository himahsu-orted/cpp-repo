#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;

typedef struct mlnode
{
    int data;
    struct mlnode *mext;
    struct node *Lnode;
} * ML;

void Linsert(LL START)
{
    LL END, CUR;
    END = START;
    int n;
    cin >> n;
    if (n == -1)
        return;
    while (n > -1)
    {
        CUR = new (struct node);
        CUR->data = n;
        CUR->next = NULL;
        END->next = CUR;
        END = CUR;
        cin >> n;
    }
}
struct node *createList()
{
    int n;
    LL L1;

    cin >> n;
    L1 = new (struct node);
    L1->data = n;
    L1->next = NULL;
    Linsert(L1);

    return L1;
}
void mlInsert(ML START)
{
    ML END, CUR;
    END = START;
    LL L;

    int n;
    cin >> n;
    if(n==-1)
    return;

    if(n == -2)
    {
        L = createList();
        START->Lnode = L;

        cin>>n;
    }

    while (n > -1)
    {
        CUR = new (struct mlnode);
        CUR->data = n;
        CUR->mext = NULL;

        cin >> n;
        if (n == -2)
        {
            L = createList();
            CUR->Lnode = L;

            cin >> n;
        }
        else
        {
            CUR->Lnode = NULL;
        }
        END->mext = CUR;
        END = CUR;
    }
}
struct mlnode *Mcreate()
{
    int n;
    ML M1;
    LL L;

    cin >> n;
    M1 = new (struct mlnode);
    M1->data = n;
    M1->mext = NULL;
    M1->Lnode=NULL;
    mlInsert(M1);

    return M1;
}
void displayMList(ML S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayMList(S->mext);
    }
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayAll(S->next);
    }
}
void displayComb(ML S)
{
    if (S != NULL)
    {
        cout << S->data << " ";

        if (S->Lnode != NULL)
            displayAll(S->Lnode);

        displayComb(S->mext);
    }
}
void removeFirst(LL(&S))
{
    S = S->next;
}
int findNumber(LL S)
{
    int n;
    cin >> n;
    while (S != NULL)
    {
        if (n == S->data)
        {
            return 1;
        }
        else
        {
            S = S->next;
        }
    }
    return 0;
}
void displayRev(LL S)
{
    if (S != NULL)
    {
        displayRev(S->next);
        cout << S->data << " ";
    }
}
void addInFront(LL(&START), int n)
{

    LL CUR;
    CUR = new (struct node);
    CUR->data = n;
    CUR->next = START;
    START = CUR;
}
void insertBefore(LL C, int n, int k)
{
    LL SP, ADD;
    SP = C;
    ADD = new (struct node);
    while (C != NULL)
    {
        if (n == C->data)
        {
            while (SP != NULL)
            {
                if (SP->next == C)
                {
                    ADD->data = k;
                    ADD->next = C;
                    SP->next = ADD;
                    return;
                }
                SP = SP->next;
            }
        }
        C = C->next;
    }
}
void deleteEnd(LL C)
{
    while (C != NULL)
    {
        if ((C->next->next) == NULL)
        {
            C->next = NULL;
            break;
        }
        C = C->next;
    }
}
int findMin(LL C)
{
    int min = C->data;
    while (C != NULL)
    {
        if (C->data < min)
            min = C->data;
        C = C->next;
    }
    return min;
}
int findMax(LL C)
{
    int max = C->data;
    while (C != NULL)
    {
        if (C->data > max)
            max = C->data;
        C = C->next;
    }
    return max;
}
int findMiddleNode(LL C)
{
    LL SP;
    SP = C;
    while (C->next != NULL)
    {
        C = C->next;
        if (C->next != NULL)
        {
            C = C->next;
            SP = SP->next;
        }
        else
            break;
    }
    return SP->data;
}
int countNodes(LL C)
{
    int count = 0;
    while (C != NULL)
    {
        count++;
        C = C->next;
    }
    return count;
}
int numberOfOdds(LL C)
{
    int count = 0;
    while (C != NULL)
    {
        if (C->data % 2 != 0)
            count++;
        C = C->next;
    }
    return count;
}
int numberOfEvens(LL C)
{
    int count = 0;
    while (C != NULL)
    {
        if (C->data % 2 == 0)
            count++;
        C = C->next;
    }
    return count;
}
struct node *insSort(LL C)
{
    LL R = new (struct node);
    LL END, CUR, TEMP;
    END = R;
    CUR = R;

    R->data = C->data;
    R->next = NULL;

    C = C->next;
    while (C != NULL)
    {
        if (C->data >= END->data)
        {
            CUR = new (struct node);
            CUR->data = C->data;
            END->next = CUR;
            END = CUR;
        }
        else
        {
            TEMP = R;
            if (C->data < R->data)
            {
                addInFront(R, C->data);
            }
            else
            {
                while (TEMP != NULL)
                {
                    if (TEMP->data > C->data)
                    {
                        insertBefore(R, TEMP->data, C->data);
                        break;
                    }
                    TEMP = TEMP->next;
                }
            }
        }
        C = C->next;
    }
    return R;
}
void deleteK(LL C, int k)
{
    LL SP;
    SP = C;

    while (C != NULL)
    {
        if (C->data == k)
        {
            while (SP != NULL)
            {
                if (SP->next == C)
                {
                    SP->next = C->next;
                    return;
                }
                SP = SP->next;
            }
        }
        C = C->next;
    }
}
int palindrome(LL C)
{
    LL SP, CON;
    SP = C;
    CON = C;
    while (C->next != NULL)
    {
        C = C->next;
        if (C->next != NULL)
        {
            C = C->next;
            SP = SP->next;
        }
        else
            break;
    }
    int count = 0;
    if (countNodes(SP) % 2 == 0)
    {
        SP = SP->next;
        count = 1;
    }

    while (SP != NULL)
    {
        addInFront(CON, SP->data);
        count++;
        SP = SP->next;
    }
    while (count > 1)
    {
        deleteEnd(CON);
        count--;
    }

    LL CP, LP;
    CP = CON;
    LP = CON;
    while (CP->next != NULL)
    {
        CP = CP->next;
        if (CP->next != NULL)
        {
            CP = CP->next;
            LP = LP->next;
        }
        else
            break;
    }
    LP = LP->next;
    while (LP != NULL)
    {
        if (LP->data != CON->data)
        {
            return 0;
        }
        else
        {
            LP = LP->next;
            CON = CON->next;
        }
    }
    return 1;
}
int main()
{
    ML C;
    C = Mcreate();
    displayComb(C);
}