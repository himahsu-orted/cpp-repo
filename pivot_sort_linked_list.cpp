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
void sortM(LL C)
{
    LL RUN = C, M;
    int min = C->data, cur, temp;
    while (C != NULL)
    {
        cur = C->data;
        min = C->data;
        while (RUN != NULL)
        {
            if (RUN->data < min)
            {
                min = RUN->data;
                M = RUN;
            }

            RUN = RUN->next;
        }
        if (cur > min)
        {
            temp = C->data;
            C->data = M->data;
            M->data = temp;
        }
        C = C->next;
        RUN = C;
        M = C;
    }
}
int main()
{
    LL A;
    A = createList();
    sortM(A);
    displayAll(A);
}
