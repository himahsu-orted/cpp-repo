#include <bits/stdc++.h>
using namespace std;
#define m 3
typedef struct bnode
{
  int cnt = 0;
  int keys[m - 1] = {0};
  struct bnode *mptr[m] = {NULL};
} * BT;
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
void display(BT T)
{
  if (T)
  {
    for (int i = 0; i < m; i++)
    {
      display(T->mptr[i]);
      if (i < m - 1 && T->keys[i] != 0)
        cout << T->keys[i] << " ";
    }
  }
}
void levelOrder(queue<BT> q)
{
  queue<BT> q2;
  while (!q.empty())
  {
    BT temp = q.front();
    q.pop();
    for (int i = 0; i < m; i++)
    {
      if (i < m - 1 && temp->keys[i] != 0)
        cout << temp->keys[i] << " ";
      if (temp->mptr[i])
        q2.push(temp->mptr[i]);
    }
    if (q.empty())
    {
      cout << endl;
      while (!q2.empty())
      {
        q.push(q2.front());
        q2.pop();
      }
    }
  }
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
      holder->eptr[holder->cnt] = S->lChild;
      holder->eptr[holder->cnt + 1] = S->rChild;
      holder->keys[holder->cnt++] = S->data;
      isPut = true;
    }
    if (!holder->eptr[holder->cnt])
    {
      holder->eptr[holder->cnt] = currentNode->mptr[i];
    }
    currentNode->mptr[i] = NULL;
    if (currentNode->cnt != 0)
    {
      holder->keys[holder->cnt++] = currentNode->keys[i];
      currentNode->keys[i] = 0;
      currentNode->cnt--;
    }
  }
  if (!isPut)
  {
    holder->eptr[holder->cnt] = S->lChild;
    holder->eptr[holder->cnt + 1] = S->rChild;
    holder->keys[holder->cnt++] = S->data;
    isPut = true;
  }
  int partition = (m / 2);
  for (int i = 0; i < m + 1; i++)
  {
    if (i <= partition)
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
void getLevelStack(BT T, stack<BT> &levels, SN S)
{
  levels.push(T);
  int i;
  for (i = 0; i < m; i++)
  {
    if (i < m - 1 && T->keys[i] > S->data)
      break;
    else if (T->keys[i] == 0)
      break;
  }
  if (T->mptr[i])
  {
    getLevelStack(T->mptr[i], levels, S);
  }
}
void controller(BT &T, SN S)
{

  stack<BT> levels;
  getLevelStack(T, levels, S);
  while (!levels.empty())
  {

    BT curr = levels.top();
    levels.pop();

    //Here we are checking if we have some space in the array. This is the condition when we are not into overflow.
    if (curr->cnt < m - 1)
    {
      if (curr->keys[curr->cnt - 1] < S->data)
      {
        curr->keys[curr->cnt] = S->data;
        curr->mptr[curr->cnt] = S->lChild;
        curr->mptr[curr->cnt + 1] = S->rChild;
        curr->cnt++;
      }
      else
      {
        shiftNodesAndAddNewNode(curr, S);
      }
      break;
    }
    // When there is no space in the array and we need to work with some overflow conditions
    else
    {
      BT splitNode = splitIntoTwoNodes(curr, S);

      S->data = curr->keys[curr->cnt - 1];
      S->lChild = curr;
      S->rChild = splitNode;

      curr->keys[curr->cnt - 1] = 0;
      curr->mptr[curr->cnt] = NULL;
      curr->cnt--;
    }
    if (curr == T)
    {
      BT newParent = new (struct bnode);
      newParent->mptr[newParent->cnt] = S->lChild;
      newParent->mptr[newParent->cnt + 1] = S->rChild;
      newParent->keys[newParent->cnt++] = S->data;
      T = newParent;
      break;
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

  BT mainParent = new (struct bnode);
  int n;
  cin >> n;
  mainParent->keys[mainParent->cnt++] = n;
  cin >> n;
  while (n != -1)
  {
    SN S = new (struct snode);
    S->data = n;
    controller(mainParent, S);
    cin >> n;
  }
  display(mainParent);
  cout << endl;
  queue<BT> q;
  q.push(mainParent);
  levelOrder(q);
}