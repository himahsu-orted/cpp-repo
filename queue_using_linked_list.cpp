#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
void insert(LL START)
{
    LL END, CUR;
    END = START;
    int n;
    cin >> n;
    while (n > -1)
    {
        CUR = new (struct node);
        CUR->data = n;
        CUR->next = NULL;
        END->next = CUR;
        END = CUR;
        cin >> n;
    }
}
void displayAll(LL S)
{
    if (S != NULL)
    {
        if (S->data != 0)
            cout << S->data << " ";
        displayAll(S->next);
    }
}

void enq(LL C, int n)
{
    LL ADD = new (struct node);
    ADD->next = NULL;
    ADD->data = n;

    while (C != NULL)
    {
        if (C->next == NULL)
        {
            C->next = ADD;
            break;
        }
        C = C->next;
    }
}
void removeFirst(LL(&S))
{
    S = S->next;
}
void deq(LL C)
{
    LL END = C;
    int t;
    if (C->next == NULL)
    {
        if (C->data == -1)
        {
            cout << "Queue Empty\n";
            return;
        }
        else
        {
            cout << C->data;
            C->data = -1;
            return;
        }
    }
    cout << C->data;
}
int main()
{
    int n;
    LL L1;

    cout << "Enter Value to enqueue: ";
    cin >> n;
    L1 = new (struct node);
    L1->data = n;
    L1->next = NULL;

    char ch;
    do
    {
        cout << "1.Enqueue\n2.Dequeue\n";
        cin >> n;
        if (n == 1)
        {
            cin >> n;
            if (L1->data == -1)
                L1->data = n;
            else
                enq(L1, n);
        }
        else
        {
            deq(L1);
            if (L1->next != NULL)
                removeFirst(L1);
        }
        cout << "Do you want to continue? y/n";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}