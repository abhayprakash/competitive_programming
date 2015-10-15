/**bfs_matrix** gives shortest distance from start node**
value : actual REQUIRED distance
graph : matrix
n     : number of nodes
start : starting node
parent: parent of node with traversed path
********************************************************/
#define bs_printlines 1
void bfs_shortest(int *value,int * parent,int**graph,int n,int start = 0)
{
    int color[n];
    for(int i=0;i<n;i++)
      color[i]=0;
    SET(parent,0);
    #define white 0
    #define gray 1
    #define black 2

    queue<int> q;
    q.push(start);
    SET(value,100000);//infinity
    value[start]=0;
    #if bs_printlines
    cout<<"printing traversal according to BFS: ";
    #endif
    while(!q.empty())
    {
        for(int i=0;i<n;i++)
         {
             if((graph[q.front()][i]==1) && (color[i]==white))
               {//cout<<"here";
                   q.push(i);
                   color[i]=gray;
                   value[i]=value[q.front()]+1;
                   parent[i]=q.front();
               }
         }
      color[q.front()]=black;
      #if bs_printlines
      cout<<q.front()<<" ";
      #endif
      q.pop();
    }
    #if bs_printlines
    cout<<endl;
    #endif
}
