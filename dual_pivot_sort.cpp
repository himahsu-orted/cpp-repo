#include<bits/stdc++.h>
using namespace std;

void pivot(int A[], int l1, int h1, int l2, int h2, int P1, int P2)
{
    int temp;
    if(l1<h1)
    {
        while(A[l1]<P1) l1++;
        while(A[h1]>P1) h1--;
        if(l1<h1)
        {
            temp=A[l1];
            A[l1]=A[h1];
            A[h1]=temp;
        }
    }
    if(l2<h2)
    {
        while(A[l2]<P2) l2++;
        while(A[h2]>P2) h2--;
        if(l2<h2)
        {
            temp=A[l2];
            A[l2]=A[h2];
            A[h2]=temp;
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int A[n];   
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    } 
    //pivot(A,n);
    int temp;
    int P1=A[0],P2=A[n-1],l1,h1,l2,h2;
    l1=1;h1=n/2;
    l2=(n/2)+1;
    h2=n-2;
    if(l1<h1)
    {
        while(A[l1]<P1) l1++;
        while(A[h1]>P1) h1--;
        if(l1<h1)
        {
            temp=A[l1];
            A[l1]=A[h1];
            A[h1]=temp;
        }
    }
    if(l2<h2)
    {
        while(A[l2]<P2) l2++;
        while(A[h2]>P2) h2--;
        if(l2<h2)
        {
            temp=A[l2];
            A[l2]=A[h2];
            A[h2]=temp;
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    } 
}