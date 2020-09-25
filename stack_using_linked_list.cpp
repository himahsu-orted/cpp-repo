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

void push(LL C, int n)
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
void pop(LL C)
{
    LL END = C;
    int t;
    if (C->next == NULL)
    {
        if (C->data == -1)
        {
            cout << "Stack Empty\n";
            return;
        }
        else
        {
            cout << C->data;
            C->data = -1;
            return;
        }
    }
    while (C != NULL)
    {
        if (C->next == NULL)
        {
            t = C->data;
            break;
        }
        C = C->next;
    }
    while (END != NULL)
    {
        if (END->next == C)
        {
            END->next = NULL;
            break;
        }
        END = END->next;
    }
    cout << t;
}
int main()
{
    int n;
    LL L1;

    cout << "Enter Value to push: ";
    cin >> n;
    L1 = new (struct node);
    L1->data = n;
    L1->next = NULL;

    char ch;
    do
    {
        cout << "1.Push\n2.Pop\n";
        cin >> n;
        if (n == 1)
        {
            cin >> n;
            if (L1->data == -1)
                L1->data = n;
            else
                push(L1, n);
        }
        else
        {
            pop(L1);
        }
        cout << "Do you want to continue? y/n";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
    displayAll(L1);
}