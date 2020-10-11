#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;

static int array_i = 0;

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
void findMax(BST T, BST &(max))
{
    if (T != NULL)
    {

        if (T->data > max->data)
        {
            max = T;
        }
        
        findMax(T->lChild, max);
        findMax(T->rChild, max);
    }
}
void findMin(BST T, BST &(min))
{
    if (T != NULL)
    {

        
        if (T->data < min->data)
        {
            min = T;
        }
        findMin(T->lChild, min);
        findMin(T->rChild, min);
    }
}
void levelOrder(BST T, int pos, int a[])
{

    if (T == NULL)
        return;

    if (pos == 1)
    {
        a[array_i++] = T->data;
    }
    else if (pos > 1)
    {
        levelOrder(T->lChild, pos - 1, a);
        levelOrder(T->rChild, pos - 1, a);
    }
}
void displayTree(BST T)
{
    if (T != NULL)
    {

        displayTree(T->lChild);
        cout << T->data << " ";
        displayTree(T->rChild);
    }
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

    createTree(T);

    
    BST left=T;
    BST right=T;

    findMax(T->lChild,left);
    findMin(T->rChild,right);

    
    int temp;
    if(left->data>right->data)
    {
        temp=right->data;
        right->data=left->data;
        left->data=temp;
    }

    displayTree(T);

}
