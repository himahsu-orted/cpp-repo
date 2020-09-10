#include<bits/stdc++.h>
using namespace std;

void triplet(int A[], int n)
{
    int i,j,k;
    for(int i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(i<j &&j<k)
                {
                    if(A[i]<A[j]&&A[j]<A[k])
                    {

                        cout<<A[i]<<"  "<<A[j]<<"  "<<A[k]<<"  ";
                        cout<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"Triplet not found.\n";
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
    triplet(A,n);
}