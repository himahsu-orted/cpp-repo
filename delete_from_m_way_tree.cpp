#include <bits/stdc++.h>
using namespace std;

#define m 3

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
void deleteAndReplace(MT T, int i)
{
    if (T->mptr[i + 1] != NULL)
    {
        T->keys[i] = T->mptr[i + 1]->keys[0];
        deleteAndReplace(T->mptr[i + 1], 0);
    }
    else
    {
        for (int j = i; j < m - 2; j++)
        {
            T->keys[j] = T->keys[j + 1];
        }
        T->keys[i] = -1;
    }
}
void deleteKey(MT T, int n)
{
    if (T != NULL)
    {
        int i;
        for (i = 0; i < m; i++)
        {
            deleteKey(T->mptr[i], n);
            if (i < m - 1 && T->keys[i] != -1 && T->keys[i] == n)
            {
                deleteAndReplace(T, i);
                break;
            }
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

    MT T = NULL;

    int n;
    cin >> n;
    while (n != -1)
    {
        createTree(T, n);
        cin >> n;
    }
    queue<MT> q;
    q.push(T);
    displayLevelOrder(T, q);

    cin >> n;
    deleteKey(T, n);
    displayLevelOrder(T, q);
}