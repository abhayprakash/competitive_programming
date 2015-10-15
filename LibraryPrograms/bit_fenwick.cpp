/**incomplete
refer topcoder tutorial
**/

#include<iostream>
using namespace std;
int main()
{
    int id = 1024524;
    while(id > 0)
    {
        id -= (id & -id);
        cout<<id<<endl;
    }
}
