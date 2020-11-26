#include <bits/stdc++.h>
using namespace std;

#define m 4

typedef struct mnode
{
    int cnt;
    int keys[m - 1];
    struct mnode *mptr[m];
} * MT;

void createTree(MT &T, int n)
{
    if (T == NULL)
    {
        MT add = new (struct mnode);
        add->cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (i < m - 1)
            {
                add->keys[i] = -1;
            }
            add->mptr[i] = NULL;
        }

        add->keys[add->cnt++] = n;

        T = add;
    }
    else
    {
        if (T->cnt < m - 1)
        {
            if (T->keys[T->cnt - 1] < n)
                T->keys[T->cnt++] = n;
            else
            {
                int i;
                for (i = 0; i < m - 1; i++)
                    if (T->keys[i] > n)
                        break;
                for (int j = m - 1; j > i; j--)
                {
                    if (j < m - 1)
                        T->keys[j] = T->keys[j - 1];
                    T->mptr[j] = T->mptr[j - 1];
                }
                T->keys[i] = n;
                T->mptr[i] = NULL;
                T->cnt++;
            }
        }
        else
        {
            int i;
            for (i = 0; i < m - 1; i++)
                if (T->keys[i] > n)
                    break;

            createTree(T->mptr[i], n);
        }
    }
}
void displayLevelOrder(MT T, queue<MT> q)
{

    queue<MT> q2;
    while (!q.empty())
    {
        MT currentNode = q.front();
        for (int i = 0; i < m; i++)
        {
            if (i < currentNode->cnt && currentNode->keys[i] > 0)
                cout << currentNode->keys[i] << " ";

            if (currentNode->mptr[i] != NULL)
                q2.push(currentNode->mptr[i]);
        }
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
void sideView(MT T, queue<MT> q)
{
    vector<int> temp;
    queue<MT> q2;
    while (!q.empty())
    {
        MT currentNode = q.front();
        for (int i = 0; i < m; i++)
        {
            if (i < currentNode->cnt && currentNode->keys[i] > 0)
                temp.push_back(currentNode->keys[i]);

            if (currentNode->mptr[i] != NULL)
                q2.push(currentNode->mptr[i]);
        }
        q.pop();
        if (q.empty())
        {
            while (!q2.empty())
            {
                q.push(q2.front());
                q2.pop();
            }
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        cout << temp[i] << " ";
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

    MT T = NULL;

    int n;
    cin >> n;
    while (n != 0)
    {
        createTree(T, n);
        cin >> n;
    }
    queue<MT> a;
    a.push(T);
    sideView(T, a);
}