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
void makeLink(LL A, LL B)
{
    while (A != NULL)
    {
        if (A->data == 6)
        {
            while (B != NULL)
            {
                if (B->next == NULL)
                {
                    B->next = A;
                    return;
                }
                B = B->next;
            }
            return;
        }
        A = A->next;
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
void findL(LL A, LL B)
{
    LL PB = B;
    LL PA = A;
    deleteEnd(A);
    while (A->next != NULL)
    {
        A = A->next;
    }
    while (B->next != NULL)
    {
        B = B->next;
    }
    if (A == B)
        findL(PA, PB);
    else
        cout << B->data;
}
int main()
{
    LL A, B;
    A = createList();
    B = createList();
    makeLink(A, B);

    findL(A, B);
}
