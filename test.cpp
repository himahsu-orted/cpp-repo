#include <bits/stdc++.h> 
#include <string>
using namespace std;
int fib(int n)
{
    int print_value;
    if(n==1||n==2)
    {
        return 1;

    }
    else
    {
        print_value = fib(n-1)+fib(n-2);
        return print_value;
        
    }
    
}
int getNewNumber(int sum, int j)
{
    int addDigit, newNumber = 0;
    while(j>0)
    {
        if(sum/fib(j)>0)
          addDigit = 1;
        else
          addDigit =0;

        newNumber = (newNumber*10) + addDigit;
        sum = sum%fib(j);
        j--;
    }
    return newNumber;

}
int main()
{
    int number, j=1,sum=0,newNumber,addDigit;
    cin>>number;
    for(int i=number;i>0;i=i/10)
    {
        sum = sum + (i%10)*fib(j);
        j++;
    }
    j=1;
    while(true)
    {
        if(fib(j)>sum)
          break;
        j++;
    }
    newNumber =0;
    j--;
    cout<<"Increamented Number is "<<getNewNumber(sum+1, j)<<endl;
    cout<<"Decremeneted Number is "<<getNewNumber(sum-1, j)<<endl;
}