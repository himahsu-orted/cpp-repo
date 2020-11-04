#include <bits/stdc++.h>
#include <vector>
#include <forward_list>
using namespace std;

typedef struct node
{
    int freq;
    string letter;
    struct node *lChild;
    struct node *rChild;
} * BST;

void createTree(BST &(T))
{
    int n;
    char ch;
    cin >> n;
    cin >> ch;

    if (n == 0)
        return;

    if (T == NULL)
    {
        BST add;
        add = new (struct node);
        add->freq = n;
        add->lChild = NULL;
        add->rChild = NULL;
        T = add;
    }

    createTree(T->lChild);
    createTree(T->rChild);
}
void display(BST T, vector<int> code, int sentValue)
{

    if (T != NULL)
    {
        if (sentValue < 2)
            code.push_back(sentValue);

        if (T->letter.length() < 2)
        {
            cout << T->letter << " " << T->freq << " ";
            for (int i = 0; i < code.size(); i++)
                cout << code[i];
            cout << endl;

            code.clear();
        }
        else
        {
        }

        display(T->lChild, code, 0);

        display(T->rChild, code, 1);
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

    vector<BST> mainArray;

    int n;
    char ch;
    cin >> ch >> n;

    while (ch != '#')
    {
        BST add = new (struct node);
        add->letter = ch;
        add->freq = n;
        add->lChild = NULL;
        add->rChild = NULL;

        mainArray.push_back(add);

        cin >> ch;
        if (ch == '#')
            break;
        cin >> n;
    }

    int pos = 0;
    int arraypos = 0;
    while (mainArray.size() != 1)
    {
        pos++;
        BST add = new (struct node);
        add->letter = 't' + to_string(pos);
        add->freq = 0;

        BST smallest = mainArray.back();

        for (int i = 0; i < mainArray.size(); i++)
            if (mainArray[i]->freq <= smallest->freq)
            {
                smallest = mainArray[i];
                arraypos = i;
            }

        BST right = new (struct node);
        right = mainArray[arraypos];
        add->rChild = right;
        add->freq += mainArray[arraypos]->freq;
        auto it = mainArray.begin() + arraypos;
        mainArray.erase(it);

        smallest = mainArray.front();
        for (int i = 0; i < mainArray.size(); i++)
            if (mainArray[i]->freq <= smallest->freq)
            {
                smallest = mainArray[i];
                arraypos = i;
            }

        BST left = new (struct node);
        left = mainArray[arraypos];
        add->lChild = left;
        add->freq += mainArray[arraypos]->freq;
        it = mainArray.begin() + arraypos;
        mainArray.erase(it);

        mainArray.push_back(add);
    }
    BST T = mainArray.front();

    vector<int> code;
    display(T, code, 3);
}
