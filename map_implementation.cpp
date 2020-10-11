#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
void addEnd(LL S, int n)
{
    while (S != NULL)
    {
        if (S->next == NULL)
        {
            LL ADD = new (struct node);

            ADD->data = n;
            ADD->next = NULL;
            S->next = ADD;
            break;
        }
        S = S->next;
    }
}
void displayAll(LL S)
{
    if (S != NULL)
    {
        cout << S->data << " ";
        displayAll(S->next);
    }
}
void findNum(LL S, int n)
{
    while (S != NULL)
    {
        if (S->data == n)
        {
            cout << "1";
            break;
        }

        S = S->next;
    }
    cout << "0";
}
int main()
{
    LL C[7];
    char ch;
    int n;

    for (n = 0; n < 7; n++)
    {
        C[n] = new (struct node);
        C[n]->data = -1;
        C[n]->next = NULL;
    }
    cout << "Enter the data: \n";
    do
    {
        cin >> n;
        if (C[n % 7]->data == -1)
        {
            C[n % 7]->data = n;
        }
        else
            addEnd(C[n % 7], n);
        cout << "Do you want to continue? y/n  ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl
         << "Enter the value to find the number: \n";
    do
    {
        cin >> n;
        findNum(C[n % 7], n);
        cout << "Do you want to continue? y/n  ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}