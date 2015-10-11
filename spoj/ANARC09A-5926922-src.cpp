#include<iostream>

using namespace std;
int main()
{
    string s;
    cin>>s;
    int t=1;
    while(s[0]!='-')
    {
        int count=0,chk=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='{')
              chk++;
            else if(s[i]=='}')
              chk--;
            if(chk<0)
            {
                count++;
                chk=1;
            }
        }
        count+=chk/2;
        cout<<t++<<". "<<count<<endl;
        cin>>s;
    }
}
