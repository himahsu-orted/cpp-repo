#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *lChild;
	struct node *rChild;

} * BST;
void createTree(BST &(T))
{
	int n;
	cin >> n;

	if (n == 0)
		return;

	if (T == NULL)
	{
		BST ADD;
		ADD = new (struct node);
		ADD->data = n;
		ADD->lChild = NULL;
		ADD->rChild = NULL;
		T = ADD;
	}
	createTree(T->lChild);
	createTree(T->rChild);
}
void createBST(BST &(T), int num)
{
	if (T == NULL)
	{
		BST add;
		add = new (struct node);
		add->data = num;
		add->lChild = NULL;
		add->rChild = NULL;
		T = add;
	}
	else
	{
		if (num > T->data)
			createBST(T->rChild, num);
		else
			createBST(T->lChild, num);
	}
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

vector<int> invalidNode;
vector<int> deadEnd;
void findDeadEnd(BST T, int min, int max)
{

	if (T != NULL)
	{
		if (!(T->data >= min && T->data <= max))
		{
			cout << min << " " << max << endl;

			invalidNode.push_back(T->data);
		}
		if (min == max)
			deadEnd.push_back(T->data);

		findDeadEnd(T->lChild, min, T->data - 1);

		findDeadEnd(T->rChild, T->data + 1, max);
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
	cin >> n;

	while (n > -1)
	{
		createBST(T, n);
		cin >> n;
	}

	T->lChild->data = 7;
	T->rChild->data = 2;

	findDeadEnd(T, INT_MIN, INT_MAX);
	if (invalidNode.size() > 0)
	{
		cout << "The given BT is not a BST and it violates the tree at:\n";
		for (int i = 0; i < invalidNode.size(); i++)
		{
			cout << invalidNode[i] << " ";
		}
	}
	else
		cout << "The given BT is a BST\n";

	if (deadEnd.size() > 0)
	{
		cout << "The dead ends are: \n";
		for (int i = 0; i < deadEnd.size(); i++)
		{
			cout << deadEnd[i] << " ";
		}
	}
	else
		cout << "The tree has no dead ends.\n";
}