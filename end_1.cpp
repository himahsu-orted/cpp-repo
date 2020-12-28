#include <bits/stdc++.h>
using namespace std;

typedef struct bnode
{
    struct bnode *lChild;
    int data;
    struct bnode *rChild;
} * BST;
typedef struct node
{
    BST tdata;
    struct node *next;
} * LL;
void createTree(BST &(T), int n)
{
    if (T == NULL)
    {
        BST ADD = new (struct bnode);
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
void insertInLinkedList(LL L, BST T)
{
    while (L)
    {
        if (L->next == NULL)
        {
            LL add = new (struct node);
            add->next = NULL;
            add->tdata = T;
            L->next = add;
            break;
        }
        L = L->next;
    }
}

static vector<int> arr1;
static vector<int> arr2;

void traverse(BST T)
{
    if (T)
    {
        arr1.push_back(T->data);
        traverse(T->lChild);
        traverse(T->rChild);
    }
}
void goThrough(BST T)
{
    if (T)
    {
        arr2.push_back(T->data);
        goThrough(T->lChild);
        goThrough(T->rChild);
    }
}
bool checkSubArray(vector<int> a2, vector<int> a1)
{
    int i = 0, j = 0;
    int n = a1.size();
    int m = a2.size();
    while (i < n && j < m)
    {
        if (a1[i] == a2[j])
        {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}
void controller(BST T1, BST T2, BST T3, BST T4, LL L)
{
    if (T1)
    {
        arr1.clear();
        traverse(T1);
        int count = 0;

        goThrough(T2);
        if (checkSubArray(arr1, arr2))
            count++;
        arr2.clear();

        goThrough(T3);
        if (checkSubArray(arr1, arr2))
            count++;
        arr2.clear();

        goThrough(T4);
        if (checkSubArray(arr1, arr2))
            count++;
        arr2.clear();

        if (count == 3)
        {
            insertInLinkedList(L, T1);
        }

        controller(T1->lChild, T2, T3, T4, L);
        controller(T1->rChild, T2, T3, T4, L);
    }
}
void display(BST T)
{
    if (T)
    {
        cout << T->data;
        display(T->lChild);
        display(T->rChild);
    }
}
void displayLL(LL L)
{
    while (L)
    {
        display(L->tdata);
        cout << endl;
        L = L->next;
    }
}
int main()
{

    //all input
    BST T1, T2, T3, T4;
    T1 = new (struct bnode);
    T2 = new (struct bnode);
    T3 = new (struct bnode);
    T4 = new (struct bnode);
    LL L = new (struct node);
    L->tdata = T1;
    L->next = NULL;

    int n;

    // INPUT FOR T1
    cin >> n;
    while (n != -1)
    {
        createTree(T1, n);
        cin >> n;
    }

    //INPUT FOR T2
    cin >> n;
    while (n != -1)
    {
        createTree(T2, n);
        cin >> n;
    }

    // INPUT FOR T3
    cin >> n;
    while (n != -1)
    {
        createTree(T3, n);
        cin >> n;
    }

    // INPUT FOR T4
    cin >> n;
    while (n != -1)
    {
        createTree(T4, n);
        cin >> n;
    }
    /////////////////////////////////////////////////
    controller(T1, T2, T3, T4, L);
    arr1.clear();
    controller(T2, T1, T3, T4, L);
    arr1.clear();
    controller(T3, T2, T1, T4, L);
    arr1.clear();
    controller(T4, T2, T3, T1, L);
    L = L->next;
    displayLL(L);
}