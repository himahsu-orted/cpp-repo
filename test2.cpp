#include <bits/stdc++.h>
using namespace std;

#define m 4

typedef struct bnode
{
    int cnt = 0;
    int keys[m - 1] = {0};
    struct bnode *mptr[m] = {NULL};
} * BT;
// This snode stands for service pointer node and basically would help in overflow condition.
typedef struct snode
{
    int data;
    struct bnode *lChild = NULL;
    struct bnode *rChild = NULL;
} * SN;

typedef struct enode
{
    int cnt = 0;
    int keys[m] = {0};
    struct bnode *eptr[m + 1] = {NULL};
} * EN;
void view(BT T)
{
    for (int i = 0; i < m - 1; i++)
    {
        if (T->keys[i] != -1)
            cout << T->keys[i] << " ";
    }
    // cout << endl;
}
void shiftNodesAndAddNewNode(BT &T, SN S)
{
    int i;
    for (i = 0; i < m - 1; i++)
        if (T->keys[i] > S->data || T->keys[i] == 0)
            break;
    for (int j = m - 1; j > i; j--)
    {
        if (j < m - 1)
            T->keys[j] = T->keys[j - 1];
        T->mptr[j] = T->mptr[j - 1];
    }
    T->keys[i] = S->data;
    T->mptr[i] = S->lChild;
    T->mptr[i + 1] = S->rChild;
    T->cnt++;
}
BT splitIntoTwoNodes(BT &currentNode, SN S)
{
    EN holder = new (struct enode);
    BT splitNode = new (struct bnode);
    bool isPut = false;
    for (int i = 0; i < m; i++)
    {
        if (currentNode->keys[i] > S->data && !isPut)
        {
            holder->keys[holder->cnt++] = S->data;
            isPut = true;
        }
        if (i < m)
        {
            holder->eptr[holder->cnt] = currentNode->mptr[i];
            currentNode->mptr[i] = NULL;
            if (i < m - 1)
            {
                holder->keys[holder->cnt++] = currentNode->keys[i];
                currentNode->keys[i] = 0;
                currentNode->cnt--;
            }
        }
    }
    if (!isPut)
    {
        holder->keys[holder->cnt++] = S->data;
        isPut = true;
    }
    int partition = m / 2;
    for (int i = 0; i < m + 1; i++)
    {
        if (i < partition)
        {
            currentNode->mptr[currentNode->cnt] = holder->eptr[i];
            currentNode->keys[currentNode->cnt++] = holder->keys[i];
        }
        else
        {
            splitNode->mptr[splitNode->cnt] = holder->eptr[i];
            if (i < m)
                splitNode->keys[splitNode->cnt++] = holder->keys[i];
        }
    }

    return splitNode;
}
void createBTree(BT &mainParent, BT &T, SN S)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (i < m - 1 && T->keys[i] > S->data)
            break;
        else if (T->keys[i] == 0)
            break;
    }
    if (T->mptr[i] && !S->lChild && !S->rChild)
    {
        cout << "Getting into recursion at PTR: " << i << " for " << S->data << " " << T->mptr[i]->cnt << endl;
        createBTree(T, T->mptr[i], S);
    }

    else
    {
        if (T->cnt < m - 1)
        {
            cout << "The index of :" << i << " for: " << S->data << endl;
            //Here we are checking if we have some space in the array. This is the condition when we are not into overflow.
            cout << "Came to add " << S->data << " by shifting. Current: " << T->keys[0] << endl;
            //Here we are checking if we have some space in the array. This is the condition when we are not into overflow.
            if (T->keys[T->cnt - 1] < S->data)
            {
                T->keys[T->cnt] = S->data;
                T->mptr[T->cnt] = S->lChild;
                T->mptr[T->cnt + 1] = S->rChild;
                T->cnt++;
            }
            else
            {
                shiftNodesAndAddNewNode(T, S);
            }

            cout << "Current Size is " << T->cnt << endl;
            view(T);
            cout << endl;
        }
        else
        {
            //This is the overflow condition and we are performing the opertaion of spliiting

            BT splitNode = splitIntoTwoNodes(T, S);
            SN newParentInfo = new (struct snode);

            if (S->lChild && S->rChild)
            {
                T->mptr[T->cnt] = S->lChild;
                splitNode->mptr[0] = S->rChild;
                S->lChild = T;
                S->rChild = splitNode;
            }

            newParentInfo->data = T->keys[T->cnt - 1];
            newParentInfo->lChild = T;
            newParentInfo->rChild = splitNode;

            T->keys[T->cnt - 1] = 0;
            T->mptr[T->cnt] = NULL;
            T->cnt--;

            cout << "Came to add " << S->data << " by splitting\n";
            view(T);
            cout << "  ";
            view(splitNode);
            cout << endl;
            if (mainParent->cnt > m - 1)
            {
                //This is where we are creating a new parent of the tree itself

                BT newParent = new (struct bnode);
                newParent->keys[newParent->cnt] = newParentInfo->data;
                newParent->mptr[newParent->cnt] = newParentInfo->lChild;
                newParent->mptr[newParent->cnt + 1] = newParentInfo->rChild;
                newParent->cnt++;

                mainParent = newParent;
                cout << "New supposed parent is now " << mainParent->keys[0] << endl;
            }
            else
            {
                //Here we are just sending the new element to be added to the tree
                cout << "Want to add new parent for " << S->data << " as " << newParentInfo->data << endl;
                mainParent->keys[mainParent->cnt] = newParentInfo->data;
                mainParent->mptr[mainParent->cnt] = newParentInfo->lChild;
                mainParent->mptr[mainParent->cnt + 1] = newParentInfo->rChild;
                mainParent->cnt++;
                // cout << "After Backtrack" << endl;
            }
        }
    }
}
void dix(BT T)
{
    if (T)
    {
        for (int i = 0; i < m; i++)
        {
            dix(T->mptr[i]);
            if (i < m - 1 && T->keys[i] != 0)
                cout << T->keys[i] << " ";
        }
    }
}
void display(queue<BT> q1)
{

    queue<BT> q2;
    while (!q1.empty())
    {
        BT currentNode = q1.front();
        for (int i = 0; i < m; i++)
        {
            if (currentNode->mptr[i])
            {
                cout << "s";
                q2.push(currentNode->mptr[i]);
            }
            if (i < m - 1)
                if (currentNode->keys[i] != 0)
                    cout << currentNode->keys[i] << " ";
        }
        q1.pop();
    }
    // if (q1.empty())
    // {
    //     cout << endl;
    //     while (!q2.empty())
    //     {
    //         q1.push(q2.front());
    //         q1.pop();
    //     }
    // }
    // }
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

    BT mainParent = new (struct bnode);
    int n;
    cin >> n;
    mainParent->keys[mainParent->cnt++] = n;
    cin >> n;
    while (n != -1)
    {
        SN S = new (struct snode);
        S->data = n;
        createBTree(mainParent, mainParent, S);
        cout << "New parent is now " << mainParent->keys[0] << " Size: " << mainParent->cnt << endl;
        cout << endl;
        cin >> n;
    }
    queue<BT> q1;
    q1.push(mainParent);
    // display(q1);
    dix(mainParent);
}