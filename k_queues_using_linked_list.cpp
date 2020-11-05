#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
void enq(LL L, int val, int s)
{
    LL T = L;
    while (L != NULL)
    {
        if (L->data == s)
        {
            break;
        }

        L = L->next;
    }

    while (T != NULL)
    {
        if (T->next == L)
        {
            break;
        }

        T = T->next;
    }

    LL add = new (struct node);
    add->data = val;
    add->next = T->next;
    T->next = add;
}
int deq(LL L, int s)
{
    int t;
    while (L != NULL)
    {
        if (L->data == s || L->next == NULL)
        {
            break;
        }

        L = L->next;
    }
    if (L->next == NULL || L->next->data < 0)
        cout << "Queue Empty";
    else
    {
        t = L->next->data;

        if (L->next->next == NULL)
            L->next = NULL;
        else
            L->next = L->next->next;
    }
    return t;
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

    LL L = new (struct node);
    L->data = -1;
    L->next = NULL;

    int k;
    cin >> k;

    for (int i = 2; i <= k; i++)
    {
        LL PER = L;
        while (PER != NULL)
        {
            if (PER->next == NULL)
                break;

            PER = PER->next;
        }

        LL add = new (struct node);
        add->next = NULL;
        add->data = -i;
        PER->next = add;
    }

    int n, val;

    cin >> n >> val;
    while (n != 0)
    {
        if (n < 0)
            deq(L, n);
        else
            enq(L, val, -1 * (n + 1));
        cin >> n;
        if (n == 0)
            break;
        if (n < 0)
            continue;
        cin >> val;
    }
    while (L != NULL)
    {
        if (L->data > -1)
            cout << L->data << " ";
        else
            cout << endl;
        L = L->next;
    }
}