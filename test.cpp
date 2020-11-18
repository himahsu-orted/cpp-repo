#include <bits/stdc++.h>
using namespace std;

typedef struct gtnode
{

	char data;
	struct gtnode *fc;
	struct gtnode *ns;
} * GT;

void makeTree(GT t)
{
	char ch;
	cin >> ch;
	if (ch != '.')
	{
		GT add = new (struct gtnode);
		add->data = ch;
		t->fc = add;
		makeTree(t->fc);
	}
	else
	{
		t->fc = NULL;
	}
	cin >> ch;
	if (ch != '.')
	{
		GT add = new (struct gtnode);
		add->data = ch;
		t->ns = add;
		makeTree(t->ns);
	}
	else
	{
		t->ns = NULL;
	}
}
void display(GT t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		display(t->fc);
		cout<<endl;
		display(t->ns);
	}
	// else
	// 	cout << ".";
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

	GT t = new (struct gtnode);
	char ch;
	cin >> ch;
	t->data = ch;
	t->fc = NULL;
	t->ns = NULL;

	makeTree(t);
	display(t);
}
