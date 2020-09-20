#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n,int place)
{
    int div;
    div=pow(10,place);
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
    for(i=n-1;i>=0;i--)
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
    int num=max;
    int count=0;
    while(num>0)
    {
        count++;
        num=num/10;
        
    };
    for(i=0;i<n;i++)
    {
        arr[i]=A[i];
    }
    for(i=0;i<count;i++)
    {
        countSort(arr,n,i);
    }
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
}