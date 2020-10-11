#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
static int array_i = 0;

typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
} * BST;

void createTree(BST &(T), int n)
{
    if (T == NULL)
    {
        BST ADD = new (struct node);
        ADD->data = n;
        ADD->lChild = NULL;
        ADD->rChild = NULL;
        T = ADD;
    }
    else
    {
        if (n > T->data)
            createTree(T->rChild, n);
        else
            createTree(T->lChild, n);
    }
}

int height(BST T)
{

    if (T == NULL)
        return 0;
    else
    {
        int lheight = height(T->lChild);
        int rheight = height(T->rChild);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

#include <bits/stdc++.h>
using namespace std;

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int elements[SIZE];
} * Q;
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

void topToLeaf(BST T, vector<int> arr)
{
    if (T == NULL)
        return;
    else
    {
        arr.push_back(T->data);
        if (T->lChild == NULL && T->rChild == NULL)
        {
            for (int i = 0; i < arr.size(); i++)
                cout << arr[i] << " ";

            cout << endl;
        }
        else
        {
            topToLeaf(T->lChild, arr);
            topToLeaf(T->rChild, arr);
        }
    }
}

void leftMostPath(BST T, BST PER)
{
    if (T != NULL)
    {

        if (T->data <= PER->data)
            cout << T->data << " ";

        leftMostPath(T->lChild, PER);

        if (T->lChild == NULL)
            leftMostPath(T->rChild, PER);
    }
}
void rightMostPath(BST T, BST PER)
{
    if (T != NULL)
    {

        if (T->data >= PER->data)
            cout << T->data << " ";

        rightMostPath(T->rChild, PER);
        if (T->lChild == NULL)
            rightMostPath(T->lChild, PER);
    }
}
void maximumSumPath(BST T, vector<int> arr, Q q)
{
    if (T == NULL)
        return;
    else
    {
        arr.push_back(T->data);
        if (T->lChild == NULL && T->rChild == NULL)
        {
            int temp = 0;
            int str = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                temp += arr[i];
                str = str * 10 + arr[i];
            }
            enq(q, temp);
            enq(q, str);
        }
        else
        {
            maximumSumPath(T->lChild, arr, q);
            maximumSumPath(T->rChild, arr, q);
        }
    }
}
string findMaxSum(Q q)
{
    int maxSum = deq(q);
    int maxStr = deq(q);
    while (q->front > -1)
    {
        int temp;
        temp = deq(q);
        if (temp > maxSum)
        {
            maxSum = temp;
            maxStr = deq(q);
        }
        else
        {
            deq(q);
        }
    }

    string r = "";
    while (maxStr > 0)
    {
        r = r + " " + to_string(maxStr % 10);
        maxStr = maxStr / 10;
    }
    reverse(r.begin(), r.end());
    return r;
}
string findMinSum(Q q)
{
    int minSum = deq(q);
    int minStr = deq(q);
    while (q->front > -1)
    {
        int temp;
        temp = deq(q);
        if (temp < minSum)
        {
            minSum = temp;
            minStr = deq(q);
        }
        else
        {
            deq(q);
        }
    }

    string r = "";
    while (minStr > 0)
    {
        r = r + " " + to_string(minStr % 10);
        minStr = minStr / 10;
    }
    reverse(r.begin(), r.end());
    return r;
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

    BST T = NULL;
    int n;
    vector<int> arr;

    struct Queue *Q1 = new (struct Queue);
    Q1->size = SIZE - 1;
    Q1->front = -1;
    Q1->rear = -1;

    cin >> n;
    while (n > -1)
    {
        createTree(T, n);
        cin >> n;
    }

    topToLeaf(T, arr);

    leftMostPath(T, T);

    cout << endl;
    rightMostPath(T, T);

    cout << endl;
    maximumSumPath(T, arr, Q1);
    cout << findMaxSum(Q1);

    cout << endl;
    maximumSumPath(T, arr, Q1);
    cout << findMinSum(Q1);

    

}
