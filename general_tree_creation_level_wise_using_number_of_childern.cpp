#include <bits/stdc++.h>
using namespace std;
typedef struct gtnode
{
    char data;
    int children;
    struct gtnode *fc;
    struct gtnode *ns;
} * GT;

GT makeOneChild()
{
    int n;
    char ch;

    cin >> ch >> n;
    GT add = new (struct gtnode);
    add->children = n;
    add->data = ch;

    add->fc = NULL;
    add->ns = NULL;

    return add;
}
void createTree(GT &T, queue<GT> &a)
{
    while (!a.empty())
    {
        int children = a.front()->children;

        GT firstChild = makeOneChild();
        if (firstChild->children != 0)
            a.push(firstChild);

        GT sibling, temp;

        for (int i = 1; i < children; i++)
        {
            temp = firstChild;

            sibling = makeOneChild();
            if (sibling->children != 0)
                a.push(sibling);

            while (temp != NULL)
            {
                if (temp->ns == NULL)
                    break;
                temp = temp->ns;
            }
            temp->ns = sibling;
        }
        a.front()->fc = firstChild;

        a.pop();
    }
}
void display(GT T)
{
    if (T != NULL)
    {
        cout << T->data;

        display(T->fc);
        display(T->ns);
    }
    else
        cout << ".";
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

    GT T = new (struct gtnode);

    int n;
    char ch;
    cin >> ch >> n;
    T->data = ch;
    T->children = n;
    T->fc = NULL;
    T->ns = NULL;

    queue<GT> a;
    a.push(T);
    createTree(T, a);
    display(T);
}
