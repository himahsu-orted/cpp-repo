#include <bits/stdc++.h>
using namespace std;


static int c = 0;
void merger(int arr[], int l, int r, int m) {

    int a = m - l + 1;
    int b = r - m;

    int m1[a], m2[b];
    for (int i = 0; i < a; i++)
        m1[i] = arr[i + l];
    for (int i = 0; i < b; i++)
        m2[i] = arr[i + 1 + m];

    int i = 0, j = 0, k = l;
    while (i < a && j < b) {

        if (m1[i] <= m2[j]) {
            arr[k] = m1[i];
            i++;
        } else {
            c = c + (a - i);
            arr[k] = m2[j];
            j++;
        }
        k++;
    }
    while (i < a) {
        arr[k] = m1[i];
        k++;
        i++;
    }
    while (j < b) {

        arr[k] = m2[j];
        k++;
        j++;
    }

}
void mergesort(int arr[], int l , int r) {

    if (l >= r) {
        return ;
    } else {

        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merger(arr, l, r, m);
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

    int arr[] = {2, 4, 1, 3, 5};

    mergesort(arr, 0, 4);

    cout << c;
}
