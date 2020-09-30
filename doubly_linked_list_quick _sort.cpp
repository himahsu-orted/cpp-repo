#include <bits/stdc++.h>
using namespace std;

typedef struct Dnode
{
    struct Dnode *left;
    int data;
    struct Dnode *right;

} * DL;
void insert(DL START)
{
    DL END, CUR;
    END = START;

    int n;
    cin >> n;
    while (n > -1)
    {
        CUR = new (struct Dnode);
        CUR->data = n;
        CUR->right = NULL;
        CUR->left = END;
        END->right = CUR;
        END = CUR;
        cin >> n;
    }
}
struct Dnode *createList()
{
    int n;
    DL L1;

    cin >> n;
    L1 = new (struct Dnode);
    L1->data = n;
    L1->left = NULL;
    L1->right = NULL;
    insert(L1);

    return L1;
}
void displayAll(DL S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayAll(S->right);
    }
}
void swapDL(DL l, DL h)
{
    int n = l->data;
    l->data = h->data;
    h->data = n;
}
struct Dnode *breakDL(DL l, DL h)
{
    int pivot = h->data;
    DL pos = l->left;

    for (DL i = l; i != h; i = i->right)
    {
        if (i->data <= pivot)
        {
            if (pos == NULL)
                pos = l;
            else
                pos = pos->right;
            swapDL(i, pos);
        }
    }
    if (pos == NULL)
        pos = l;
    else
        pos = pos->right;
    swapDL(pos, h);
    return pos;
}
void quickSort(DL low, DL high)
{
    DL pos;
    if (low != NULL && high != NULL && low != high->right)
    {
        pos = breakDL(low, high);
        quickSort(low, pos->left);
        quickSort(pos->right, high);
    }
}
void quickSortController(DL L)
{
    DL PER = L;
    while (L->right != NULL)
        L = L->right;

    quickSort(PER, L);
}
int main()
{

    DL L;
    L = createList();

    quickSortController(L);
    cout << endl;
    displayAll(L);
}