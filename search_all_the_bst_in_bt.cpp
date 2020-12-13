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
void createBST(BST &(T), int num)
{
    if (T == NULL)
    {
        BST add;
        add = new (struct node);
        add->data = num;
        add->lChild = NULL;
        add->rChild = NULL;
        T = add;
    }
    else
    {
        if (num > T->data)
            createBST(T->rChild, num);
        else
            createBST(T->lChild, num);
    }
}
vector<int> invalidNode;
vector<int> currentTree;
void checkBST(BST T, int min, int max)
{

    if (T)
    {
        currentTree.push_back(T->data);
        if (!(T->data >= min && T->data <= max))
            invalidNode.push_back(T->data);

        checkBST(T->lChild, min, T->data - 1);
        checkBST(T->rChild, T->data + 1, max);
    }
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
void traverse(BST T)
{
    if (T)
    {
        invalidNode.clear();
        currentTree.clear();
        checkBST(T, INT_MIN, INT_MAX);
        if (invalidNode.size() == 0)
        {
            for (int i = 0; i < currentTree.size(); i++)
                cout << currentTree[i] << " ";
            cout << endl;
        }

        traverse(T->lChild);
        traverse(T->rChild);
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

    int n;
    cin >> n;

    while (n > -1)
    {
        createBST(T, n);
        cin >> n;
    }

    traverse(T);
}