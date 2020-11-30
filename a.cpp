#include <bits/stdc++.h>
using namespace std;

#define m 5

typedef struct bnode
{
	int cnt = 0;
	int keys[m - 1] = {0};
	struct bnode *mptr[m] = {NULL};
} * BT;

// This snode stands for service pointer node and basically would help in overflow condition.
typedef struct snode
{
	int data;
	struct bnode *lChild = NULL;
	struct bnode *rChild = NULL;
} * SN;

struct tempbnode
{
	int cnt;
	int keys[m] = {0};
	struct bnode *tmptr[m + 1] = {NULL};
};
void view(BT T)
{
	for (int i = 0; i < m - 1; i++)
	{
		if (T->keys[i] != -1)
			cout << T->keys[i] << " ";
	}
	// cout << endl;
}
void shiftNodesAndNewNode(BT &T, SN S)
{
	// cout << "Cam f   " << S->data << endl;
	// cout << "curent is " << T->keys[0] << endl;
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
	// cout << "curent is " << T->keys[i] << endl;
}
void transferToSecondNode(BT &currentNode, BT &splitNode, int partitionPos)
{
	int j = 0;
	for (int i = partitionPos; i < m; i++)
	{
		splitNode->mptr[j] = currentNode->mptr[i];
		currentNode->mptr[i] = NULL;

		if (i < m - 1)
		{
			splitNode->keys[j] = currentNode->keys[i];
			currentNode->keys[i] = 0;
			splitNode->cnt++;
			currentNode->cnt--;
		}
		j++;
	}
}
BT splitIntoTwoNodes(BT &currentNode, SN S)
{
	BT splitNode = new (struct bnode);
	int partitionPos = (m - 1) / 2;
	int i;
	for (i = 0; i < m - 1; i++)
		if (currentNode->keys[i] > S->data)
			break;
	int InsertionPos = i;
	if (InsertionPos == partitionPos)
	{
		transferToSecondNode(currentNode, splitNode, partitionPos);
		shiftNodesAndNewNode(currentNode, S);
	}
	else if (InsertionPos > partitionPos)
	{
		/* Here we are first checking if the insertion postition is in the partion area. If it is so then we first transfer the nodes from current node to split node and then add the new node to the last element of split node */

		transferToSecondNode(currentNode, splitNode, partitionPos + 1);
		shiftNodesAndNewNode(splitNode, S);
		cout << currentNode->cnt;
		// splitNode->keys[splitNode->cnt] = S->data;
		// splitNode->mptr[splitNode->cnt] = S->lChild;
		// splitNode->mptr[splitNode->cnt + 1] = S->rChild;
		// splitNode->cnt++;

		// cout << splitNode->cnt << "for " << S->data;
	}
	else
	{
		// cout << "came here for " << S->data;
		/* Here we are into a condtition that the insertion position is before in the array than partition position and that means that we will need to first transfer and then add the new node in the desired position in current node*/

		transferToSecondNode(currentNode, splitNode, partitionPos + 1);
		shiftNodesAndNewNode(currentNode, S);
		cout << currentNode->cnt;
		// cout << splitNode->cnt << "for " << S->data;
	}

	return splitNode;
}
void createBTree(BT &mainParent, BT &T, SN S)
{
	int i;
	for (i = 0; i < m; i++)
	{
		if (i < m - 1 && T->keys[i] > S->data)
			break;
		else if (T->keys[i] == 0)
			break;
	}

	if (T->mptr[i] && !S->lChild && !S->rChild)
	{
		cout << "Getting into recursion at PTR: " << i << " for " << S->data << endl;
		createBTree(T->mptr[i], T->mptr[i], S);
	}

	else
	{
		if (T->cnt < m - 1)
		{
			cout << "The index of :" << i << " for: " << S->data << endl;
			//Here we are checking if we have some space in the array. This is the condition when we are not into overflow.
			cout << "Came to add " << S->data << " by shifting. Current: " << T->keys[0] << endl;
			if (T->keys[T->cnt - 1] < S->data)
			{
				T->keys[T->cnt] = S->data;
				T->mptr[T->cnt] = S->lChild;
				T->mptr[T->cnt + 1] = S->rChild;
				T->cnt++;
			}
			else
			{
				shiftNodesAndNewNode(T, S);
			}
			// cout << "New supposed parent is now " << mainParent->keys[0] << endl;
			cout << "Current Size is " << T->cnt << endl;
			view(T);
			cout << endl;
		}
		else
		{

			BT splitNode = splitIntoTwoNodes(T, S);
			// T->mptr[T->cnt + 1] = NULL;
			SN newParentInfo = new (struct snode);

			if (S->lChild && S->rChild)
			{
				T->mptr[T->cnt] = S->lChild;
				splitNode->mptr[0] = S->rChild;

				S->lChild = T;
				S->rChild = splitNode;
			}

			newParentInfo->data = T->keys[T->cnt - 1];
			newParentInfo->lChild = T;
			newParentInfo->rChild = splitNode;

			T->keys[T->cnt - 1] = 0;
			T->mptr[T->cnt] = NULL;
			T->cnt--;
			cout << "Came to add " << S->data << " by splitting\n";
			view(T);
			cout << "  ";
			view(splitNode);
			cout << endl;
			if (T == mainParent)
			{
				BT newParent = new (struct bnode);

				newParent->keys[newParent->cnt] = newParentInfo->data;
				newParent->mptr[newParent->cnt] = newParentInfo->lChild;
				newParent->mptr[newParent->cnt + 1] = newParentInfo->rChild;
				newParent->cnt++;

				mainParent = newParent;

				cout << "New supposed parent is now " << mainParent->keys[0] << endl;
			}
			else
			{

				cout << "Want to add new parent for " << S->data << " as " << newParentInfo->data << endl;
				createBTree(mainParent, mainParent, newParentInfo);
				cout << "After Backtrack" << endl;
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
			if (i < m - 1 && T->keys[i] != 0)
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
	int n;
	cin >> n;
	mainParent->keys[mainParent->cnt++] = n;
	cin >> n;
	while (n != -1)
	{
		SN S = new (struct snode);
		S->data = n;
		createBTree(mainParent, mainParent, S);
		cout << "New parent is now " << mainParent->keys[0] << " Size: " << mainParent->cnt << endl;
		cout << endl;
		cin >> n;

		display(mainParent);
		cout << endl
			 << endl;
	}
	// view(mainParent->mptr[]);

	cout << endl;
}