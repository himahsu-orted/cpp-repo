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
void display(MT T)
{
    if (T != NULL)
    {
        for (int i = 0; i < m; i++)
        {
            display(T->mptr[i]);
            if (i < m - 1 && T->keys[i] != -1)
                cout << T->keys[i] << " ";
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
    display(T);
}