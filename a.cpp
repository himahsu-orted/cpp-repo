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
    vector<int> temp;
    int j = 0;

    int max=0;
    int min=0;
    int asc=0;
    int dsc=0;
    int uno=0;

    for (i = 0; i < 100; i++)
    {
        if (a[i] != -2)
        {
            if(a[i]!=-1)
            temp.push_back(a[i]);
            else 
            {
                int c=0;
                for(int k=0;k<temp.size()-1;k++)
                {
                    if(min<temp[k])
                    min=temp[k];

                    if(max>temp[k])
                    max=temp[k];

                    if(temp[k]<temp[k+1])
                    c++;
                }
                if(c==temp.size()-1)
                asc=++j;
                if(c==0)
                dsc=++j;
                else 
                uno=++j;

                temp.clear();
            }
        }
    }
    cout<<max<<endl<<min<<endl<<asc<<endl<<dsc<<endl<<uno;
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
