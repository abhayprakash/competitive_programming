#include <iostream>
using namespace std;
int integer(unsigned long int factorialnumber )
{
	unsigned zero_count = 0;
	for(unsigned five_factor=5;five_factor<=factorialnumber;five_factor*=5)
	{
		zero_count += factorialnumber/five_factor;
	}
	return (zero_count);
}
int main()
{
    int t;
    cin>>t;
    int n[t];
    for (int i=0;i<t;i++)
    {
        cin>>n[i];
        }
    for(int i=0;i<t;i++)
    {
            cout<<integer(n[i])<<endl;
            }
    return 0;
}
