#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class longnumber{
    string num;
    public:
    longnumber(string s="0")
    {
        num=s;
    }
    friend ostream& operator<<(ostream&,longnumber);
    friend istream& operator>>(istream&,longnumber&);
    longnumber operator+(longnumber);
    longnumber operator-(longnumber);//n>m
    friend longnumber purify(longnumber);
    };
longnumber longnumber::operator+(longnumber ntoadd)
{
    longnumber toreturn;
    string s1=num;
    string s2=ntoadd.num;
    int d1=s1.length();
    int d2=s2.length();
    int dm=max(d1,d2);
    int dl=min(d1,d2);
    char sm[dm+1];
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int c=0;
    int i=0;
    for(;i<dl;i++)
    {
        sm[i]=((s1[i]+s2[i]+c-2*'0')%10)+'0';
        c=(s1[i]+s2[i]+c-2*'0')/10;
    }

    if(dm==d1)
    {
        for(;i<dm;i++)
        {
        sm[i]=((s1[i]+c-'0')%10)+'0';
        c=(s1[i]+c-'0')/10;
        }
    }
    else
    {
        for(;i<dm;i++)
        {
        sm[i]=((s2[i]+c-'0')%10)+'0';
        c=(s2[i]+c-'0')/10;
        }
    }
    sm[i]=c+'0';
    if(c==0)
    {
        char tm[dm];
        copy(sm,sm+dm,tm);
        reverse(tm,tm+dm);
        toreturn.num=tm;
        return toreturn;
    }
    reverse(sm,sm+dm+1);
    toreturn.num=sm;
    return toreturn;
}
longnumber longnumber::operator-(longnumber ntosub)
{
    longnumber toreturn;
    string s1=num;
    string s2=ntosub.num;
    int m=s1.length();
    int n=s2.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    char diffc[m+1];
    int i;
    for(i=0;i<n;i++)
    {
        if(s1[i]>=s2[i])
        diffc[i]=s1[i]-s2[i]+48;
        else
        {
            int p=i+1;
            while(s1[p]=='0')
            s1[p++]='9';
            s1[p]--;
            diffc[i]=s1[i]+10-s2[i]+48;
        }
    }
    for(;i<m;i++)
    {
        diffc[i]=s1[i];
    }
    diffc[i]='\0';
    reverse(diffc,diffc+m);
    toreturn.num=diffc;
    return toreturn;
}
longnumber purify(longnumber n)
{
    longnumber toreturn;
    string s=n.num;
    int l=s.length();
    char dmy[l];
    copy(s.begin(),s.end(),dmy);
    int i=0;char temp[l];int cnt=0;
    while(dmy[i]=='0')
    i++;
    for(;i<l;i++)
    {
        if(dmy[i]>'9'||dmy[i]<'0')
        break;
        temp[cnt++]=dmy[i];
    }
    temp[cnt]='\0';
    toreturn.num=temp;
    return toreturn;
}
ostream& operator<<(ostream& out,longnumber n)
{
    /*string s=n.num;
    int l=s.length();
    char dmy[l];
    copy(s.begin(),s.end(),dmy);
    int i=0;
    while(dmy[i]=='0')
    i++;
    for(;i<l;i++)
    {
        if(dmy[i]>'9'||dmy[i]<'0')
        break;
        out<<dmy[i];
    }*/
    out<<n.num;
    return out;
}
istream& operator>>(istream& in,longnumber& n)
{
    in>>n.num;
    return in;
}
int main()
{
    //string s;
    //cin>>s;
    longnumber n;//(s);
    cin>>n;//check why this is not functioning.... operation failure
    //cin>>s;
    longnumber m;//(s);
    cin>>m;
    cout<<purify(n+m)<<endl;
    cout<<purify(n-m)<<endl;
    return 0;
}
