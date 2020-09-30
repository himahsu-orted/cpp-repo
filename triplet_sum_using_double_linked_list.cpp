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
    int temp = l->data;
    l->data = h->data;
    h->data = temp;
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
void findTriplet(DL L, int n)
{

    DL i = L;
    DL END = L;
    while (END != NULL)
    {
        if (END->right == NULL)
            break;

        END = END->right;
    }
    while (i != NULL)
    {
        int fVal = i->data;
        DL MP = L;
        DL LP = END;

        while (MP < LP)
        {
            if (fVal * 2 + MP->data + LP->data == n)
            {
                if(fVal!=MP->data&& MP->data!=LP->data && fVal!=LP->data)
                {
                    cout << fVal << " " << MP->data << " " << LP->data;
                    cout << endl;
                }
                MP = MP->right;
                LP = LP->left;
            }
            else if (fVal * 2 + MP->data + LP->data < n)
            {
                MP = MP->right;
            }
            else if (fVal * 2 + MP->data + LP->data > n)
            {
                LP = LP->left;
            }
        }
        i = i->right;
        if (i->right == NULL)
            break;
    }
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

    DL L;
    L = createList();
    quickSortController(L);
    findTriplet(L, 19);
}