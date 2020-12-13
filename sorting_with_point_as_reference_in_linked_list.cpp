#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next = NULL;
} * LL;

void insert(LL L, int n)
{
    while (L)
    {
        if (L->next == NULL)
            break;
        L = L->next;
    }
    LL add = new (struct node);
    add->data = n;
    L->next = add;
}
bool selfSort(LL L)
{
    bool status = false;
    while (L)
    {
        if (L->data > L->next->data)
        {
            int temp = L->data;
            L->data = L->next->data;
            L->next->data = temp;
            status = true;
        }
        L = L->next;
        if (!L->next)
            break;
    }
    return status;
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
    int n;
    cin >> n;
    L->data = n;
    cin >> n;
    while (n != -1)
    {
        insert(L, n);
        cin >> n;
    }
    while (selfSort(L))
    {
        selfSort(L);
    }
    while (L)
    {
        cout << L->data << " ";
        L = L->next;
    }
}