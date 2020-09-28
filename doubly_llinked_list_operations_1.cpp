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
struct Dnode *insSort(DL C)
{
    DL R = new (struct Dnode);
    DL END, CUR, TEMP;
    END = R;
    CUR = R;

    R->data = C->data;
    R->right = NULL;

    C = C->right;
    while (C != NULL)
    {
        if (C->data >= END->data)
        {
            CUR = new (struct Dnode);
            CUR->data = C->data;
            END->right = CUR;
            END = CUR;
        }
        else
        {
            TEMP = R;
            if (C->data < R->data)
            {
                addInFront(R, C->data);
            }
            else
            {
                while (TEMP != NULL)
                {
                    if (TEMP->data > C->data)
                    {
                        insertBefore(R, TEMP->data, C->data);
                        break;
                    }
                    TEMP = TEMP->right;
                }
            }
        }
        C = C->right;
    }
    return R;
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
}