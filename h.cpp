#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode
{
  char data;
  struct gtnode *fc;
  struct gtnode *ns;
} * GT;
typedef struct node
{
  char data;
  struct node *lChild;
  struct node *rChild;
} * BST;
void makeTree(GT t, vector<char> arr)
{
  static int j = 1;

  if (j < arr.size())
    return;
  char n;
  n = arr[j++];
  if (n != '.')
  {
    GT add = new (struct gtnode);
    add->data = n;
    t->fc = add;
    makeTree(t->fc, arr);
  }
  else
  {
    t->fc = NULL;
  }
  if (j < arr.size())
    return;
  n = arr[j++];
  if (n != '.')
  {
    GT add = new (struct gtnode);
    add->data = n;
    t->ns = add;
    makeTree(t->ns, arr);
  }
  else
  {
    t->ns = NULL;
  }
}
void serialize(GT T, vector<char> &arr)
{
  if (T)
  {
    cout << T->data;
    serialize(T->fc, arr);
    serialize(T->ns, arr);
  }
  // else
  //   arr.push_back('.');
}
void serializeBST(BST T, vector<char> arr)
{
  if (T)
  {
    arr.push_back(T->data);
    serializeBST(T->lChild, arr);
    serializeBST(T->rChild, arr);
  }
  else
    arr.push_back('.');
}
void createBinaryTree(BST &T, vector<char> arr)
{
  static int i = 0;
  char n = arr[i++];
  if (n == '.')
    return;
  if (!T)
  {
    BST ADD = new (struct node);
    ADD->data = n;
    ADD->lChild = NULL;
    ADD->rChild = NULL;
    T = ADD;
  }
  createBinaryTree(T->lChild, arr);
  createBinaryTree(T->rChild, arr);
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

  vector<char> arr;
  char ch;
  cin >> ch;
  while (ch != '#')
  {
    arr.push_back(ch);
    cin >> ch;
  }
  GT t = new (struct gtnode);
  char n;
  n = arr[0];
  t->data = n;
  t->fc = NULL;
  t->ns = NULL;
  makeTree(t, arr);
  // arr.clear();
  cout << t->fc->fc->data;
  // serialize(t, arr);
  // createBinaryTree(T, arr);
  // for (int i = 0; i < arr.size(); i++)
  //   cout << arr[i] << " ";
  // cout << endl;
  // display(T);
}
