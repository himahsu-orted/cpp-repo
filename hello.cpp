#include <bits/stdc++.h> 

using namespace std;
 

int mainF();
int takeInput();

int32_t main() {

    mainF();
    return 0 ;
}
union arrayOfIntgerChar
{
    int a;
    char ch;
};
int mainF()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    arrayOfIntgerChar u[n];
    int flag[n];
    int tag;
    for(int i= 0;i<n;i++)
    {
        tag=takeInput();
        if(tag==1)
        {
            cout<<"\nEnter the charater value: ";
            flag[i]=tag;
            cin>>u[i].ch;
        }
        if(tag==0)
        {
            cout<<"\nEnter the integer value: ";
            flag[i]=tag;
            cin>>u[i].a;
        }
    }
    cout<<endl<<"The values are: ";
    for(int i=0;i<n;i++)
    {
        if(flag[i])
        {
            cout<<u[i].ch<<"\t";
        }
        else
        {
            cout<<u[i].a<<"\t";
        }
        
    }
    return 0;

}
int takeInput()
{
    cout<<"\nWhat do you want to store? 1.Integer 2. Char  :";
    int g;
    int res;
    cin>> g;    
    switch(g)
    {
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            cout<<"\nInvalid Entry. Please enter again. \n";
            return(takeInput());
    }
}