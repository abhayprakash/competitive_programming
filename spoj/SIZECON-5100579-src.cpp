#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int t;
    cin>>t;
    int sum;
    sum=0;
    int n;
    int i;
    i=0;
    //for(int i=0;i<t;i++)
    /*{
        cin>>n;//taking input
        if(n>0)//checking the no. is positive or not
        sum=sum+n;//adding the positive no. in the sum
        //i=i+1;//this line required in while loop only
    }*/
    while(i<t)
    {
        cin>>n;
        if(n>0)
        sum=sum+n;
        i=i+1;
    }
    cout<<sum<<endl;
    return 0;
}


