#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
struct Stack
{
    int size;
    int top;
    int elements[SIZE];
};
void push(struct Stack *S, int val)
{
    if (S->top >= SIZE)
        cout << "Stack Full";
    else
    {
        S->top = S->top + 1;
        S->elements[S->top] = val;
    }
}
int pop(struct Stack *S)
{
    int t;
    if (S->top < 0)
        cout << "Stack Empty";
    else
        t = S->elements[S->top--];
    return (t);
}
int peek(struct Stack *S)
{
    int t;
    if (S->top < 0)
        cout << "Stack Empty";
    else
        t = S->elements[S->top];
    return (t);
}

void holdInStack(struct Stack *S, int val)
{
    if (S->top < 0)
    {
        push(S, val);
    }
    else
    {
        int temp = pop(S);
        holdInStack(S, val);
        push(S, temp);
    }
}
void stackRev(struct Stack *S)
{

    if (S->top > -1)
    {
        int val = pop(S);
        stackRev(S);
        holdInStack(S, val);
    }
}
typedef struct MLnode
{
    int data;
    int countOfLink;
    struct MLnode *next[10];
} * ML;
struct MLnode *createFirst();
void createRest(ML START)
{
    ML CUR, END;
    END = START;

    int n, count = 0;
    cin >> n;

    if (n == 0)
    {
        END->next[0] = NULL;
        return;
    }
    else
    {
        END->countOfLink = n;
        while (count < n)
        {
            END->next[count] = createFirst();
            count++;
        }
    }
}
struct MLnode *createFirst()
{
    int n;
    cin >> n;
    ML START = new (struct MLnode);
    START->data = n;
    createRest(START);
    return START;
}
void find(struct Stack *S, ML L, int s, int d)
{
    static int flag = 0;
    push(S, L->data);
    if (L->data == d || L->data == s)
    {
        if (flag == 0)
        {
            push(S, 0);
            push(S, L->data);
        }
        flag++;
        if (flag == 2)
        {
            return;
        }
    }
    if (L->countOfLink == 0)
    {
        while (S->top > -1)
        {
            if (peek(S) == -1)
            {
                pop(S);
                break;
            }
            else
            {
                pop(S);
            }
        }
    }
    else
    {
        int count = 0;
        if (L->countOfLink > 1)
        {
            for (int j = 0; j < L->countOfLink - 1; j++)
                push(S, -1);
        }
        while (count < L->countOfLink)
        {
            if (flag == 2)
            {
                flag = 0;
                break;
            }
            else
            {
                find(S, L->next[count], s, d);
                count++;
            }
        }
    }
}
int main()
{
    ML L;
    struct Stack *S = new (struct Stack);
    S->size = SIZE;
    S->top = -1;

    L = createFirst();
    int s, d;

    cin >> s >> d;
    find(S, L, s, d);
    stackRev(S);

    bool startFlag = false;
    while (S->top > -1)
    {
        int popVal = pop(S);

        if (startFlag == true && popVal > 0)
        {
            cout << popVal << " ";
        }
        if (popVal == 0)
        {
            startFlag = true;
        }
    }

    cout << endl;

    struct Stack *D = new (struct Stack);
    D->size = SIZE;
    D->top = -1;

    cin >> s >> d;
    find(D, L, s, d);
    stackRev(D);

    startFlag = false;
    while (D->top > -1)
    {
        int popVal = pop(D);

        if (startFlag == true && popVal > 0)
        {
            cout << popVal << " ";
        }
        if (popVal == 0)
        {
            startFlag = true;
        }
    }
}