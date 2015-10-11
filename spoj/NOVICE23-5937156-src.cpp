#include<iostream>
using namespace std;
bool prime[1000001]={0};

unsigned long int pi[1000001]={0};

int main()
{
    prime[0]=true;
    prime[1]=true;
    for(int i=2;i<1001;i++)
      if(!prime[i])
      {
          for(int j=i*i;j<1000001;j=j+i)
            prime[j]=true;
      }

    for(int i=0;i<1000001;i++)
      if(!prime[i])
        pi[i]=pi[i-1]+1;
      else pi[i]=pi[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<pi[n]<<endl;
    }
}
