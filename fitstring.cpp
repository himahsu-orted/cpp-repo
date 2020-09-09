#include<bits/stdc++.h>
using namespace std;

void display(int F[], int len)
{
    static int display_i=0;
    if(display_i<len)
    {
        cout<<F[display_i]<<" ";
        display_i++;
        display(F,len);
    }
    else
    {
        display_i=0;
        return;
    }
    
}
int checkLenghtOfNumber(int n)
{
    static int lengthOfNumber=0;
    if(n==0)
    return lengthOfNumber;

    lengthOfNumber++;
    return(checkLenghtOfNumber(n/10));
}

void fitsToArray(int F[],int length,int n)
{
    if(n==0) return;

    F[length-1]=n%10;
    fitsToArray(F,length-1,n/10);
}
int fitsToNumber(int A[],int F[],int length,int changer)
{
    static int prd=0;
    static int sum=0;
    if(prd<=length)
    {
        sum=sum+A[prd]*F[changer];
        ++prd;
        fitsToNumber(A,F,length,changer-1);
    }
    return sum;
}
void generate(int A[], int F[], int curr, int n)
{
    static int generate_i=0;

    if(n==0)
    {
        generate_i=0;
        return;
    }

    if(curr/A[n-1]>0)
    {
        F[generate_i]=1;
    }
    else
    {
        F[generate_i]=0;
    }
    curr=curr%A[n-1];
    generate_i++;
    generate(A,F,curr,n-1);

}
void fibonacci(int A[],int n,int cur,int next)
{
    static int m=0;
    if(m<n)
    {
        A[m]=next;
        if(m==0)
        {
            A[m+1]=next;
            m=1;
        }
        m++;
        fibonacci(A,n,next,cur+next);
    }
}
void controller(int n,int len)
{
    int A[n],F[len];
    fitsToArray(F,len,n);
    fibonacci(A,len,1,1);
    int currentNumber=fitsToNumber(A,F,len-1,len-1);
    cout<<"Decrement FitString: ";
    generate(A,F,currentNumber-1,len);
    display(F,len);

    cout<<"\nIncrement FitString: ";

    generate(A,F,currentNumber+1,len);
    display(F,len);
}
int main()
{
    int n;
    cin>>n;
    int lengthOfNumber=checkLenghtOfNumber(n);
    controller(n,lengthOfNumber);
}