#include <bits/stdc++.h>
using namespace std;

#define m 3

typedef struct bnode
{
	int cnt = 0;
	int keys[m - 1];
	struct bnode *mptr[m] = {NULL};
} * BT;

// This snode stands for service pointer node and basically would help in overflow condition.
typedef struct snode
{
	int data;
	struct bnode *lChild = NULL;
	struct bnode *rChild = NULL;
} * SN;
void validate(BT &T)
{
	for (int i = 0; i < m - 1; i++)
		T->keys[i] = -1;
}
void shiftNodesAndNewNode(BT &T, SN S)
{
	int i;
	for (i = 0; i < m - 1; i++)
		if (T->keys[i] > S->data)
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
void transferToSecondNode(BT &currentNode, BT &splitNode, int partitionPos)
{
	int j = 0;
	for (int i = partitionPos; i < m; i++)
	{
		splitNode->mptr[j] = currentNode->mptr[i];
		currentNode->mptr[i] = NULL;
		currentNode->cnt--;

		if (i < m - 1)
		{
			splitNode->keys[j] = currentNode->keys[i];
			splitNode->cnt++;
			j++;
		}
		currentNode->keys[i] = -1;
	}
}
BT splitIntoTwoNodes(BT &currentNode, SN S)
{
	BT splitNode = new (struct bnode);
	validate(splitNode);
	int partitionPos = (m - 1) / 2;
	int i;
	for (i = 0; i < m - 1; i++)
		if (currentNode->keys[i] > S->data)
			break;
	int InsertionPos = i;
	if (InsertionPos > partitionPos)
	{
		/* Here we are first checking if the insertion postition is in the partion area. If it is so then we first transfer the nodes from current node to split node and then add the new node to the last element of split node */

		transferToSecondNode(currentNode, splitNode, partitionPos);

		splitNode->keys[splitNode->cnt] = S->data;
		splitNode->mptr[splitNode->cnt] = S->lChild;
		splitNode->mptr[splitNode->cnt + 1] = S->rChild;
		splitNode->cnt++;
	}
	else
	{
		// cout << "came here for " << S->data;
		/* Here we are into a condtition that the insertion position is before in the array than partition position and that means that we will need to first transfer and then add the new node in the desired position in current node*/

		transferToSecondNode(currentNode, splitNode, partitionPos);
		shiftNodesAndNewNode(currentNode, S);
	}
	return splitNode;
}
void createBTree(BT &mainParent, BT &T, SN S)
{
	int i;
	for (i = 0; i < m - 1; i++)
		if (T->keys[i] > S->data)
			break;

	if (i <= m - 1 && T->mptr[i] && T->mptr[i] != S->lChild)
		createBTree(mainParent, T->mptr[i], S);

	else
	{
		if (T->cnt < m - 1)
		{
			//Here we are checking if we have some space in the array. This is the condition when we are not into overflow.
			if (T->keys[T->cnt - 1] < S->data)
				T->keys[T->cnt++] = S->data;
			else
			{
				shiftNodesAndNewNode(T, S);
			}
		}
		else
		{

			// This is basically overflow condition

			BT splitNode = splitIntoTwoNodes(T, S);
			SN newParentInfo = new (struct snode);

			newParentInfo->data = T->keys[T->cnt];
			newParentInfo->lChild = T;
			newParentInfo->rChild = splitNode;

			T->keys[T->cnt] = -1;

			if (T == mainParent)
			{

				BT newParent = new (struct bnode);
				newParent->keys[newParent->cnt] = newParentInfo->data;
				newParent->mptr[newParent->cnt] = newParentInfo->lChild;
				newParent->mptr[newParent->cnt + 1] = newParentInfo->rChild;
				newParent->cnt++;

				mainParent = newParent;
			}
			else
			{
				createBTree(mainParent, mainParent, newParentInfo);
			}
		}
	}
}
void display(BT T)
{
	if (T != NULL)
	{
		for (int i = 0; i < m; i++)
		{
			display(T->mptr[i]);
			if (i < m - 1 && T->keys[i] != -1)
				cout << T->keys[i] << " ";
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
	validate(mainParent);
	int n;
	cin >> n;
	mainParent->keys[mainParent->cnt++] = n;
	cin >> n;
	while (n != -1)
	{
		SN S = new (struct snode);
		S->data = n;
		createBTree(mainParent, mainParent, S);
		cin >> n;
	}
	display(mainParent);
	cout << endl;
}