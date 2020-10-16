#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;

typedef struct node
{
    char data;
    struct node *lChild;
    struct node *rChild;
} * BST;
void createTree(BST &(T))
{
    queue<char> list;
    queue<BST> q;
    char ch;
    cin >> ch;
    while (ch != '$')
    {
        list.push(ch);
        cin >> ch;
    }

    BST center = new (struct node);
    center->data = list.front();
    center->lChild = NULL;
    center->rChild = NULL;
    list.pop();
    q.push(center);

    while (!list.empty())
    {
        BST left, right;

        if (list.front() != '#')
        {
            left = new (struct node);
            left->data = list.front();
            q.front()->lChild = left;
            q.push(left);
        }
        list.pop();

        if (list.front() != '#')
        {
            right = new (struct node);
            right->data = list.front();
            q.front()->rChild = right;
            q.push(right);
        }
        list.pop();

        q.pop();
    }
    T = center;
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
void levelOrder(BST T, queue<BST> q)
{
    queue<BST> q2;
    if (T != NULL)
    {
        while (!q.empty())
        {
            cout << q.front()->data << " ";

            if (q.front()->lChild != NULL)
                q2.push(q.front()->lChild);

            if (q.front()->rChild != NULL)
                q2.push(q.front()->rChild);

            q.pop();
            if (q.empty())
            {
                cout << endl;
                while (!q2.empty())
                {
                    q.push(q2.front());
                    q2.pop();
                }
            }
        }
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

    // display(T);

    queue<BST> q;
    q.push(T);
    levelOrder(T, q);
}
