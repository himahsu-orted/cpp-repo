#include <bits/stdc++.h> 
using namespace std;

void swap(int A[],int l, int h)
{
    int temp;
    temp=A[l];
    A[l]=A[h];
    A[h]=temp;
}
int breakArray(int A[],int l , int h, int p)
{

    while(l<h)
    {
        while(A[l]<p) 
        {
            l++;
        }
        while(A[h]>p) 
        {
            h--;
        }
        if(l<h) 
        {
            swap(A,l,h);
        }
    }
    swap(A,l,h);
    return h;
}
void quickSort(int A[],int low,int high)
{
    int pos;
    if(low<high)
    {
        pos=breakArray(A,low,high,A[low]);
        quickSort(A,low, pos);
        quickSort(A, pos+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    quickSort(A,0,n-1);

    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
}