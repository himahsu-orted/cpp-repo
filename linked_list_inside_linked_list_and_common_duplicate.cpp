#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int iVal;
    char cVal;
    struct node *next;
} * LL;
typedef struct Bnode
{
    struct Bnode *Bnext;
    struct node *element;
} * BL;

typedef struct valNode
{
    char num;
    int digit;
    int count;
    struct valNode *valNext;
} * VN;
void insert(LL START, int arr[])
{
    LL END, CUR;
    END = START;
    int n;
    char ch;

    cin >> ch;
    cin >> n;

    int k;
    k = ch;
    while (n > -1 && ch != '#')
    {
        CUR = new (struct node);
        CUR->iVal = n;
        CUR->cVal = ch;

        arr[k * 10 + n]++;

        CUR->next = NULL;
        END->next = CUR;
        END = CUR;
        cin >> ch;
        cin >> n;
        k = ch;
    }
}
struct node *createList(int arr[])
{

    int n;
    char ch;
    LL L1;

    cin >> ch;
    cin >> n;

    L1 = new (struct node);
    L1->iVal = n;

    L1->cVal = ch;

    int val = ch;
    ;
    arr[val * 10 + n]++;

    L1->next = NULL;
    insert(L1, arr);

    return L1;
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->cVal << "";
        cout << S->iVal << " ";
        displayAll(S->next);
    }
}

int main()
{

    LL A, B, C;

    int arr[1500];
    int i;

    for (i = 0; i < 1500; i++)
        arr[i] = 0;

    A = createList(arr);
    B = createList(arr);
    C = createList(arr);

    BL LongList = new (struct Bnode);
    LongList->element = A;
    LongList->Bnext = new (struct Bnode);
    LongList->Bnext->element = B;
    LongList->Bnext = new (struct Bnode);
    LongList->Bnext->element = C;
    LongList->Bnext = NULL;

    displayAll(A);
    displayAll(B);
    displayAll(C);

    cout << endl;

    for (i = 0; i < 1500; i++)
    {
        if (arr[i] > 2)
            cout << char(i / 10) << i % 10 << " ";
    }
}