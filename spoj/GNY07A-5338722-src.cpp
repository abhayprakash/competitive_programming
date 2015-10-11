#include<iostream>
using namespace std;
int main()
{
    int n,i=1;
    cin>>n;
    while(n--)
    {
        int p;string word;
        cin>>p>>word;
        word=word.substr(0,p-1)+word.substr(p,word.length()-p);
        cout<<i++<<" "<<word<<endl;
    }
}
