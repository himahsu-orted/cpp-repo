#include <bits/stdc++.h>
using namespace std;
struct leafnode
{
    string endString;
};
typedef struct trienode
{
    bool isHolder = true;
    union
    {
        trienode *tnode[10] = {NULL};
        leafnode *leaf;
    };
} * TN;

TN newEndNode(bool holderStatus, string word)
{
    TN add = new (struct trienode);
    add->isHolder = holderStatus;
    add->tnode[0] = new (struct trienode);
    add->tnode[0]->leaf = new (struct leafnode);
    add->tnode[0]->leaf->endString = word;

    return add;
}
void insert(TN &T, string word, int i = 0)
{
    if (i == word.length())
    {
        T->tnode[3] = newEndNode(false, word);
        return;
    }
    if (!T)
    {
        T = new (struct trienode);
        T->tnode[word[i] - 65] = newEndNode(false, word);
        return;
    }
    if (!T->isHolder)
    {

        TN add = new (struct trienode);
        char stringPrefix = T->tnode[0]->leaf->endString[i];
        add->tnode[stringPrefix - 65] = T;
        T = add;

        T->tnode[word[i] - 65] = newEndNode(false, word);
    }

    char oneLetter = word[i];
    insert(T->tnode[word[i] - 65], word, i + 1);
}
void display(TN T)
{
    if (T)
    {
        for (int i = 0; i < 4; i++)
        {
            if (T->isHolder)
                display(T->tnode[i]);
        }
        if (!T->isHolder)
        {
            cout << T->tnode[0]->leaf->endString << " ";
        }
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

    TN T = NULL;
    string a;

    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        while (1)
        {
            insert(T, a);
            cin >> a;
            if (a[0] == '#')
                break;
        }
        display(T);
        cout << endl;
    }
}