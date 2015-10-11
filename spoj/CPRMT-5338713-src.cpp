#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
    string a,b;
    ostream_iterator<char> output(cout);
    while(cin>>a)
    {
        int ab_sp[26]={0};
        cin>>b;vector<char> seq;
        int l1=a.length(),l2=b.length();
        if(l1<l2)
        {
            for(int i=0;i<l1;i++)
            {
                int p=b.find(a[i],ab_sp[a[i]-'a']);
                if(p!=string::npos)
                {seq.push_back(a[i]);ab_sp[a[i]-'a']=p+1;}
            }
        }
        else
        {
            for(int i=0;i<l2;i++)
            {
                int p=a.find(b[i],ab_sp[b[i]-'a']);
                if(p!=string::npos)
                {seq.push_back(b[i]);ab_sp[b[i]-'a']=p+1;}
            }
        }
        sort(seq.begin(),seq.end());
        copy(seq.begin(),seq.end(),output);
        cout<<endl;
    }
    return 0;
}
