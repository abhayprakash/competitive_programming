#include<iostream>
using namespace std;
int main()
{    
int m,n;
cin>>m>>n;
do{
    if(n==1||m==1)
      cout<<m<<"+"<<n<<"="<<m+n<<endl;
    else
      cout<<m<<"+"<<n<<"!="<<m+n<<endl;
    cin>>m>>n;
    }while(m!=-1);
}

