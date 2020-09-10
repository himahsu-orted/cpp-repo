#include<bits/stdc++.h>
using namespace std;

void comput(int A[], int alen, int B[],int blen)
{
    int i,j,temp;
    for(i=0;i<blen;i++)
    {
        for(j=0;j<alen;j++)
        {
            if(B[i]==A[j])
            {
                cout<< A[j]<<" ";
                A[j]=-1;
            }
        }
    }
    for(i=0;i<alen-1;i++)
    {
        for(j=0;j<alen-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    for(i=0;i<alen;i++)
    {
        if(A[i]!=-1)
        cout<<A[i]<<" ";
    }
}

int main()
{
    int arr1[15] = {5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4};
    int arr2[4] = {3, 5, 7, 2};
    comput(arr1,15,arr2,4);
}