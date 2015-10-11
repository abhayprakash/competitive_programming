#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isoptr(char a)
{
    if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
    return true;
    return false;
}
bool ishigher(char a,char b)
{
    if(a=='^'&&b=='*')
      return true;
    else if(a=='^'&&b=='/')
      return true;
    else if(a=='^'&&b=='*')
      return true;
    else if(a=='^'&&b=='-')
      return true;
    else if(a=='^'&&b=='+')
      return true;
    else if(a=='/'&&b=='*')
      return true;
    else if(a=='/'&&b=='-')
      return true;
    else if(a=='/'&&b=='+')
      return true;
    else if(a=='*'&&b=='-')
      return true;
    else if(a=='*'&&b=='+')
      return true;
    else if(a=='-'&&b=='+')
      return true;
    return false;
}
string makepst(string infix)
{
    int li=infix.length();
    string outfix,temp;
    stack<char> optr;
    int i=0,count=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
           {
               int bc=1,dc=0,j=i+1;
               while(1)
               {
                   i++;
                   if(infix[i]=='(')
                      bc++;
                   else if(infix[i]==')')
                      bc--;
                   if(bc==0)
                     break;
                   dc++;
               }
               temp.assign(infix,j,dc);
               //cout<<outfix<<"before appending"<<endl;
               //cout<<makepst(temp)<<"to be appended"<<endl;
               outfix+=makepst(temp);
               //cout<<outfix<<"after appending"<<endl;
               i++;
           }
        if(isoptr(infix[i])&&infix[i]!='\0')
        {
            if(optr.empty())
              optr.push(infix[i]);
            else{
              if(ishigher(infix[i],optr.top()))
                optr.push(infix[i]);
              else{
                outfix+=optr.top();
                optr.pop();
                optr.push(infix[i]);
              }
            }
        }
        else{
          if(infix[i]!='\0')
          outfix+=infix[i];
            }
        if(infix[i]!='\0')
            i++;
    }

    while(!optr.empty())
    {
        outfix+=optr.top();
        optr.pop();
    }

    return outfix;
}
int main()
{
    string s;
    int t;
    cin>>t;
    while(t--){
    cin>>s;
    cout<<makepst(s)<<endl;
    }
    return 0;
}
