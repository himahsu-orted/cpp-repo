#include <iostream>
using namespace std;

typedef struct bstnode
{
    int data;
    struct bstnode *lChild;
    struct bstnode *rChild;
} * BST;
void createTree(BST &T, int n)
{
    if (!T)
    {
        T = new (struct bstnode);
        T->data = n;
        T->lChild = NULL;
        T->rChild = NULL;
    }
    else
    {
        if (n > T->data)
            createTree(T->rChild, n);
        else
            createTree(T->lChild, n);
    }
}
void display(BST T)
{
    if (T)
    {
        cout << T->data << " ";
        display(T->lChild);
        display(T->rChild);
    }
}
int height(BST T)
{
    if (T)
    {
        return (max(height(T->lChild), height(T->rChild)) + 1);
    }
    else
        return 0;
}
static BST temp = NULL;
BST leftRotation(BST &T)
{

    BST add = T->rChild;
    T->rChild = add->lChild;
    add->lChild = T;
    return add;
}
void check(BST &T, int n)
{
    if (T)
    {
        if (T->data == n)
        {
            if (abs(height(T->rChild) - height(T->lChild)) > 1)
            {
                T = leftRotation(T);
                return;
            }
        }
        check(T->lChild, n);
        check(T->rChild, n);
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
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    BST T = NULL;

    cin >> n;
    while (n != -2)
    {
        if (n == -1)
        {
            cin >> n;
            check(T, n);
        }
        else if (n == 0)
        {
        }
        else if (n == -2)
            break;
        else
        {
            createTree(T, n);
        }
        cin >> n;
    }
    display(T);
}