#include<iostream>
#include<map>
int a[500001]={0};
using namespace std;
void fn()
{
    map<unsigned long int,bool> map1;

    for(int i=1;i<=500000;i++)
      {
          a[i]=a[i-1]-i;
          if(a[i]<=0 || map1[a[i]]==true)
          {
              a[i]=a[i-1]+i;
          }
          map1[a[i]]=true;
      }
}
int main()
{
    fn();
    int n;
    cin>>n;
    while(n!=-1)
    {
        cout<<a[n]<<endl;
        cin>>n;
    }
}
