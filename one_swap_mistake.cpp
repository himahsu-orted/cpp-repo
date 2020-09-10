#include<bits/stdc++.h>
using namespace std;

void swap(int A[],int start, int end)
{
    int temp=A[start];
    A[start]=A[end];
    A[end]=temp;
}
void sortingF(int A[],int n)
{
    int i=0,j=n-1;
    
        while(A[i]<A[i+1] && A[i]<A[j]) i++;
        while(A[j]>A[j-1] && A[j]>A[i]) j--;
        swap(A,i,j);
}
int main()
{
    int n;
    cin>> n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    sortingF(A,n);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
}