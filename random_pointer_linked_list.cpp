#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *random;
} * LL;
void removeFirst(LL(&S));
void randomConnector(LL S, int A[])
{
    LL T = S;
    int i = 0;
    while (S != NULL)
    {
        if (A[i] != 0)
        {
            while (T != NULL)
            {
                if (A[i] == T->data)
                {
                    S->random = T;
                    break;
                }
                T = T->next;
            }
        }
        i++;
        T = S;
        S = S->next;
    }
}
int randomCounter(LL S)
{
    int i = 0;
    while (S != NULL)
    {
        if (S->random != NULL)
            i++;

        S = S->next;
    }
    return i;
}
struct node *createList()
{
    int A[20], i;
    for (i = 0; i < 20; i++)
    {
        A[i] = 0;
    }

    LL START;
    START = new (struct node);

    LL END, CUR;
    END = START;
    CUR = START;
    int n, k = 1;
    i = 0;
    while (k > 0)
    {
        cin >> n;
        CUR->data = n;
        CUR->next = NULL;
        CUR->random = NULL;
        END->next = CUR;
        END = CUR;
        CUR = new (struct node);
        cin >> k;
        cin >> n;
        A[i++] = n;
    }
    randomConnector(START, A);
    return START;
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayAll(S->next);
    }
}
void randomDisplay(LL PER, LL S)
{
    LL STORE = PER;
    LL TEMP = PER;
    while (PER != NULL)
    {
        cout << PER->data << " ";
        if (PER == S)
        {
            PER = S->random;
            cout << PER->data << " ";
        }
        if (PER->random != NULL)
        {
            TEMP = PER;
        }
        PER = PER->next;
    }

    cout << endl;

    PER = STORE;
    if (TEMP < S)
        return;
    while (PER != NULL)
    {
        cout << PER->data << " ";
        if (PER == S)
        {
            PER = S->random;
            cout << PER->data << " ";
        }
        if (PER == TEMP)
        {
            PER = TEMP->random;
            cout << PER->data << " ";
        }
        PER = PER->next;
    }
}
void dis(LL S)
{
    LL PER = S;
    while (S != NULL)
    {
        if (S->random != NULL)
        {
            randomDisplay(PER, S);
            cout << endl;
        }
        S = S->next;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL C;
    C = createList();
    displayAll(C);
    cout << endl;
    dis(C);
}