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

BST findDeadEnd(BST T,BST PER)
{
    if(T!=NULL)    
    {
        
        if(T->lChild==NULL && T->rChild==NULL)
        {
            return T;
        }
        bool leftStatus= false;
        if(T->data-(T->lChild,PER)->data==1)
        {
            leftStatus=false;
        }
        else 
        {
            leftStatus=true;
        }
        if(findDeadEnd(T->rChild,PER);
    }

}
void findMaxMin(BST T, int &max,int & min)
{
    if(T!=NULL)
    {

        if(T->data>max)
        {
            max=T->data;
        }
        if(T->data<min)
        {
            min=T->data;
        }
        findMaxMin(T->lChild,max,min);
        findMaxMin(T->rChild,max,min);
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

    cin >> n;
    while (n > -1)
    {
        createTree(T, n);
        cin >> n;
    }


    int max=T->data;
    int min=T->data;
    
    //findDeadEnd(T,T);
    findMaxMin(T,max,min);

    cout<<min<<" "<<max;


}
