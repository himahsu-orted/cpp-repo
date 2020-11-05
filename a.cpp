#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	struct node *lChild;
	int data;
	struct node *rChild;
} * bst;

void createTree(bst &(T), int n)
{
	if (T == NULL)
	{
		bst ADD = new (struct node);
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
int sum;
bool conditionChecker(int i, int j, int k)
{
	if (i < j && j < k)
	{
		if (i + j + k == sum)
			return true;
	}
}
void lastFinder(bst total, int leftDigit, int rightDigit)
{
	if (total != NULL)
	{

		if (conditionChecker(leftDigit, total->data, rightDigit))
			cout << leftDigit << " " << total->data << " " << rightDigit<<endl;

		lastFinder(total->lChild, leftDigit, rightDigit);
		lastFinder(total->rChild, leftDigit, rightDigit);
	}
}
void rightGiver(bst total, bst rightPart, int leftDigit)
{
	if (rightPart != NULL)
	{
		rightGiver(total, rightPart->rChild, leftDigit);

		lastFinder(total, leftDigit, rightPart->data);

		rightGiver(total, rightPart->lChild, leftDigit);
	}
}
void leftGiver(bst total, bst leftPart, bst rightPart)
{
	if (leftPart != NULL)
	{
		leftGiver(total, leftPart->lChild, rightPart);

		rightGiver(total, rightPart, leftPart->data);

		leftGiver(total, leftPart->rChild, rightPart);
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

	int n;
	bst t = NULL;
	cin >> n;
	while (n > -1)
	{
		createTree(t, n);
		cin >> n;
	}
	cin >> sum;
	leftGiver(t, t->lChild, t->rChild);
}