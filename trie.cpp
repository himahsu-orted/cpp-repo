#include <bits/stdc++.h>
using namespace std;

#define NO_OF_ALPHABET 36

typedef struct trienode
{
    bool isComplete = false;
    struct trienode *letter[NO_OF_ALPHABET];
} * TN;

void insert(TN &T, string word, int i = 0)
{
    if (!T)
        T = new (struct trienode);
    if (i >= word.length())
    {
        T->isComplete = true;
        return;
    }

    char oneLetter = word[i];

    if ((int)oneLetter >= 48 && (int)oneLetter <= 57)
        insert(T->letter[word[i] - 48], word, i + 1);

    else
        insert(T->letter[word[i] - 97 + 10], word, i + 1);
}
bool find(TN T, string word, int i = 0)
{
    if (!T)
        return false;
    if (i >= word.length())
    {
        if (T->isComplete)
            return true;
        else
            return false;
    }

    char oneLetter = word[i];

    if ((int)oneLetter >= 48 && (int)oneLetter <= 57)
        return find(T->letter[word[i] - 48], word, i + 1);

    else
        return find(T->letter[word[i] - 97 + 10], word, i + 1);
}
void display(TN T, vector<int> q, int n)
{
    if (T)
    {
        q.push_back(n);
        for (int i = 0; i < NO_OF_ALPHABET; i++)
        {
            display(T->letter[i], q, i);
        }
        if (T->isComplete)
        {
            for (int j = 1; j < q.size(); j++)
            {
                if (q[j] < 10)
                    cout << (char)(q[j] + 48) << "";
                else
                    cout << (char)(q[j] + 97 - 10) << "";
            }
            cout << " ";
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

    TN T = NULL;
    string a;
    cin >> a;
    while (a[a.length() - 1] != '#')
    {
        insert(T, a);
        cin >> a;
    }
    a.erase(a.length() - 1);
    insert(T, a);
    vector<int> q;
    display(T, q, 0);
}