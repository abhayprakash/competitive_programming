//to submit
#include<iostream>
#include<string>
#include<vector>
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
    longnumber operator-(longnumber);
    friend longnumber dbt(longnumber n);
    };
longnumber longnumber::operator+(longnumber ntoadd)
{
    longnumber toreturn;
    string s1,s2;
    s1=num;s2=ntoadd.num;
    int m= s1.length();
    int n= s2.length();
    //cout<<"*"<<m<<"*"<<n<<endl;//delete
    //int num1[m],num2[n];
    int c=0;
    int d=max(n,m)+1;
    int sum[d];
    char sumchar[d+1];
    char dummyarray[d];
    sumchar[d]='\0';
    dummyarray[d-1]='\0';
    int k=min(m,n);
    for(int i=0;i<k;i++)
    {
        //cout<<"sum element*"<<sum[d-1]<<"*=element1"<<s1[m-1]<<"*+element2"<<s2[n-1]<<"carry"<<c<<endl;
        //cout<<"sum actual="<<s1[m-1]-48+s2[n-1]-48+c<<endl;
        sum[d-1]=(s1[m-1]-48+s2[n-1]-48+c)%10;
        //cout<<"debugging :sum last dig:"<<sum[d-1]<<endl;
        //cout<<"now carry="<<c<<endl;
        c=(s1[m-1]-48+s2[n-1]-48+c)/10;
        //cout<<"debugging: carry:"<<c<<endl;
        //cout<<"final c="<<c<<endl;
        //cout<<"\n*after sum sum element"<<sum[d-1]<<"*carry element"<<c<<endl;
        d--;m--;n--;
    }
    int dummy=max(m,n)-min(m,n);
    if(m>n){
    for(int j=0;j<dummy;j++)
           {
            sum[d-1]=(s1[m-1]-48+c)%10;
            c=(s1[m-1]-48+c)/10;
            //cout<<"debugging line 51: sum d-1:"<<sum[d-1]<<endl;
            d--;m--;
            //cout<<"/*debugging m>n*/"<<c<<endl;
           }
    }
    else
        {
        for(int j=0;j<dummy;j++)
           {
            sum[d-1]=(s2[n-1]-48+c)%10;
            c=(s2[n-1]-48+c)/10;
            d--;n--;
            //cout<<"/*debugging n>m*/"<<c<<endl;
           }
        }
    sum[0]=c;
    //cout<<"/*debugging*/"<<sum[0]<<"*"<<c<<endl;
    //int select=0;
    //if(sum[0]==0) select=1;

    for(int i=0;i<max(s1.length(),s2.length())+1;i++)/**could'nt do it with subsrting*/
    {sumchar[i]=sum[i]+48;}//cout<<sumchar[i]<<endl;}
    //cout<<"/*debugging*/"<<sum[0]<<endl;
    if(sum[0]!=0)
    toreturn.num=sumchar;

    else
    {
        for(int i=0;sumchar[i+1]!='\0';i++)
        dummyarray[i]=sumchar[i+1];
        toreturn.num=dummyarray;
    }
    return toreturn;
}
longnumber longnumber::operator-(longnumber ntosub)
{
    longnumber toreturn;
    string s1=num;
    string s2=ntosub.num;
    if(s1==s2)
    {
        toreturn.num="zero";
        return toreturn;
    }
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
ostream& operator<<(ostream& out,longnumber n)
{
    string s=n.num;
    if(s=="UJVO")
    {
        out<<"0";
        return out;
    }
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
    }
    return out;
}
istream& operator>>(istream& in,longnumber& n)
{
    in>>n.num;
    return in;
}
longnumber dbt(longnumber n)
{
    longnumber toreturn;
    string s=n.num;
    int l=s.length();
    char div[l];
    int d_i=0,c=0;
    for(int i=0;i<l;i++)
    {
        div[d_i++]=((10*c+s[i]-48)/2)+48;
        c=(10*c+s[i]-48)%2;
    }
    toreturn.num=div;
    return toreturn;
}
int main()
{
    for(int i=0;i<10;i++)
    {
    longnumber total,diff;
    cin>>total>>diff;
    cout<<dbt(total+diff)<<endl<<dbt(total-diff)<<endl;
    }
    return 0;
}
