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
    char ch;
    cin >> ch;
    while (ch != '#')
    {
        CUR = new (struct Dnode);
        CUR->data = (int)ch - 48;
        CUR->right = NULL;
        CUR->left = END;
        END->right = CUR;
        END = CUR;
        cin >> ch;
    }
}
struct Dnode *createList()
{
    DL L1;

    L1 = new (struct Dnode);
    L1->data = 0;
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
void sumCal(DL A, DL B)
{
    DL C = new (struct Dnode);
    C->data = -1;
    C->left = NULL;
    C->right = NULL;

    DL CUR, END;
    END = C;

    int temp = 0;
    while (A != NULL)
    {
        if (B != NULL)
        {
            CUR = new (struct Dnode);
            if (A->data + B->data + temp > 9)
            {
                CUR->data = (A->data + B->data + temp) % 10;
                temp = (A->data + B->data + temp) / 10;
            }
            else
            {
                CUR->data = A->data + B->data + temp;
                temp = 0;
            }
            CUR->right = NULL;
            CUR->left = END;
            END->right = CUR;
            END = CUR;

            A = A->left;
            B = B->left;
        }
        else
        {
            CUR = new (struct Dnode);
            CUR->data = A->data + temp;
            temp = 0;
            CUR->right = NULL;
            CUR->left = END;
            END->right = CUR;
            END = CUR;

            A = A->left;
        }
        if (A->left == NULL)
            break;
    }
    while (END != NULL)
    {
        if (END->data != -1)
            cout << END->data;

        END = END->left;
    }
}
void calculateSum(DL A, DL B)
{
    int Alen = 0, Blen = 0;

    while (A->right != NULL)
    {
        A = A->right;
        Alen++;
    }

    while (B->right != NULL)
    {
        B = B->right;
        Blen++;
    }

    if (Alen > Blen)
    {
        sumCal(A, B);
    }
    else
    {
        sumCal(B, A);
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

    DL A, B;
    A = createList();
    B = createList();

    calculateSum(A, B);
}