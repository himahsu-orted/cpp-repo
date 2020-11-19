#include <bits/stdc++.h>
using namespace std;

typedef struct inode
{
	int data;
	int low;
	int high;
	struct inode *lChild;
	struct inode *rChild;
} * IN;
void createTree(IN &(t), int n, int l, int h)
{
	if (t == NULL)
	{
		t = new (struct inode);
		t->data = n;
		t->low = l;
		t->high = h;
		t->lChild = NULL;
		t->rChild = NULL;
	}
	else
	{
		if (t->data < n)
			t->data = n;

		if (l < t->low)
		{
			createTree(t->lChild, n, l, h);
		}
		else
		{
			createTree(t->rChild, n, l, h);
		}
	}
}
void display(IN t, int l, int h)
{
	if (t != NULL)
	{
		if (t->low <= l && t->high >= h)
			cout << t->low << " " << t->high << endl;
		display(t->lChild, l, h);
		display(t->rChild, l, h);
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

	IN t = NULL;
	int input, n, l, h;
	cin >> input;
	while (input != 0)
	{

		if (input == 1)
		{
			cin >> l >> h >> n;
			createTree(t, n, l, h);
		}
		else if (input == 2)
		{
			cin >> l >> h;
			display(t, l, h);
		}
		else
			break;
		cin >> input;
	}
}