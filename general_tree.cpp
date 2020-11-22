#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode
{

    int data;
    struct gtnode *fc;
    struct gtnode *ns;
} * GT;
void makeTree(GT t)
{
    int n;
    cin >> n;
    if (n != 0)
    {
        GT add = new (struct gtnode);
        add->data = n;
        t->fc = add;
        makeTree(t->fc);
    }
    else
    {
        t->fc = NULL;
    }
    cin >> n;
    if (n != 0)
    {
        GT add = new (struct gtnode);
        add->data = n;
        t->ns = add;
        makeTree(t->ns);
    }
    else
    {
        t->ns = NULL;
    }
}
void display(GT T)
{
    if (T != NULL)
    {
        cout << T->data << " ";
        display(T->fc);
        display(T->ns);
    }
    else
    {
        cout << ". ";
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

    GT t = new (struct gtnode);
    int n;
    cin >> n;
    t->data = n;
    t->fc = NULL;
    t->ns = NULL;

    makeTree(t);
    display(t);
}
