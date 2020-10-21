#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;

} * BST;
void createTree(BST &(T))
{
    int n;
    cin >> n;

    if (n == 0)
        return;

    if (T == NULL)
    {
        BST ADD;
        ADD = new (struct node);
        ADD->data = n;
        ADD->lChild = NULL;
        ADD->rChild = NULL;
        T = ADD;
    }
    createTree(T->lChild);
    createTree(T->rChild);
}
void display(BST T)
{
    if (T != NULL)
    {
        cout << T->data << " ";

        display(T->lChild);
        display(T->rChild);
    }
}

void makeBST(BST T, int min, int max)
{
    static BST store = NULL;
    if (T != NULL)
    {
        if (!(T->data >= min && T->data <= max))
        {
            if (store == NULL)
                store = T;
            else
            {
                int temp;
                temp = T->data;
                T->data = store->data;
                store->data = temp;
                store = NULL;
            }
            return;
        }
        makeBST(T->lChild, min, T->data - 1);
        makeBST(T->rChild, T->data + 1, max);
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
    createTree(T);

    makeBST(T,INT_MIN,INT_MAX);
    
}