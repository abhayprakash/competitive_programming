#include<iostream>
#include<cmath>
using namespace std;
int arr[]={2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921};
int bSearch(int key,char p)
{
    int len = sizeof(arr)/sizeof(int);
    int left,right,mid;

    left=0; right=len-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==key) return mid;

        if(key<arr[mid]) right=mid-1;
        else left=mid+1;
    }
    if(p=='r')
    {
        if(key>arr[mid])
          return mid;
        else
          return mid-1;
    }
    else
    {
        if(key>arr[mid])
          return mid+1;
        else
          return mid;
    }
}
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<bSearch(b,'r')-bSearch(a,'l')+1<<endl;
    }
}
