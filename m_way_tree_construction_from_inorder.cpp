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
    vector<int> a;
    cin >> n;
    while (n != -1)
    {
        a.push_back(n);
        cin >> n;
    }
    int pos = ceil(a.size() / (float)m);
    int currentPos;
    int max_levels = ceil(log(a.size()) / log(3));

    for (int i = 0; i < max_levels; i++)
    {
        currentPos = pos;
        for (int j = 0; j < pow(3, i); j++)
        {
            for (int k = 0; k < m - 1; k++)
            {
                createTree(T, a[currentPos - 1]);
                currentPos += pow(m, max_levels - (i + 1));
            }
            currentPos += pos;
        }
        pos /= m;
    }
    queue<MT> q;
    q.push(T);
    displayLevelOrder(T, q);
}