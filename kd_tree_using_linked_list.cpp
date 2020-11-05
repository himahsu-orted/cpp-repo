#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} * LL;
typedef struct kdnode
{
    struct kdnode *lChild;
    LL L;
    struct kdnode *rChild;
} * KD;
void insert(KD &(T), int data[], int i, int d)
{
    if (T == NULL)
    {
        KD add = new (struct kdnode);
        add->lChild = NULL;
        add->rChild = NULL;

        LL temp = new (struct node);
        temp->next = NULL;
        temp->data = data[0];

        LL end = temp;
        for (int i = 1; i < d; i++)
        {
            LL newItem = new (struct node);
            newItem->data = data[i];
            newItem->next = NULL;
            end->next = newItem;
            end = newItem;
        }

        add->L = temp;
        T = add;
    }
    else
    {
        LL temp = T->L;
        int j = 0;
        while (temp != NULL)
        {
            if (j == i)
                break;
            j++;
            temp = temp->next;
        }
        int x = temp->data;
        if (data[i] < x)
            insert(T->lChild, data, (i + 1) % d, d);
        else
            insert(T->rChild, data, (i + 1) % d, d);
    }
}
void printfn(KD T)
{
    if (T != NULL)
    {
        printfn(T->lChild);

        while (T->L != NULL)
        {
            cout << T->L->data << " ";
            T->L = T->L->next;
        }
        cout << endl;

        printfn(T->rChild);
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

    KD T = NULL;

    int d;
    cin >> d;
    int data[d], n;
    cin >> n;
    while (n > 0)
    {
        data[0] = n;
        for (int i = 1; i < d; i++)
        {
            cin >> data[i];
        }
        insert(T, data, 0, d);
        cin >> n;
    }

    printfn(T);
    // for(int i=0;i<d;i++)
    // cout<<data[i]<<" ";
}