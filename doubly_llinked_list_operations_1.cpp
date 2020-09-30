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
void removeFirst(DL(&S))
{
    S = S->right;
}
int findNumber(DL S)
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
            S = S->right;
        }
    }
    return 0;
}
void displayRev(DL S)
{
    if (S != NULL)
    {
        displayRev(S->right);
        cout << S->data << " ";
    }
}
void addInFront(DL(&START), int n)
{

    DL CUR;
    CUR = new (struct Dnode);
    CUR->data = n;
    CUR->left = NULL;
    START->left = CUR;
    CUR->right = START;
    START = CUR;
}
void insertAfter(DL C, int n, int k)
{
    while (C->right != NULL)
    {
        if (C->data == k)
        {
            if (C->right == NULL)
            {
                addInEnd(C, n);
                return;
            }
            DL ADD = new (struct Dnode);
            ADD->data = n;
            ADD->right = C->right;
            ADD->left = C;
            C->right->left = ADD;
            C->right = ADD;
        }
    }
}
void insertBefore(DL C, int n, int k)
{
    //Insert n before k
    if (k == C->data)
    {
        addInFront(C, n);
        return;
    }
    while (C != NULL)
    {
        if (C->data == k)
        {
            DL ADD;
            ADD = new (struct Dnode);
            ADD->data = n;
            ADD->right = C;
            ADD->left = C->left->right;
            C->left->right = ADD;
            C->left = ADD;
        }
    }
}
void deleteEnd(DL C)
{
    while (C != NULL)
    {
        if (C->right == NULL)
        {
            C->left->right = NULL;
            break;
        }
    }
}
void addInEnd(DL C, int n)
{
    while (C->right != NULL)
    {
        C = C->right;
    }

    DL ADD = new (struct Dnode);
    ADD->data = n;
    ADD->right = NULL;
    ADD->left = C;
    C->right = ADD;
}
int findMin(DL C)
{
    int min = C->data;

    while (C != NULL)
    {
        if (C->data < min)
            min = C->data;
        C = C->right;
    }
    return min;
}
int findMax(DL C)
{
    int max = C->data;
    while (C != NULL)
    {
        if (C->data > max)
            max = C->data;
        C = C->right;
    }
    return max;
}
int findMiddleNode(DL C)
{
    DL SP;
    SP = C;
    while (C->right != NULL)
    {
        C = C->right;
        if (C->right != NULL)
        {
            C = C->right;
            SP = SP->right;
        }
        else
            break;
    }
    return SP->data;
}
int countNodes(DL C)
{
    int count = 0;
    while (C != NULL)
    {
        count++;
        C = C->right;
    }
    return count;
}
int numberOfOdds(DL C)
{
    int count = 0;
    while (C != NULL)
    {
        if (C->data % 2 != 0)
            count++;
        C = C->right;
    }
    return count;
}
int numberOfEvens(DL C)
{
    int count = 0;
    while (C != NULL)
    {
        if (C->data % 2 == 0)
            count++;
        C = C->right;
    }
    return count;
}
void swapDL(DL l,DL h)
{
    int temp=l->data;
    l->data=h->data;
    h->data=temp;
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
void deleteK(DL C, int k)
{
    DL SP;
    SP = C;

    while (C != NULL)
    {
        if (C->data == k)
        {
            C->left->right = C->right;
            C->right->left = C->left;
        }
    }
}
int palindrome(DL C)
{
    DL END = C;

    while (END->right != NULL)
    {
        END = END->right;
    }
    while (C < END)
    {
        if (C->data != END->data)
            return 0;

        C = C->right;
        END = END->left;
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

    DL L;
    L = createList();

    cout << endl;
    displayAll(L);

    int n;
    int k;

    // cin >> n;
    // addInFront(L, n);

    // cout << endl;
    // displayAll(L);

    // cin >> n;
    // addInEnd(L, n);

    // cout << endl;
    // displayAll(L);

    // cin >> k;
    // cin >> n;
    // insertBefore(L, n, k);

    // cout << endl;
    // displayAll(L);

    // cin >> k;
    // cin >> n;
    // insertAfter(L, n, k);

    // cout << endl;
    // displayAll(L);

    removeFirst(L);

    cout << endl;
    displayAll(L);

    // deleteEnd(L);

    // cout<<endl;
    // displayAll(L);

    // cin>>n;
    // deleteK(L,n);

    // cout<<endl;
    // displayAll(L);

    // DL S;
    // S=insSort(L);

    // cout<<endl;
    // displayAll(L);
}