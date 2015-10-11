#include<iostream>
using namespace std;
int main()
{
    unsigned long int m;
    int n;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    unsigned long int sum_max=0;
    unsigned long int sum_max_arr[n];
    int ar_ct=0;
    int i_start=0,i_end=0;
    for(;i_end<n;i_end++)
      {
          sum_max+=a[i_end];
          //cout<<sum_max<<"inloop\n";
          if(sum_max>m)
          {
              sum_max-=a[i_end];
              i_end--;
              sum_max_arr[ar_ct++]=sum_max;
              sum_max-=a[i_start];
              i_start++;
          }
      }
    //cout<<sum_max<<"*"<<endl;
    sum_max_arr[ar_ct++]=sum_max;
    unsigned long int real_max=sum_max_arr[0];
    for(int i=1;i<ar_ct;i++)
      {
          if(sum_max_arr[i]>real_max)
            real_max=sum_max_arr[i];
          if(real_max==m)
            break;
      }
    cout<<real_max<<endl;
}
