#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
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
void circularMaker(LL C)
{
    LL PER = C;
    while (C != NULL)
    {
        if (C->next == NULL)
            break;

        C = C->next;
    }
    C->next = PER;
}
LL elementPos(LL S, int n)
{
    while (S != NULL)
    {
        if (S->data == n)
            break;

        S = S->next;
    }
    return S;
}
void oneRound(LL CUR, LL PER, int n)
{
    cout << CUR->data << " ";
    CUR = CUR->next;

    if (CUR == PER)
    {
        cout << CUR->data << " ";
        return;
    }
    else
    {
        if (CUR->data != n)
        {
            oneRound(CUR, PER, n);
        }
        else
        {
            cout << CUR->data << " ";
            cout << endl;
            oneRound(CUR, PER, n);
        }
    }
}
void circleMaker(LL S, int n)
{
    LL PER = S;
    if (n > 1)
    {
        LL TEMP = elementPos(S, n);
        if (TEMP != NULL)
            oneRound(TEMP, TEMP, n);
        else
            return;

        cout << endl;
        circleMaker(PER, --n);
    }
    else
        return;
}
int main()
{

    LL C;
    C = createList();
    circularMaker(C);
    
    circleMaker(C, C->data);
}