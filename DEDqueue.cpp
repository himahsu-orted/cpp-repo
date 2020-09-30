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
void enqRear(struct Queue *Q, int val)
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
void enqFront(struct Queue *Q, int val)
{
    if ((Q->rear + 1) % Q->size == Q->front)
        cout << "Queue Full";
    else
    {
        if (Q->front == -1)
        {
            Q->front = Q->size - 1;
        }
        else
        {
            Q->front = (Q->front - 1) % Q->size;
        }
        Q->elements[Q->front] = val;
    }
}
int deqFront(struct Queue *Q)
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
int deqRear(struct Queue *Q)
{
    int t;
    if (Q->front == -1)
        cout << "Queue Empty";
    else
    {
        if (Q->front == Q->rear)
        {
            t = Q->elements[Q->rear];
            Q->front = -1;
            Q->rear = -1;
        }
        else
        {
            t = Q->elements[Q->rear];
            Q->rear = (Q->rear - 1) % Q->size;
        }
    }
    return t;
}
int main()
{
    struct Queue *Q1 = new (struct Queue);
    Q1->size = SIZE - 1;
    Q1->front = -1;
    Q1->rear = -1;

    int n;
    char ch;
    do
    {
        cout << "\n1.Enq from Front\n2.Enq from Rear";
        cout << "\n3.Deq from Front\n4.Deq from Rear";
        cin >> n;
        switch (n)
        {
        case 1:
            cin >> n;
            enqFront(Q1, n);
            break;
        case 2:
            cin >> n;
            enqRear(Q1, n);
            break;
        case 3:
            cout << deqFront(Q1);
            break;
        case 4:
            cout << deqRear(Q1);
            break;
        }
        cout << "Do you want to enter more? y/n ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    while (Q1->front > -1)
    {
        cout << deqFront(Q1) << " ";
    }
}