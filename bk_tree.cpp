#include <bits/stdc++.h>
using namespace std;

#define min(x, y, z) min(min(x, y), z)
#define m 10

typedef struct node
{
	string word;
	struct node *ptr[m];
} * BK;
int getEditDistance(string a, string b)
{
	int row = b.length() + 1;
	int col = a.length() + 1;
	int arr[col][row];
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i == 0)
				arr[i][j] = j;

			else if (j == 0)
				arr[i][j] = i;

			else if (a[i - 1] == b[j - 1])
				arr[i][j] = arr[i - 1][j - 1];

			else
				arr[i][j] = 1 + min(arr[i][j - 1],
									arr[i - 1][j],
									arr[i - 1][j - 1]);
		}
	}
	return (arr[col - 1][row - 1]);
}
void createTree(BK &T, string newString)
{
	if (!T)
	{
		T = new (struct node);
		T->word = newString;
	}
	else
		createTree(T->ptr[getEditDistance(newString, T->word)], newString);
}
void wordFind(BK T, string phrase, int n)
{
	if (T)
	{

		int d = getEditDistance(T->word, phrase);
		if (d <= n)
			cout << d << " " << T->word << " ";
		for (int i = d - n; i < d + n; i++)
			wordFind(T->ptr[i], phrase, n);
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

	string a;
	BK T;
	cin >> a;
	while (1)
	{
		createTree(T, a);
		cin >> a;
		if (a[0] == '#')
			break;
	}
	int n;
	cin >> a >> n;
	wordFind(T, a, n);
	}