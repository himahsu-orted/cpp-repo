#include <bits/stdc++.h>
using namespace std;

const int m = 5;
typedef struct mstnode
{
	int cnt;
	int keys[m - 1];
	struct mstnode *cptr[m];

} * MT;

void createTree()
{
}
int main()
{
	MT mtree = new (struct mstnode);
}