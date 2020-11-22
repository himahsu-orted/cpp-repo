#include <bits/stdc++.h>
using namespace std;
typedef struct gtnode
{
    char data;
    struct gtnode *fc;
    struct gtnode *ns;
} * GT;
GT createTree(GT &T)
{
    char ch;
    int n;
    cin >> ch;
    cin >> n;

    GT add = new (struct gtnode);
    add->data = ch;
    add->fc = NULL;
    add->ns = NULL;
    T = add;

    if (n > 0)
    {
        GT temp = createTree(T->fc);

        for (int i = 1; i < n; i++)
        {
            temp = createTree(temp->ns);
        }
    }
    return T;
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

    GT T = NULL;
    createTree(T);

    display(T);
}
