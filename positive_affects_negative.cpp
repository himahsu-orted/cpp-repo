#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int x, y;
} * VN;
void addPositives(vector<vector<int>> &arr, stack<VN> &pos, int x, int y)
{
    arr[x][y] = 1;
    VN add = new (struct node);
    add->x = x;
    add->y = y;
    pos.push(add);
}
void addZero(vector<vector<int>> &arr, int x, int y)
{
    arr[x][y] = 0;
}
void controller(vector<vector<int>> &arr, stack<VN> &pos)
{
    stack<VN> temp;
    while (!pos.empty())
    {
        int x = pos.top()->x;
        int y = pos.top()->y;
        int i = arr.size();
        int j = arr[0].size();
        pos.pop();
        if ((x + 1) < i && arr[x + 1][y] < 0)
        {
            arr[x + 1][y] = 1;
            addPositives(arr, temp, x + 1, y);
        }
        if ((x - 1) >= 0 && arr[x - 1][y] < 0)
        {
            arr[x - 1][y] = 1;
            addPositives(arr, temp, x - 1, y);
        }
        if ((y + 1) < j && arr[x][y + 1] < 0)
        {
            arr[x][y + 1] = 1;
            addPositives(arr, temp, x, y + 1);
        }
        if ((y - 1) >= 0 && arr[x][y - 1] < 0)
        {
            arr[x][y - 1] = 1;
            addPositives(arr, temp, x, y - 1);
        }
    }
    while (!temp.empty())
    {
        pos.push(temp.top());
        temp.pop();
    }
}
void display(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] > -1)
                cout << " ";
            cout << arr[i][j] << " ";
        }
        cout << endl;
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

    vector<vector<int>> arr;
    stack<VN> pos;
    for (int i = 0; i < 5; i++)
    {
        vector<int> in(6, -1);
        arr.push_back(in);
    }
    addPositives(arr, pos, 2, 3);
    addPositives(arr, pos, 4, 5);
    addPositives(arr, pos, 2, 2);
    addZero(arr, 4, 4);
    addZero(arr, 1, 1);
    display(arr);
    int count = 0;
    while (!pos.empty())
    {
        cout << endl;
        controller(arr, pos);
        display(arr);
        count++;
    }
    cout << count;
}