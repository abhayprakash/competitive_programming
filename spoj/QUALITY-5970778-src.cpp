#include<iostream>
using namespace std;
int main()
{
    int a;
    int count=1;
    while(cin>>a)
    {
        int b,c,d,e,f;
        cin>>b>>c>>d>>e>>f;
        int solved=0,time=a+b+c;
        if(a)
          {solved++;time+=(d-1)*20*60;}
        if(b)
          {solved++;time+=(e-1)*20*60;}
        if(c)
          {solved++;time+=(f-1)*20*60;}
        cout<<"team "<<count++<<": "<<solved<<", "<<time<<endl;
    }
}
