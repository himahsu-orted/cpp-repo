#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n,int place)
{
    int mod,div;
    if(place==0)
    {
        mod=10;
        div=1;
    }
    else if(place==1)
    {
        mod=10;
        div=10;
    }
    else
    {
        mod=1;
        div=100;
    }
    int i;
    int max=9;
    int fx[max+1];

    for(i=0;i<max+1;i++)
    fx[i]=0;

    for(i=0;i<n;i++)
    {
        fx[(arr[i]/div)%10]++;
    }
    cout<<endl;
    for(i=1;i<max+1;i++)
    {
        fx[i]+=fx[i-1];
    }
    int B[n],pos;
    for(i=0;i<n;i++)
    {
        pos=fx[(arr[i]/div)%10]-1;
        fx[(arr[i]/div)%10]--;
        B[pos]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        arr[i]=B[i];
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n],A[n];
    int i,max;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
        if(i==0)
        max=A[i];
        else
        {
            if(A[i]>max)
            max=A[i];
        }
    }
    for(i=0;i<n;i++)
    {
        arr[i]=A[i];
    }
    for(i=0;i<3;i++)
    {
        countSort(arr,n,i);
        cout<<endl;
        for(int j=0;j<n;j++)
        {
        cout<<arr[j]<<" ";
        }
    }
}