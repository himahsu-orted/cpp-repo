#include<bits/stdc++.h>
using namespace std;

void displayPos(int start, int end)
{
    cout<<"Window from "<<start<<" to "<<end;
}
void sortingF(int A[],int n)
{
    int i=0,j=n-1,ePos=0,sPos=0;
    
        while(A[i]<A[i+1] && A[i]<A[j]) i++;
        while(A[j]>A[j-1] && A[j]>A[i]) j--;
        displayPos(i,j);
}
int main()
{
    int n;
    cin>> n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[n];
    sortingF(A,n);
}