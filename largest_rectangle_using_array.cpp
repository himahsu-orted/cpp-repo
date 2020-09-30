#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int arr[6]={21, 1, 6, 7, 5, 3};
  
    int maxArea=0;
    int temp;
    int count=0;
    for(int i=0;i<6;i++)
    {
        temp=arr[i];
        for(int j=0;j<6;j++)
        {
            if(arr[j]>=temp)
            {
                count++;
            }
            else
            {
                if(count*temp>=maxArea)
                maxArea=count*temp;

                if(temp>maxArea)
                maxArea=temp;

                count=0;
            }   
        }
        count=0;
    }
    cout<<maxArea;
}