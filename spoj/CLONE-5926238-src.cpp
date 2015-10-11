#include<iostream>
#include<sstream>
#include<map>
using namespace std;
unsigned long long int num_value(string s)
{
    unsigned long long int num=0;
    istringstream input(s);
    char c;
    while(input>>c){
    if(c=='A')
      num=num*4+0;
    else if(c=='C')
      num=num*4+1;
    else if(c=='G')
      num=num*4+2;
    else if(c=='T')
      num=num*4+3;
    }
    return num;
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(1)
    {
        if(n==0 && m==0)
          break;
        map<unsigned long long int,int> table;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            unsigned long long int key=num_value(s);
            table[key]++;
        }
        map<unsigned long long int,int>::iterator it=table.begin();
        int a[n+1];
        for(int i=0;i<=n;i++)
          a[i]=0;
        for(;it!=table.end();it++)
          {
              //cout<<it->first<<" "<<it->second<<" a of this is increased\n";
              a[it->second]++;
          }
        for(int i=1;i<=n;i++)
          cout<<a[i]<<endl;
        cin>>n>>m;
    }
}
