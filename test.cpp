#include<bits/stdc++.h>
using namespace std;

int main()
{

    int arr[5];
    int i,j,count=0;
    for(i=0;i<5;i++)
    cin>>arr[i];

    for(i=0;i<5;i++)
    {
        for(j=i;j<5;j++)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
        if(count>=5-i-1)
        cout<<arr[i]<<" ";
        count=0;
    }
}