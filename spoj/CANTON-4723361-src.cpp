#include<iostream>
using namespace std;
int movedown(int&,int&,int&,int);
int moveup(int& row,int& column,int& counter,int n)
{
    while(row>0&&counter<n)
    {
     if(row!=1)
     {
                row--;
                column++;
                counter++;
                if(counter==n)
                break;
                }
     else
     {   column++;
         counter++;
         if(counter==n)
         return 0;
         else
         movedown(row,column,counter,n);
                }
                }

return 0;
}
int movedown(int& row,int& column,int& counter,int n)
{
    while(column>0&&counter<n)
    {
     if(column!=1)
     {
                row++;
                column--;
                counter++;
                if(counter==n)
                break;}
     else if(column==1)
     {row++;
     counter++;
     if(counter==n)
     return 0;
     else
     moveup(row,column,counter,n);
                }
     }
return 0;
}
int main()
{
    int t,row=1,column=1,counter=0;
    cin>>t;
    int n[t];
    for(int i=0;i<t;i++)
    {
            cin>>n[i];
            n[i]--;
            }
    for(int i=0;i<t;i++)
    {
            row=1;column=1;counter=0;
    moveup(row,column,counter,n[i]);
    cout<<"TERM "<<n[i]+1<<" IS "<<row<<"/"<<column<<endl;
    }
    return 0;
}
        
