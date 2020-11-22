#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode
{

    char data;
    bool hasData;
    struct gtnode *fc;
    struct gtnode *ns;
} * GT;

static int maxCount = 0;
static int checkVal = 0;
static int click = 0;

void makeTree(GT t)
{
    char ch;
    cin >> ch;
    if (ch != '.')
    {
        GT add = new (struct gtnode);
        add->data = ch;
        add->hasData = false;
        t->fc = add;
        makeTree(t->fc);
    }
    else
    {
        t->fc = NULL;
    }
    cin >> ch;
    if (ch != '.')
    {
        GT add = new (struct gtnode);
        add->data = ch;
        add->hasData = false;
        t->ns = add;
        makeTree(t->ns);
    }
    else
    {
        t->ns = NULL;
    }
}
void getChild(GT t, vector<GT> &children)
{
    if (t != NULL)
    {
        children.push_back(t);
        getChild(t->ns, children);
    }
}
void getMax(GT t, vector<GT> &nodes)
{
    if (t != NULL)
    {
        nodes.push_back(t);
        getMax(t->fc, nodes);
        getMax(t->ns, nodes);
    }
}
GT getMaxChild(GT t)
{
    vector<GT> child;
    vector<GT> nodes;
    GT maxChild = NULL;
    int maxfreq = 0;
    getChild(t, child);
    for (int i = 0; i < child.size(); i++)
    {
        getMax(child[i]->fc, nodes);
        if (nodes.size() >= maxfreq && child[i]->hasData == false)
        {
            maxfreq = nodes.size();
            maxChild = child[i];
        }
        maxCount = 0;
        nodes.clear();
    }

    return maxChild;
}
void todoFinder(GT t, vector<GT> &todo)
{
    if (t != NULL)
    {
        if (t->hasData == true)
        {
            GT maxChildHolder = getMaxChild(t->fc);
            if (maxChildHolder != NULL)
                todo.push_back(maxChildHolder);
        }
        todoFinder(t->fc, todo);
        todoFinder(t->ns, todo);
    }
}
void controller(GT t)
{

    vector<GT> nodes;

    while (1)
    {
        todoFinder(t, nodes);
        if (nodes.size() != 0)
            click++;
        else
        {
            if (click == 0)
                cout << "The tree has no data.";
            else
                cout << click;
            break;
        }
        for (int i = 0; i < nodes.size(); i++)
        {
            nodes[i]->hasData = true;

            //Remove this comment to see the flow as well
            //cout << nodes[i]->data << " ";
        }
        //cout<endl;
        nodes.clear();
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
    char ch;
    cin >> ch;
    t->data = ch;
    t->fc = NULL;
    t->ns = NULL;
    t->hasData = true;

    makeTree(t);
    controller(t);
}
