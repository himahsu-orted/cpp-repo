#include <bits/stdc++.h>
using namespace std;

typedef struct qheap
{
    int count = 0;
    int data;
    struct qheap *qptr[4] = {NULL};
} * QH;

void createHeap(QH H)
{
    if (H)
    {
        for (int i = 0; i < H->count; i++)
        {
            createHeap(H->qptr[i]);
            if (H->qptr[i])
                if (H->data > H->qptr[i]->data)
                    swap(H->data, H->qptr[i]->data);
        }
    }
}
void createTree(QH &H, int n, queue<QH> &q)
{
    QH add = new (struct qheap);
    add->data = n;
    if (!H)
    {
        H = add;
        q.push(H);
    }
    else
        q.front()->qptr[q.front()->count++] = add;

    createHeap(H);
    if (q.front()->count > 3)
    {

        for (int i = 0; i < 4; i++)
            q.push(q.front()->qptr[i]);
        q.pop();
    }
}
void levelOrderDisplay(QH H, queue<QH> &q)
{
    queue<QH> q2;
    while (!q.empty())
    {
        cout << q.front()->data << " ";
        for (int i = 0; i < 4; i++)
            if (q.front()->qptr[i])
                q2.push(q.front()->qptr[i]);

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

    int n;
    queue<QH> nodeQueue;
    QH H = NULL;

    cin >> n;
    while (n != -1)
    {
        createTree(H, n, nodeQueue);
        cin >> n;
    }
    nodeQueue = queue<QH>();
    nodeQueue.push(H);
    levelOrderDisplay(H, nodeQueue);
}