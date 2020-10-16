#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
typedef struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
} * BST;

void createTree(BST &(T))
{
    int num;
    cin >> num;

    if (num == 0)
        return;

    if (T == NULL)
    {
        BST ADD = new (struct node);
        ADD->data = num;
        ADD->lChild = NULL;
        ADD->rChild = NULL;
        T = ADD;
    }

    createTree(T->lChild);
    createTree(T->rChild);
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
void left(BST T, vector<int> &arr)
{
    if (T != NULL)
    {
        if (T->lChild != NULL || T->rChild != NULL)
            arr.push_back(T->data);

        left(T->lChild, arr);
    }
}
void right(BST T, vector<int> &arr)
{
    if (T != NULL)
    {
        right(T->rChild, arr);

        if (T->lChild != NULL || T->rChild != NULL)
            arr.push_back(T->data);
    }
}
void bottom(BST T, vector<int> &arr)
{
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
            arr.push_back(T->data);

        bottom(T->lChild, arr);
        bottom(T->rChild, arr);
    }
}
void display(BST T, vector<int> &arr)
{
    if (T != NULL)
    {
        int c = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (T->data == arr[i])
                c++;
        }
        if (c == 0)
            cout << T->data << " ";

        display(T->lChild, arr);
        display(T->rChild, arr);
    }
}
int main()
{

    BST T = NULL;
    int i, j;
    createTree(T);

    vector<int> arr;
    left(T, arr);
    bottom(T, arr);
    right(T, arr);

    cout << endl;
    display(T, arr);
}
