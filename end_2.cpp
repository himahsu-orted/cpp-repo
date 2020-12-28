#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode
{
    char data;
    struct gtnode *fc;
    struct gtnode *ns;
} * GT;
void makeTree(GT t)
{
    char n;
    cin >> n;
    if (n != '.')
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
    if (n != '.')
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
void levelOrder(vector<vector<char>> &arr, queue<GT> q)
{
    queue<GT> q2;
    vector<char> t1;
    while (!q.empty())
    {
        GT temp = q.front();
        while (temp)
        {
            t1.push_back(temp->data);
            if (temp->fc)
                q2.push(temp->fc);
            temp = temp->ns;
        }
        q.pop();
        if (q.empty())
        {
            arr.push_back(t1);
            t1.clear();
            while (!q2.empty())
            {
                q.push(q2.front());
                q2.pop();
            }
        }
    }
}
void spiral(vector<vector<char>> arr)
{
    bool check = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (check)
        {
            for (int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j] << " ";
        }
        else
        {
            for (int j = arr[i].size() - 1; j >= 0; j--)
                cout << arr[i][j] << " ";
        }
        cout << endl;
        check = !check;
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
    char n;
    cin >> n;
    t->data = n;
    t->fc = NULL;
    t->ns = NULL;

    queue<GT> q;
    vector<vector<char>> arr;
    makeTree(t);
    q.push(t);
    levelOrder(arr, q);
    spiral(arr);
}
