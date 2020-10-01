
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} * LL;
void insert(LL START, int c)
{
    int i = 2;
    LL END, CUR;
    END = START;
    int n;
    int a = 0;
    while (i <= c)
    {
        CUR = new (struct node);
        CUR->data = i;
        i++;
        CUR->next = NULL;
        END->next = CUR;
        END = CUR;
    }
}
struct node *createList(int c)
{
    int n;
    LL L1;

    L1 = new (struct node);
    L1->data = 1;
    L1->next = NULL;
    insert(L1, c);

    return L1;
}
void displayAll(LL S)
{
    if (S != NULL)
    {

        cout << S->data << "\n";
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
void elementCounter(LL S, int total)
{

    for (int i = 0; i < total; i++)
    {

        cout << S->data << endl;

        S = S->next;
    }
}
void oneRound(LL START, int total, int k)
{
    int count = 1;
    int i = 0;

    int arr[total / 2];
    int j = 0;

    while (START != NULL)
    {
        if (count % k == 0 && START->data != -1)
        {
            if (i >= total / 2)
                arr[j++] = START->data;
            START->data = -1;
            i++;
        }

        if (i == total)
            break;

        START = START->next;

        if (START->data != -1)
            count++;
    }

    sort(arr, arr + total / 2);
    j = 0;
    for (i = 0; i < total; i++)
    {
        if (i + 1 == arr[j])
        {
            cout << "A ";
            j++;
        }
        else
            cout << "B ";
    }
}
void controller(LL S, int total, int k)
{

    oneRound(S, total, k);
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

    int k;
    cin >> k;

    circularMaker(C);
    controller(C, n, k);
}