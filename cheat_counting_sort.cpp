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
    int j=0,l;
    for(i=0;i<max+1;i++)
    {
        if(fx[i]!=0)
        {
            for(l=0;l<fx[i];l++)
            {
                arr[j]=i;
                j++;
            }
        }
    }
    cout<<"\nSorted Array: \n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}