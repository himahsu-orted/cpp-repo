#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;

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
static int array_i = 0;
void levelOrder(BST T, int pos, int arr[])
{

    if (T == NULL)
        return;

    if (pos == 1)
    {
        arr[array_i++] = T->data;
    }
    else if (pos > 1)
    {
        levelOrder(T->lChild, pos - 1, arr);
        levelOrder(T->rChild, pos - 1, arr);
    }
}
void squirrel(BST T, int pos, int arr[], char changer)
{

    if (T == NULL)
        return;

    if (pos == 1)
    {
        arr[array_i++] = T->data;
    }
    else if (pos > 1)
    {
        if (changer == 'L')
        {
            squirrel(T->lChild, pos - 1, arr, changer);
            squirrel(T->rChild, pos - 1, arr, changer);
        }
        else
        {
            squirrel(T->rChild, pos - 1, arr, changer);
            squirrel(T->lChild, pos - 1, arr, changer);
        }
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
    cin >> n;
    int i = 0;
    int items;

    while (n > -1)
    {
        createTree(T, n);
        cin >> n;
        i++;
    }
    items = i;
    int depth = height(T);
    int arr[i + 1];

    ///////FIRST OUTPUT////////////////
    for (i = 1; i < depth + 1; i++)
    {
        levelOrder(T, i, arr);
    }
    array_i = 0;
    for (i = 0; i < items; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    ///////SECOND OUTPUT////////////////
    reverse(arr, arr + items);

    for (i = 0; i < items; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    ///////THIRD OUTPUT////////////////
    for (int i = depth; i > 0; i--)
    {
        levelOrder(T, i, arr);
    }
    array_i = 0;
    for (i = 0; i < items; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < 2; j++)
    {
        ///////FOURTH OUTPUT////////////////
        for (i = 1; i < depth + 1; i++)
        {
            char changer = 'L';
            if (i % 2 == 0)
            {
                if (changer == 'L')
                    changer = 'R';
                else
                    changer = 'L';
            }
            squirrel(T, i, arr, changer);
        }
        array_i = 0;
        for (i = 0; i < items; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        ///////FIFTH OUTPUT////////////////

        for (i = 1; i < depth + 1; i++)
        {
            char changer = 'R';
            if (i % 2 == 0)
            {
                if (changer == 'L')
                    changer = 'R';
                else
                    changer = 'L';
            }
            squirrel(T, i, arr, changer);
        }
        array_i = 0;
        for (i = 0; i < items; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        ///////SIXTH OUTPUT////////////////
    }
}
