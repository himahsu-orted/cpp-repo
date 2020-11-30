#include <bits/stdc++.h>
using namespace std;
typedef struct vertex
{
    int data;
    int at = -1;
    int dt = -1;
} * VN;
static int atCount = 0;
void findATDT(vector<vector<VN>> mainArray, vector<VN> insideArray, vector<VN> &temp, vector<bool> &isVisited)
{
    for (int i = 0; i < insideArray.size(); i++)
    {

        if (!isVisited[insideArray[i]->data])
        {
            temp[insideArray[i]->data] = insideArray[i];

            insideArray[i]->at = atCount;
            atCount++;
            isVisited[insideArray[i]->data] = true;
        }

        findATDT(mainArray, mainArray[insideArray[i]->data], temp, isVisited);

        if (insideArray[i]->dt == -1 && insideArray[i]->at != -1)
        {
            insideArray[i]->dt = atCount;
            atCount++;
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

    int n, e, temp;
    cin >> n >> e;

    vector<vector<VN>> arr(n);
    vector<bool> isVisited(n, false);
    vector<VN> storeArray(n);
    for (int i = 0; i < e; i++)
    {
        cin >> n >> temp;
        VN add = new (struct vertex);
        add->data = temp;
        arr[n].push_back(add);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!isVisited[i])
        {
            VN add = new (struct vertex);
            add->data = i;
            add->at = atCount;
            atCount++;
            storeArray[i] = add;
        }

        findATDT(arr, arr[i], storeArray, isVisited);

        if (storeArray[i]->at != -1 && storeArray[i]->dt == -1)
        {
            storeArray[i]->dt = atCount;
            atCount++;
        }
    }
    for (int i = 0; i < storeArray.size(); i++)
        if (storeArray[i])
            cout << storeArray[i]->data << " " << storeArray[i]->at << " " << storeArray[i]->dt << endl;
}