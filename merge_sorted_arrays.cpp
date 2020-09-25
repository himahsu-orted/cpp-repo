#include <bits/stdc++.h>
using namespace std;

void reFunc(int X[], int Y[])
{
    int i, j, k, temp = 0;
    for (i = 0; i < 8; i++)
    {
        if (X[i] == 0)
        {
            j = 0;
            k = 0;
            while (j < 5)
            {
                if (Y[j] < X[i + 1] && Y[j] != -1)
                {
                    X[i] = Y[j];
                    Y[j] = -1;
                    k++;
                    break;
                }
                j++;
            };
            if (k == 0)
            {
                X[i] = X[i + 1];
                X[i + 1] = 0;
            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        if (X[i] == 0)
        {
            X[i] = X[i + 1];
            X[i + 1] = 0;
        }
    }
    for (i = 0; i < 9; i++)
    {
        if (X[i] == 0)
        {
            for (j = 0; j < 5; j++)
            {
                if (Y[j] != -1)
                    X[i++] = Y[j];
            }
        }
    }
}
int main()
{
    int X[9] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
    int Y[5] = {1, 8, 9, 10, 15};
    reFunc(X, Y);
    for (int i = 0; i < 9; i++)
    {
        cout << X[i] << " ";
    }
}