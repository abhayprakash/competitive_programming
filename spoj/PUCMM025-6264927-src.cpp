#include<iostream>
using namespace std;
bool check(string s,int i,int sum)
{
    switch(i){
    case 1: return true;
            break;
    case 2: if((s[s.length()-1]-'0')%2 == 0) return true; break;
    case 3: if(sum%3 == 0) return true; break;
    case 4: if(((s[s.length()-2]-'0')*10 + (s[s.length()-1]-'0'))%4 == 0 ) return true; break;
    case 5: if(s[s.length()-1] == '0' ||s[s.length()-1] == '5') return true; break;
    case 6: if(check(s,2,sum) && check(s,3,sum)) return true; break;

    case 8: if(((s[s.length()-3]-'0')*100 +(s[s.length()-2]-'0')*10 + (s[s.length()-1]-'0'))%8 == 0 ) return true; break;
    case 9: if(sum%9 == 0) return true; break;
    }
    return false;
}
int main()
{
    string s;
    while(cin>>s)
    {
      int count[10]={0};
      int sum=0,sevn=0,stsv=0;
      for(int i=0;i<s.length();i++)
        {
          count[s[i]-'0']++;
          sum+=(s[i]-'0');
          sevn = sevn*10; // The previous sum we had must be multiplied
          sevn += s[i]-'0';
          sevn %= 7;
        }
      if(sevn==0) stsv=1;
      int answer=0;
      for(int i=1;i<10;i++)
        {
            if(count[i])
            {
               if(i==7)
                 {if(stsv) answer+=count[i];}
               else if(check(s,i,sum))
                 answer+=count[i];
            }
        }
      cout<<answer<<endl;
    }
}
