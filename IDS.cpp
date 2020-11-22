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
int depth = 0;
void getDepth(GT T, int height)
{
    if (T != NULL)
    {
        if (height > depth)
            depth = height;
        getDepth(T->fc, height + 1);
        getDepth(T->ns, height);
    }
}
static bool status = false;
bool DFS(GT T, int find, int depth, int currentHeight)
{
    if (status == true)
        return status;

    if (currentHeight > depth)
        return status;
    else
    {
        if (T != NULL)
        {
            if (find == T->data)
            {
                status = true;
                return status;
            }
            else
            {
                DFS(T->fc, find, depth, currentHeight + 1);
                DFS(T->ns, find, depth, currentHeight);
            }
        }
    }
    return status;
}
bool BFS(GT T, int find)
{
    for (int i = 1; i < depth + 1; i++)
        if (DFS(T, find, i, 1))
        {
            return true;
        }

    return false;
}
bool IDS(GT T, int find)
{
    status = false;
    return BFS(T, find);
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
    getDepth(t, 1);

    int input;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        cout << IDS(t, input);
        cout << endl;
    }
}
