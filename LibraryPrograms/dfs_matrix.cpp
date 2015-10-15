/** matrix type **
graph   : matrix of graph // input
n       : number of nodes // input
parent  : parent of each node by this travesal
d[]     : first time node visited
f[]     : second time node visited
*****************/
#define white 0
#define gray 1
#define black 2

DFS_VISIT(int ** graph,int n,int u,int & time,int parent[],int d[],int f[])
{
    time+=1;

    d[u]=time;
    color[u]=gray;
    for(int i=0;i<n;i++)
      if(graph[u][i]==1) // 1 has been written in place of white : 9 july 2013
        {
            parent[i]=u;
            DFS_VISIT(graph,n,i,time,parent,d);
        }
    color[u]=black;
    time+=1;
    f[u]=time;
}
void DFS(int ** graph,int n,int d[],int f[],int parent[])
{
    int color[n];
    SET(color,0);
    SET(parent,0);
    SET(d,0);
    SET(f,0);
    int time=0;
    for(int i=0;i<n;i++)
      if(color[i]==white)
        {
            DFS_VISIT(graph,n,i,time,parent,d,f);
        }
}
