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

void createTree(BST & (T))
{
	int n;
	cin >> n;

	if (n == 0)
		return;

	if (T == NULL)
	{
		BST add;
		add = new (struct node);
		add->data = n;
		add->lChild = NULL;
		add->rChild = NULL;
		T = add;
	}

	createTree(T->lChild);
	createTree(T->rChild);
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
vector<int> leftView;
vector<int> rightView;
vector<int> topView;
vector<int> bottomView;


void level(BST T, queue<BST> q)
{
	queue<BST> q2;
	while (!q.empty())
	{

		if (q.front()->lChild)
			q2.push(q.front()->lChild);
		if (q.front()->rChild)
			q2.push(q.front()->rChild);

		rightView.push_back(q.front()->data);
		q.pop();

		if (!q.empty())
		{
			rightView.pop_back();
		}
		if (q.empty())
		{
			while (q2.front() != NULL)
			{
				q.push(q2.front());
				q2.pop();
			}
			if (!q.empty())
				leftView.push_back(q.front()->data);
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
	createTree(T);

	queue<BST> q;
	q.push(T);
	leftView.push_back(T->data);
	level(T, q);

	for (int i = 0; i < leftView.size(); i++)
		cout << leftView[i] <<
		     cout << endl;
	for (int i = 0; i < leftView.size(); i++)
		cout << rightView[i] << " ";
}
