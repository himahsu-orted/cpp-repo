#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    int i,max;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        max=arr[i];
        else
        {
            if(arr[i]>max)
            max=arr[i];
        }
    }
    int fx[max+1];

    for(i=0;i<max+1;i++)
    fx[i]=0;

    for(i=0;i<n;i++)
    {
        fx[arr[i]]++;
    }
    cout<<endl;
    for(i=1;i<max+1;i++)
    {
        fx[i]+=fx[i-1];
    }
    int B[n],pos;
    for(i=0;i<n;i++)
    {
        pos=fx[arr[i]]-1;
        fx[arr[i]]--;
        B[pos]=arr[i];
    }
    cout<<"\nSorted Numbers: ";
    for(i=0;i<n;i++)
    {
        cout<<B[i]<<"  ";
    }
}