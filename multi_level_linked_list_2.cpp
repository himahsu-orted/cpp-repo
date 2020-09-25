
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

    int n;
    cin >> n;
    if (n == -1)
        return;

    if (n == -2)
    {
        L = Mcreate();
        START->Lnode = L;

        cin >> n;
    }

    while (n > -1)
    {
        CUR = new (struct mlnode);
        CUR->data = n;
        CUR->mext = NULL;

        cin >> n;
        if (n == -2)
        {
            L = Mcreate();
            CUR->Lnode = L;

            cin >> n;
        }
        else
        {
            CUR->Lnode = NULL;
        }
        END->mext = CUR;
        END = CUR;
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
        if (S->Lnode != NULL)
            displayMList(S->Lnode);

        displayMList(S->mext);
    }
}
int main()
{
    ML C;
    C = Mcreate();
    displayMList(C);
}