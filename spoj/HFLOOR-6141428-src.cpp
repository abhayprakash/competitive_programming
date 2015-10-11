#include<iostream>
#include<iomanip>
#define white 1
#define black 2
#define gray 3
#include<queue>
using namespace std;
int matrix[100][100]={0};
int colour[100][100]={0};
int row, col;
void room_visit(int rw,int cl,int& pcount)
{
    if(colour[rw][cl]!=white)
      return;
    colour[rw][cl]=gray;
    if(matrix[rw][cl]==2)
      pcount++;
    if(rw>0)
      room_visit(rw-1,cl,pcount);
    if(rw<row)
      room_visit(rw+1,cl,pcount);
    if(cl>0)
      room_visit(rw,cl-1,pcount);
    if(cl<col)
      room_visit(rw,cl+1,pcount);
    colour[rw][cl]=black;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p=0,r=0;

        cin>>row>>col;
        char ch;
        for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
            {
                cin>>ch;
                if(ch=='#')
                  {matrix[i][j]=0;colour[i][j]=black;}
                else if(ch=='-')
                  {matrix[i][j]=1;colour[i][j]=white;}
                else if(ch=='*')
                  {matrix[i][j]=2;colour[i][j]=white;}
            }
        /************************bfs*************************/
        for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
            {
                if(colour[i][j]==black || colour[i][j]==gray)
                  continue;
                else // white
                  {
                    r++;
                    room_visit(i,j,p);
                  }
            }
        /****************************************************/
        cout<<fixed<<setprecision(2)<<(float)p/(float)r<<endl;
    }
}
