#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
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
void sort(struct Queue *Q, int n, int temp)
{
    static int p1 = 0, p2 = 0;
    static int i = 0;
    if (i < n - 1)
    {
        if (p1 == 0 && p2 == 0)
        {
            p1 = deq(Q);
            p2 = deq(Q);
        }
        else
        {
            p1 = temp;
            p2 = deq(Q);
        }

        if (p1 < p2)
        {
            enq(Q, p1);
            if (i + 1 == n - 1)
                enq(Q, p2);
            i++;
            sort(Q, n, p2);
        }
        else
        {
            enq(Q, p2);
            if (i + 1 == n - 1)
                enq(Q, p1);
            i++;
            sort(Q, n, p1);
        }
    }
    else
    {
        p1 = 0;
        p2 = 0;
        i = 0;
    }
}
void sortController(struct Queue *Q, int n)
{
    static int j = 0;
    if (j < n)
    {
        sort(Q, n, 3);
        j++;
        sortController(Q, n);
    }
}
int main()
{
    struct Queue *Q1 = new (struct Queue);
    Q1->size = SIZE - 1;
    Q1->front = -1;
    Q1->rear = -1;

    enq(Q1, 3);
    enq(Q1, 7);
    enq(Q1, 2);
    enq(Q1, 1);
    enq(Q1, 9);

    sortController(Q1, 5);

    while (Q1->front > -1)
    {
        cout << deq(Q1) << " ";
    }
}