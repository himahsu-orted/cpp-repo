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
void displayAll(LL S)
{
    if (S != NULL)
    {
        if (S->data != 0)
            cout << S->data << " ";
        displayAll(S->next);
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
static int re1(int pre, LL C)
{

    if (C != NULL)
    {
        int later = re1(pre, C->next);
        if (later == 0)
            return C->data;
        else
        {
            return (C->data * 10 + later);
        }
    }
    return 0;
}
static int re2(int pre, LL D)
{
    if (D != NULL)
    {
        int later = re1(pre, D->next);
        if (later == 0)
            return D->data;
        else
        {
            return (D->data * 10 + later);
        }
    }
    return 0;
}

int main()
{

    LL C, D;
    C = createList();
    D = createList();
    cout << re1(C->data, C) + re2(D->data, D);
}
