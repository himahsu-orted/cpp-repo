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
void deleteFront(DL(&S))
{
    if (S->right == NULL)
    {
        if (S->data == -1)
            cout << "Queue Empty";
        else
        {
            cout << S->data;
            S->data = -1;
        }
        return;
    }
    cout << S->data;
    S = S->right;
}
void addInFront(DL(&START), int n)
{
    if (START->data == 0 && START->right == NULL)
    {
        START->data = n;
        return;
    }

    DL CUR;

    CUR = new (struct Dnode);
    CUR->data = n;
    CUR->left = NULL;
    START->left = CUR;
    CUR->right = START;
    START = CUR;
}
void deleteEnd(DL C)
{
    if (C->right == NULL)
    {
        if (C->data == -1)
            cout << "Queue Empty";
        else
        {
            cout << C->data;
            C->data = -1;
        }
        return;
    }
    while (C != NULL)
    {
        if (C->right == NULL)
        {
            cout << C->data;
            C->left->right = NULL;
            break;
        }
        C = C->right;
    }
}
void addInEnd(DL L, int n)
{
    if (L->data == 0 && L->right == NULL)
    {
        L->data = n;
        return;
    }
    while (L != NULL)
    {
        if (L->right == NULL)
        {
            DL ADD = new (struct Dnode);
            ADD->data = n;
            L->right = ADD;
            ADD->left = L;
            ADD->right = NULL;

            break;
        }
        L = L->right;
    }
}
int main()
{

    DL L = new (struct Dnode);
    L->left = NULL;
    L->right = NULL;

    int count = 0;
    char ch;
    int n;
    do
    {
        cout << "Enter your choice: 1.Enqueue from Front\n2.Dequeue from Front";
        cout << "\n3.Enqueue from Rear\n4.Dequeue from Rear\n";
        cin >> n;

        if (count > 0 || (n == 1 || n == 3 && count < 1))
        {
            switch (n)
            {
            case 1:
                cin >> n;

                if (L->data == -1)
                    L->data = n;

                else
                    addInFront(L, n);

                count++;

                break;
            case 2:
                count--;
                deleteFront(L);
                break;
            case 3:
                cin >> n;

                if (L->data == -1)
                    L->data = n;

                else
                    addInEnd(L, n);

                count++;
                break;
            case 4:
                count--;
                deleteEnd(L);
                break;
            }
        }
        else
        {
            cout << "\nQueue Empty\n";
        }
        cout << "\nDo you want to continue? y/n ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}