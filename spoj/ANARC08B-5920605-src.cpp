#include<iostream>
#include<string>
#include<stack>
using namespace std;

int fn(string s)
{
    if(s=="063")
      return 0;
    if(s=="010")
      return 1;
    if(s=="093")
      return 2;
    if(s=="079")
      return 3;
    if(s=="106")
      return 4;
    if(s=="103")
      return 5;
    if(s=="119")
      return 6;
    if(s=="011")
      return 7;
    if(s=="127")
      return 8;
    if(s=="107")
      return 9;
}
string fns(int n)
{
    if(n==0)
      return ("063");
    if(n==1)
      return ("010");
if(n==2)
    return ("093");
       if(n==3)
    return ("079");
     if(n==4)
    return ("106");
      if(n==5)
    return ("103");
      if(n==6)
    return ("119");
      if(n==7)
    return ("011");
      if(n==8)
    return ("127");
      if(n==9)
    return ("107");

}
int main()
{
    string s;
    cin>>s;
    while(s!="BYE")
    {
        string initial=s;
        string temp;
        int n1=0,n2=0;
        while(s[0]!='+')
        {
            temp=s.substr(0,3);
            n1=10*n1+fn(temp);
            s.erase(0,3);
        }
        s.erase(0,1);
        while(s[0]!='=')
        {
            temp=s.substr(0,3);
            n2=10*n2+fn(temp);
            s.erase(0,3);
        }
        int dec_ans=n1+n2;
        stack<int> st;
        while(dec_ans)
        {
            st.push(dec_ans%10);
            dec_ans/=10;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=fns(st.top());
            st.pop();
        }
        cout<<initial<<ans<<endl;
        cin>>s;
    }
}
