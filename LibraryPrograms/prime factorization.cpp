#include<iostream>
#include<map>
#include<iterator>
#include<cmath>
#include<bitset>
using namespace std;
int main()
{
    typedef map<unsigned long int,unsigned long int,less<unsigned long int> > map1;
    map1 prime;
    unsigned long int n;
    cin>>n;
    //int p[(int)sqrt(n)+1];
    unsigned long int size=(unsigned long int)(n/2)+1;
    bool s[size];
    for(unsigned long int i=2;i<size;i++)
      s[i]=true;
    for(unsigned long int i=2;i<size;i++)
      {
          if(s[i])
          {
              unsigned long int j=2;
              while(i*j<size)
              {
                  if(s[i*j])
                    s[i*j]=false;
                  j++;
              }
          }
      }
    unsigned long int tcount=0;
    for(unsigned long int i=2;i<size;i++)
     {
         if(s[i])
         {
             unsigned long int temp=n,count=0;
             while(temp%i==0)
             {
                 temp/=i;
                 count++;tcount++;
             }
             prime.insert(map1::value_type(i,count) );
         }
     }
     if(!tcount)
               prime.insert(map1::value_type(n,1) );
    for(map1::iterator iter=prime.begin();iter!=prime.end();iter++)
      if(iter->second)
        //prime.erase(iter);
    //for(map1::const_iterator iter=prime.begin();iter!=prime.end();iter++)
      cout<<iter->first<<"  :  "<<iter->second<<endl;
}
