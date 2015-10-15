#include<iostream>
#include<vector>
#include<cstring>
#define SET(name,value) memset(&name,value,sizeof(name))//cstring is required
#define val 1000000
#define MAX 5000000
using namespace std;
vector<long int> ps;
long int i=2;
int main()
{//cout<<"hvjh\n";
       int ar[val];
       while(1)
       {
           SET(ar,1);
           long int index=i;
           for(int j=0;j<ps.size();j++)
             {
                 long int starter;
                 if(ps.size())
                   starter=i/ps[j];
                 else break;
                 if(starter*ps[j]-index<0) starter++;
                 for(;starter*ps[j]<=val+index;starter++)
                   ar[starter*ps[j]-index]=0;
             }
           for(;i-index<val;i++)
           {
               if(ar[i-index])
                 {
                     for(int j=2;i*j<=val+index;j++)
                       ar[i*j-index]=0;
                     ps.push_back(i);
                 }
                 if(ps.size()>=MAX)
                   break;
           }
           if(ps.size()>=MAX)
             break;
       }
       int t;
       cin>>t;
       while(t--)
       {
           int k;
           cin>>k;
           cout<<ps[k-1]<<endl;
       }
}
