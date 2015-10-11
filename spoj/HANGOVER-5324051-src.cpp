#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
int main()
{
    string input;
    getline(cin,input);
    while(input!="0.00")
    {
      float data;
      istringstream inputstring(input);
      inputstring>>data;
      float l=0;
      int n=0;
      while(l<data)
      l+=1.0/((float)(++n)+1.0);
      cout<<n<<" card(s)"<<endl;
      getline(cin,input);
    }
    return 0;
}
