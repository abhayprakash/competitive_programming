#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    string words[50];
    string s;
    getline(cin,s);
    while(s!="*")
    {
        istringstream sin(s);
        int i=0;
        while(sin>>words[i])
          i++;
        //cout<<i<<endl;
        bool ans=true;
        for(int j=1;j<i;j++)
          {
              //cout<<words[0][0]<<"*\n";
              if(words[j][0]==words[j-1][0])
                {
                    continue;
                }
              else if(words[j][0]==words[j-1][0]-32)
                {
                    continue;
                }
                else if(words[j][0]-32==words[j-1][0])
                {
                    continue;
                }
                else{ans=false;
                    break;}
          }
        if(ans==true)
          cout<<"Y"<<endl;
        else
          cout<<"N"<<endl;
        getline(cin,s);
    }
}
