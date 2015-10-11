#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    while(n!=0&&p!=0&&m!=0){
    priority_queue<int> set;
    set.push(n);
    set.push(m);
    set.push(p);
    long long int c=set.top();
    set.pop();
    long long int a=set.top();
    set.pop();
    long long int b=set.top();
    set.pop();
    if(c*c==a*a+b*b)
      cout<<"right\n";
    else cout<<"wrong\n";
    cin>>n>>m>>p;
    }
}
