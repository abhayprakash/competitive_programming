#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n,k,count=0;
    cin>>n>>k;
    int a[n];
    set<int> as;
    for(int i=0;i<n;i++)
      {
          cin>>a[i];
          //table[a[i]]=1;
          as.insert(a[i]);
      }
    //sort(a,a+n);
    for(int i=0;i<n;i++)
      if(as.find(a[i]+k)!=as.end())
        count++;
    cout<<count<<endl;
}
