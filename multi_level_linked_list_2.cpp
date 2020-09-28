
#include <bits/stdc++.h>
using namespace std;

typedef struct mlnode
{
    int data;
    struct mlnode *mext;
    struct mlnode *Lnode;
} * ML;
struct mlnode *Mcreate();
void mlInsert(ML START)
{
    ML END, CUR;
    END = START;
    ML L;

    int n = 0;
    while (n > -1)
    {
        cin >> n;
        if (n == -1)
        {
            return;
        }
        else if (n == 1)
        {
            L = Mcreate();
            END->Lnode = L;
        }
        else if (n == 0)
        {
            END->Lnode = NULL;
        }
        else
        {
            CUR = new (struct mlnode);
            CUR->data = n;
            CUR->mext = NULL;
            END->mext = CUR;
            END = CUR;
        }
    }
}
struct mlnode *Mcreate()
{
    int n;
    ML M1;

    cin >> n;
    M1 = new (struct mlnode);
    M1->data = n;
    M1->mext = NULL;
    M1->Lnode = NULL;
    mlInsert(M1);

    return M1;
}
void displayMList(ML S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayMList(S->mext);
    }
}
void displayLevel(ML S)
{
    ML END = S;
    while (END->mext != NULL)
    {
        END = END->mext;
    }
    while (S != NULL)
    {
        if (S->Lnode != NULL)
        {
            END->mext = S->Lnode;
            S->Lnode = NULL;
            while (END->mext != NULL)
            {
                END = END->mext;
            }
        }
        S = S->mext;
    }
}
void displayDepth(ML S, int A[])
{
    static int i = 0;
    if (S != NULL)
    {

        A[i++] = S->data;
        if (S->Lnode != NULL)
            displayDepth(S->Lnode, A);

        displayDepth(S->mext, A);
    }
}
int main()
{
    ML C;
    C = Mcreate();
    int arr[200];
    for (int i = 0; i < 200; i++)
        arr[i] = -1;
    displayDepth(C, arr);

    displayLevel(C);
    displayMList(C);

    for (int i = 0; i < 200; i++)
        if (arr[i] != -1)
            cout << arr[i] << " ";
}