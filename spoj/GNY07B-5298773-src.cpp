#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
int main()
{
    long double kg_to_lb=2.2046;
    long double lb_to_kg=0.4536;
    long double l_to_g=0.2642;
    long double g_to_l=3.7854;
    //long double result;
    int t;
    cin>>t;
    t++;
    int count=1;
    while(t--)
    {
        cout<<setprecision(4)<<fixed;
        string input;
        getline(cin,input);
        string unit;
        long double data;
        istringstream inputstring(input);
        inputstring>>data>>unit;
        if(unit=="l")
        cout<<count++<<" "<<data*l_to_g<<" g"<<endl;
        else if(unit=="g")
        cout<<count++<<" "<<data*g_to_l<<" l"<<endl;
        if(unit=="kg")
        cout<<count++<<" "<<data*kg_to_lb<<" lb"<<endl;
        if(unit=="lb")
        cout<<count++<<" "<<data*lb_to_kg<<" kg"<<endl;
    }
    return 0;
}
