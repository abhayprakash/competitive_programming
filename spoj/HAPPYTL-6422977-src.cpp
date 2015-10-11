#include<stdio.h>
//using namespace std;
int main()
{
    int n,m;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    while(n!=0 && m!=0)
    {
        int start[n], end[n],dur;
        for(int i=0;i<n;i++)
        {
            //cin>>dur>>dur>>start[i]>>dur;
            scanf("%d%d%d%d",&dur,&dur,&start[i],&dur);
            end[i]=start[i]+dur;
        }
        for(int j=0;j<m;j++)
        {
            int count=0,s,d;
            //cin>>s>>d;
            scanf("%d%d",&s,&d);
            for(int i=0;i<n;i++)
              if(!((s<=start[i] && s+d<=start[i]) || (s>=end[i] && s+d>=end[i])))
                count++;
            //cout<<count<<endl;
            printf("%d\n",count);
        }
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
    }
}
