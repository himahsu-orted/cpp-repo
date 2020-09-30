#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
union u
{
    int intVal;
    char charVal;
};
struct Queue
{
    int size;
    int front;
    int rear;
    union u *obj[SIZE];
};
void enqRear(struct Queue *Q, int val)
{
    if ((Q->rear + 1) % Q->size == Q->front)
        cout << "Queue Full";
    else
    {
        if (Q->rear == -1)
        {
            Q->rear = 0;
        }
        else
        {
            Q->rear = (Q->rear + 1) % Q->size;
        }
        Q->obj[Q->rear] = new (union u);
        Q->obj[Q->rear]->intVal = val;
    }
}
void enqFront(struct Queue *Q, char val)
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
        Q->obj[Q->front] = new (union u);
        Q->obj[Q->front]->charVal = val;
    }
}
int deqFront(struct Queue *Q)
{
    char t;
    if (Q->front == -1)
        cout << "Queue Empty";
    else
    {
        if (Q->front == Q->size - 1)
        {
            t = Q->obj[Q->front]->intVal;
            Q->front = -1;
        }
        else
        {
            t = Q->obj[Q->front]->intVal;
            Q->front = (Q->front + 1) % Q->size;
        }
    }
    return t;
}
int deqRear(struct Queue *Q)
{
    int t;
    if (Q->rear == -1)
        cout << "Queue Empty";
    else
    {
        if (Q->rear == 0)
        {
            t = Q->obj[Q->rear]->charVal;
            Q->rear = -1;
        }
        else
        {
            t = Q->obj[Q->rear]->charVal;
            Q->rear = (Q->rear - 1) % Q->size;
        }
    }
    return t;
}
void displayNum(struct Queue *Q)
{
    if (Q->rear > -1)
    {
        int temp = deqRear(Q);
        displayNum(Q);
        cout << temp << " ";
    }
}
void displayChar(struct Queue *Q)
{
    if (Q->front > -1)
    {
        char temp = deqFront(Q);
        displayChar(Q);
        cout << temp << " ";
    }
}
int main()
{
    struct Queue *Q1 = new (struct Queue);
    Q1->size = SIZE - 1;
    Q1->front = -1;
    Q1->rear = -1;
    string s = "";

    enqFront(Q1, 'N');
    enqRear(Q1, 17);
    enqFront(Q1, 'I');
    enqFront(Q1, 'T');
    enqRear(Q1, 9);
    enqFront(Q1, 'C');
    enqFront(Q1, 'S');
    enqRear(Q1, 20);
    enqFront(Q1, 'E');
    enqRear(Q1, 21);

    displayChar(Q1);
    displayNum(Q1);
}