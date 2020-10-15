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
void AscDsc(BST T)
{
    int depth = height(T);
    int a[100];
    int i;

    for (i = 0; i < 100; i++)
    {
        a[i] = -2;
    }
    for (i = 1; i < depth + 1; i++)
    {
        levelOrder(T, i, a);
        a[array_i++] = -1;
    }
    int max;
    int min;

    int arraycount = 0;

    max = T->data;
    min = T->data;

    vector<int> temp;
    vector<int> res;

    for (i = 0; i < 100; i++)
    {
        if (a[i] != -2)
        {
            if (a[i] != -1)
            {
                if (a[i] < min)
                    min = a[i];

                if (a[i] > max)
                    max = a[i];

                temp.push_back(a[i]);
            }
            else
            {

                if (temp.size() > 1)
                {
                    int numCount = 0;
                    for (int j = 0; j < temp.size() - 1; j++)
                    {
                        if (temp[i] < temp[i + 1])
                            numCount++;
                    }
                    if (temp.size() - 1 == numCount)
                        res.push_back(arraycount);
                    else if (numCount == 0)
                        res.push_back(arraycount);
                    else
                        res.push_back(arraycount);
                }
                arraycount++;
            }
        }
    }
    cout << max << endl
         << min << endl;
    for (i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
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
    AscDsc(T);
}
