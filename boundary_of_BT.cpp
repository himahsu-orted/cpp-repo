#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
} * BST;

void createTree(BST &(T))
{
    int num;
    cin >> num;

    if (num == 0)
        return;

    if (T == NULL)
    {
        BST ADD = new (struct node);
        ADD->data = num;
        ADD->lChild = NULL;
        ADD->rChild = NULL;
        T = ADD;
    }

    createTree(T->lChild);
    createTree(T->rChild);
}
int height(BST T)
{

    if (T == NULL)
        return 0;
    else
    {
        int lheight = height(T->lChild);
        int rheight = height(T->rChild);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
static int array_i = 0;
static int array_j = 0;
void levelOrder(BST T, int pos, int arr[][6])
{

    if (T == NULL)
        return;

    if (pos == 1)
    {
        arr[array_j][array_i++] = T->data;
    }
    else if (pos > 1)
    {
        levelOrder(T->lChild, pos - 1, arr);
        levelOrder(T->rChild, pos - 1, arr);
    }
}
void left(BST T)
{
    if (T != NULL)
    {
        if (T->lChild != NULL || T->rChild != NULL)
            cout << T->data << " ";

        left(T->lChild);
    }
}
void right(BST T)
{
    if (T != NULL)
    {
        right(T->rChild);

        if (T->lChild != NULL || T->rChild != NULL)
            cout << T->data << " ";
    }
}
void bottom(BST T)
{
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
            cout << T->data << " ";

        bottom(T->lChild);
        bottom(T->rChild);
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

    BST T = NULL;
    int i, j;
    createTree(T);

    left(T);
    // cout<<endl;
    bottom(T);
    // cout<<endl;
    right(T);
}
