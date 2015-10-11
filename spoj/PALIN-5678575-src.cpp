#include<iostream>
using namespace std;
bool check(string new1,string old)
{
    if(new1.length()>old.length())
      return true;
    else if(new1.length()==old.length())
    {
        if(new1>old) return true;
    }
    return false;
}
void makemirror(string& s)
{
    int l=s.length();
    for(int i=l/2;i<l;i++)
      s[i]=s[l-1-i];
}
void change(string& s)
{
    int l=s.length(),i=(l-1)/2;
    if(s[i]<'9')
      s[i]++;
    else{
      while(s[i]=='9'&&i!=0)
      {
          s[i]='0';
          i--;
      }
      if(i==0)
      {
          if(s[i]!='9')
           s[i]++;
          else
           s[i]='0';
      }
      if(i!=0)
      {
          s[i]++;
      }
      else if(i==0&&s[0]=='0')
      {
          s="1"+s;
      }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,b;
        cin>>s;
        b=s;
        makemirror(b);
        if(check(b,s))
        {
            cout<<b<<endl;
            continue;
        }
        else
        {
            change(b);
            makemirror(b);
            cout<<b<<endl;
        }
    }
}
