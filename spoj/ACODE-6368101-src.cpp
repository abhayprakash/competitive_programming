#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    while(s!="0")
    {
        int l=s.length();
        unsigned long int p[l+1];
        p[l]=1;
        if(s[l-1]=='0') p[l-1] = 0;
        else p[l-1]=1;
        for(int i=l-2;i>=0;i--)
        {
            if(s[i]=='0')
              p[i]=0;//because 10 has only one possiblity so p[i] = p[i+2] only
            else{
              p[i]=p[i+1];
              if(((s[i]-'0')*10+s[i+1]-'0')<=26)
                p[i]+=p[i+2];}
        }
        cout<<p[0]<<endl;
        cin>>s;
    }
}


