#include<iostream>
using namespace std;
int main()
{
   int a,b;
   char c;
   cout<<"Enter two numbers"<<endl;
   cin>>a>>b;
   cout<<" Enter the symbol of operation"<<endl;
   cin>>c;
   if(c=='+')
   {
    cout<<a+b;
   }
   else if(c=='-')
   {
    cout<<a-b;
   }
   else if(c=='*')
   {
    cout<<a*b;
   }
   else if(c=='/')
   {
    cout<<a/b;
   }
   return 0;
}