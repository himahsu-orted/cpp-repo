#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;

} * BST;
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
void display(BST T)
{
    if (T != NULL)
    {
        cout << T->data << " ";

        display(T->lChild);
        display(T->rChild);
    }
}
void postOrder(BST T, vector<int> &arr)
{
    if (T != NULL)
    {
        postOrder(T->lChild, arr);
        postOrder(T->rChild, arr);

        arr.push_back(T->data);
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

    display(T);
    cout << endl;

    BST S = NULL;
    vector<int> arr;
    postOrder(T, arr);

    for (int i = arr.size() - 1; i >= 0; i--)
        createBST(S, arr[i]);

    display(S);
}