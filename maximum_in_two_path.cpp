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
void findMax(BST T, int end, int &max, vector<int> arr)
{
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL || T->data == end)
        {
            if (end == T->data)
            {
                max = *max_element(arr.begin(), arr.end());
                return;
            }
        }
        arr.push_back(T->data);

        findMax(T->lChild, end, max, arr);
        findMax(T->rChild, end, max, arr);
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
    vector<int> arr;

    createTree(T);

    int end1, end2, end3, end4, end5, end6;
    int max1 = 0, max2 = 0, max3 = 0, max4 = 0, max5 = 0, max6 = 0;

    cin >> end1 >> end2 >> end3 >> end4 >> end5 >> end6;

    findMax(T, end1, max1, arr);
    arr.clear();

    findMax(T, end2, max2, arr);
    arr.clear();

    findMax(T, end3, max3, arr);
    arr.clear();

    findMax(T, end4, max4, arr);
    arr.clear();

    findMax(T, end5, max5, arr);
    arr.clear();

    findMax(T, end6, max6, arr);
    arr.clear();

    cout << (max1 > max2 ? max1 : max2) << " ";
    cout << (max3 > max4 ? max3 : max4) << " ";
    cout << (max5 > max6 ? max5 : max6);
}
