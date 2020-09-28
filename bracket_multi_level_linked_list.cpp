#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    char data;
    struct node *next;
    struct node *Lnode;
} * LL;
struct node *createList();
void insert(LL START)
{
    LL END, CUR;
    END = START;
    char n;
    cin >> n;

    while (n != '#')
    {
        if (n == '{')
            END->Lnode = createList();
        else if (n == '}')
            return;
        else
        {
            CUR = new (struct node);
            CUR->data = n;
            CUR->next = NULL;
            CUR->Lnode = NULL;
            END->next = CUR;
            END = CUR;
        }
        cin >> n;
    }
}
struct node *createList()
{
    char n;
    LL L1;

    cin >> n;
    L1 = new (struct node);
    L1->data = n;
    L1->next = NULL;
    L1->Lnode = NULL;
    insert(L1);

    return L1;
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        if (S->Lnode != NULL)
        {
            cout << "{ ";
            displayAll(S->Lnode);
            cout << "} ";
        }
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
char game(LL L1, LL L2)
{
    int a = 0, b = 0;
    bool aChance = true;
    while (L1 != NULL)
    {
        if (aChance == true)
        {
            a = L1->data;
            aChance = false;
        }
        else
        {
            b = b + L1->data;
            aChance = true;
        }
        L1 = L1->next;
    }
    aChance = true;
    while (L2 != NULL)
    {
        if (aChance == true)
        {
            a = L2->data;
            aChance = false;
        }
        else
        {
            b = b + L2->data;
            aChance = true;
        }
        L2 = L2->next;
    }
    if (a > b)
        return 'A';
    else
        return 'B';
}
int main()
{
    LL L1;
    char temp;
    cin >> temp;
    if (temp == '{')
        L1 = createList();
    cout << "{ ";
    displayAll(L1);
    cout << "}";
}