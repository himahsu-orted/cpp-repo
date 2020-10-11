#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
typedef struct Bnode
{
    struct node *first;
    struct node *second;
    struct Bnode *Bnext;
} * BL;
void insert(LL START)
{
    LL END, CUR;
    END = START;
    int n;
    cin >> n;
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
    insert(L1);

    return L1;
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayAll(S->next);
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
BL createBL(LL A, LL B)
{
    BL BList = new (struct Bnode);
    BL END, CUR;
    BList->first = A;

    END = BList;
    while (B != NULL)
    {
        if (B->next == NULL)
            break;

        if (B->data > A->data)
        {
            while (A != NULL)
            {
                if (A->next == NULL)
                    break;

                if (A->data > B->data)
                    break;

                A = A->next;
            }
            END->second = B;
            CUR = new (struct Bnode);
            CUR->first = A;
            CUR->Bnext = NULL;
            END->Bnext = CUR;
            END = CUR;
        }
        B = B->next;
    }

    return BList;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL A, B;
    A = createList();
    B = createList();

    BL BList = createBL(A, B);

    while (BList != NULL)
    {
        if (BList->Bnext == NULL)
            break;

        while (BList->first != NULL)
        {

            if (BList->second != NULL)
            {
                if (BList->first->data > BList->second->data)
                    break;
            }
            cout << BList->first->data << " ";

            BList->first = BList->first->next;
        }
        while (BList->second != NULL)
        {

            if (BList->first != NULL)
            {
                if (BList->second->data > BList->first->data)
                    break;
            }

            cout << BList->second->data << " ";

            BList->second = BList->second->next;
        }

        BList = BList->Bnext;
    }
}