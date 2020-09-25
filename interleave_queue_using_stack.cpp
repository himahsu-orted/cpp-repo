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
struct Queue
{
    int size;
    int front;
    int rear;
    int elements[SIZE];
};
void enq(struct Queue *Q, int val)
{
    if ((Q->rear + 1) % Q->size == Q->front)
        cout << "Queue Full";
    else
    {
        if (Q->front == -1)
        {
            Q->front = 0;
            Q->rear = 0;
        }
        else
        {
            Q->rear = (Q->rear + 1) % Q->size;
        }
        Q->elements[Q->rear] = val;
    }
}
int deq(struct Queue *Q)
{
    int t;
    if (Q->front == -1)
        cout << "Queue Empty";
    else
    {
        if (Q->front == Q->rear)
        {
            t = Q->elements[Q->front];
            Q->front = -1;
            Q->rear = -1;
        }
        else
        {
            t = Q->elements[Q->front];
            Q->front = (Q->front + 1) % Q->size;
        }
    }
    return t;
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
int main()
{
    struct Queue *Q1 = new (struct Queue);
    Q1->size = SIZE - 1;
    Q1->front = -1;
    Q1->rear = -1;

    struct Stack *S1 = new (struct Stack);
    S1->size = SIZE - 1;
    S1->size = SIZE - 1;
    S1->top = -1;

    int n;
    cin >> n;
    int size = 0;
    while (n > -1)
    {
        enq(Q1, n);
        cin >> n;
        size++;
    };
    n = 0;
    while (n < size / 2)
    {
        push(S1, deq(Q1));
        n++;
    }

    stackRev(S1);
    while (S1->top != -1)
    {
        enq(Q1, pop(S1));
        enq(Q1, deq(Q1));
    }

    while (Q1->front > -1)
        cout << deq(Q1) << " ";
}
