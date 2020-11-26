#include <bits/stdc++.h>

using namespace std;

typedef struct bstnode
{
	int data;
	struct bstnode *lChild;
	struct bstnode *rChild;
} * BST;
void createTree(BST &T, int n)
{
	if (!T)
	{
		T = new (struct bstnode);
		T->data = n;
		T->lChild = NULL;
		T->rChild = NULL;
	}
	else
	{
		if (n > T->data)
			createTree(T->rChild, n);
		else
			createTree(T->lChild, n);
	}
}
void display(BST T)
{
	if (T)
	{
		cout << T->data << " ";
		display(T->lChild);
		display(T->rChild);
	}
}
void levelOrder(BST T, queue<BST> q)
{
	queue<BST> q2;
	if (T != NULL)
	{
		while (!q.empty())
		{
			cout << q.front()->data << " ";

			if (q.front()->lChild != NULL)
				q2.push(q.front()->lChild);

			if (q.front()->rChild != NULL)
				q2.push(q.front()->rChild);

			q.pop();
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
}
int height(BST T)
{
	if (T)
	{
		return (max(height(T->lChild), height(T->rChild)) + 1);
	}
	else
		return 0;
}
BST rightRotation(BST T)
{
	if (T->lChild)
	{
		BST add = T->lChild;
		T->lChild = add->rChild;
		add->rChild = T;
		return add;
	}
	else
		return NULL;
}
BST leftRotation(BST T)
{
	if (T->rChild)
	{
		BST add = T->rChild;
		T->rChild = add->lChild;
		add->lChild = T;
		return add;
	}
	else
		return NULL;
}
void findPath(BST T, vector<BST> a, stack<BST> &s, int target)
{
	if (T)
	{
		if (T->data == target)
		{
			for (int i = 0; i < a.size(); i++)
				s.push(a[i]);
			return;
		}
		a.push_back(T);
		findPath(T->lChild, a, s, target);
		findPath(T->rChild, a, s, target);
	}
}
void getWay(BST T, vector<int> temp, vector<int> &per, int target, int i)
{
	if (T)
	{
		if (i > -1)
			temp.push_back(i);
		if (T->data == target)
		{
			for (int i = 0; i < temp.size(); i++)
				per.push_back(temp[i]);
		}
		getWay(T->lChild, temp, per, target, 0);
		getWay(T->rChild, temp, per, target, 1);
	}
}
void compare(BST &T1, BST &T2)
{
	stack<BST> s;
	vector<BST> a;
	vector<int> way;
	vector<int> temp;
	queue<BST> q;
	if (T2 && T1)
	{
		if (T1->data != T2->data)
		{
			findPath(T1, a, s, T2->data);
			getWay(T1, temp, way, T2->data, -1);
			for (int i = 0; i < way.size(); i++)
			{
				BST currentNode = s.top();
				s.pop();
				if (way[i] == 1)
				{
					if (!s.empty())
						s.top()->rChild = rightRotation(currentNode);
					else
						T1 = rightRotation(currentNode);
				}
				else
				{
					if (!s.empty())
						s.top()->lChild = leftRotation(currentNode);
					else
						T1 = leftRotation(currentNode);
				}
				if (!currentNode)
				{
					i--;
				}
			}
		}
		compare(T1->lChild, T2->lChild);
		compare(T1->lChild, T2->lChild);
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
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	BST T1 = NULL;
	BST T2 = NULL;

	cin >> n;
	while (n != -1)
	{

		createTree(T1, n);
		cin >> n;
	}
	cin >> n;
	while (n != -1)
	{

		createTree(T2, n);
		cin >> n;
	}

	stack<BST> s;
	vector<BST> a;

	// compare(T1, T2);
	display(T1);
}