#include<iostream>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#define len 10
using namespace std;

struct page{
    string s;
    int value;
};
bool myfn(page i, page j)
{
    return i.value>j.value;
}
int main()
{
    int t,i=1;
    scanf("%d\n",&t);
    //fflush(stdin);
    while(t--)
    {
	printf("Case #%d:\n",i++);
        page site[len];
        int p=len,i=0;
        while(p--)
        {
            string s;
            
            getline(cin,s);
            istringstream inp(s);
            inp>>site[i].s>>site[i].value;
            i++;
        }
        sort(site,site+len,myfn);
        int index=0;
        while(site[index].value==site[0].value)
          {
              cout<<site[index].s<<endl;
              index++;
          }
    }
}