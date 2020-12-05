#include <bits/stdc++.h>
using namespace std;

typedef struct jug
{
    int vertex;
    int weight;
} * JG;

void insert(vector<JG> &jugs, int vertex, int weight)
{
    JG add = new (struct jug);
    add->vertex = vertex;te
    add->weight = weight;
    jugs.push_back(add);
}
void display(vector<JG> jugs, JG oneJug, int destination)
{
    cout << oneJug->weight << " ";
    if (destination != oneJug->vertex)
        display(jugs, jugs[oneJug->vertex], destination);
    else
        return;
}
void threeJugs(vector<JG> jugs)
{
    display(jugs, jugs[0], jugs[jugs.size() - 1]->vertex);
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

    vector<JG> jugs;
    insert(jugs, 1, 8);
    insert(jugs, 2, 3);
    insert(jugs, 0, 5);

    threeJugs(jugs);
}
