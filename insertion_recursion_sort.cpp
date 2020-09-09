#include<bits/stdc++.h>
using namespace std;

void chArr(int A[],int posOfAllocation,int end,int val)
{
    if(end>=posOfAllocation)
    {
        A[end]=A[end-1];
        chArr(A,posOfAllocation,end-1,val);
    }
    else
    {
        A[posOfAllocation]=val;
    }
}
void findPos(int A[],int end,int val)
{
    static int j=0;
    if(j<=end)
    {
        if(val<=A[j])
        {
            chArr(A,j,end+1,val);
            j=0;
            return;
        }
        j++;
        findPos(A,end,val);
    }
}
void reSort(int A[], int sorted,int n)
{
    static int i=0;
    if(i<n)
    {
        i++;
        if(A[sorted]>A[sorted+1])
        {
            findPos(A,sorted,A[sorted+1]);
        }
        reSort(A,sorted+1,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>> a[i];
    }
    reSort(a,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}