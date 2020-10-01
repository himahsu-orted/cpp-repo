#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
void insert(LL START, int c)
{
    int i = 1;
    LL END, CUR;
    END = START;
    int n;
    cin >> n;
    while (i < c)
    {
        i++;
        CUR = new (struct node);
        CUR->data = n;
        CUR->next = NULL;
        END->next = CUR;
        END = CUR;
        cin >> n;
    }
}
struct node *createList(int c)
{
    int n;
    LL L1;

    cin >> n;
    L1 = new (struct node);
    L1->data = n;
    L1->next = NULL;
    insert(L1, c);

    return L1;
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->data << " ";
        displayAll(S->next);
    }
}
void circularMaker(LL C)
{
    LL PER = C;
    while (C != NULL)
    {
        if (C->next == NULL)
            break;

        C = C->next;
    }
    C->next = PER;
}
int elementCounter(LL S, int total)
{
    int count = 0;
    for (int i = 0; i < total; i++)
    {

        if (S->data != -1)
            count++;

        S = S->next;
    }

    return count;
}
LL oneRound(LL START, int n)
{
    int count = 0;
    while (START != NULL)
    {

        if (START->data != -1)
            count++;

        if (count == n)
            break;

        START = START->next;
    }
    if (count == n)
    {
        cout << START->data << " ";
        START->data = -1;
    }
    return START->next;
}
void controller(LL S, int n, int total)
{
    LL TEMP = oneRound(S, n);
    TEMP = oneRound(TEMP, n);
    if (elementCounter(S, total) == 1)
        return;
    else
        controller(TEMP, n, total);
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

    LL C;
    int n;
    cin >> n;
    C = createList(n);
    circularMaker(C);

    controller(C, 3, n);
}