#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    struct node *lChild;
    int data;
    struct node *rChild;
} * bst;

void createTree(bst &(T), int n)
{
    if (T == NULL)
    {
        bst ADD = new (struct node);
        ADD->data = n;
        ADD->lChild = NULL;
        ADD->rChild = NULL;
        T = ADD;
    }
    else
    {
        if (n > T->data)
            createTree(T->rChild, n);
        else
            createTree(T->lChild, n);
    }
}
void mergeBST(bst &(T), int n)
{
    if (T == NULL)
    {
        bst add = new (struct node);
        add->data = n;
        add->lChild = NULL;
        add->rChild = NULL;
        T = add;
    }
    else
    {
        if (n > T->data)
            mergeBST(T->rChild, n);
        else
            mergeBST(T->lChild, n);
    }
}
void giveVal(bst &(T), bst temp)
{
    if (temp != NULL)
    {
        mergeBST(T, temp->data);
        giveVal(T, temp->lChild);
        giveVal(T, temp->rChild);
    }
}
void display(bst t)
{
    if (t != NULL)
    {
        display(t->lChild);
        cout << t->data << " ";
        display(t->rChild);
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

    int n;
    cin >> n;
    bst T[n];
    for (int i = 0; i < n; i++)
    {
        T[i] = NULL;
        int val;
        cin >> val;
        while (val > -1)
        {
            createTree(T[i], val);
            cin >> val;
        }
    }
    bst temp = T[0];
    for (int i = 1; i < n; i++)
    {
        if (temp->data > T[i]->data)
        {
            giveVal(temp, T[i]);
            cout << "here";
        }
        else
        {
            giveVal(T[i], temp);
            temp = T[i];
        }
    }
    display(temp);
}