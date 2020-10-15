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
static int i = 0;
vector<int> store;
static int maxBent = 1;
bool onePath(BST T, vector<int> arr, bool status)
{

    if (T != NULL)
    {

        arr.push_back(T->data);
        if (T->lChild == NULL && T->rChild == NULL)
        {
            if (i >= maxBent)
            {
                maxBent = i;

                if (i > maxBent)
                    store.clear();
                else
                    store.push_back(-1);

                for (int i = 0; i < arr.size(); i++)
                {
                    store.push_back(arr[i]);
                }
            }
            i = 0;
        }
        if (onePath(T->lChild, arr, true) != status)
            i++;
        onePath(T->rChild, arr, false);
    }
    return !status;
}
void display(BST T)
{
    if (T != NULL)
    {
        cout << T->data << " ";

        display(T->lChild);
        display(T->rChild);
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
    createTree(T);

    vector<int> arr;
    onePath(T, arr, true);

    for (int i = 0; i < store.size(); i++)
    {
        if (store[i] != -1)
            cout << store[i] << " ";
        else if(i!=0)
            cout << endl;
    }
}
