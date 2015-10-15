/*******matrix********way to use it**
*write these lines in main() or ....*

int *value,**graph; //value is the distance from the starting node
    int u; //u is number of nodes
    cout<<"Enter number of nodes: ";
    cin>>u;
    //making matrix
    value=new int[u];
    graph=new int*[u];
    for(int i=0;i<u;i++)
      graph[i]=new int[u];
    make_graph(value,graph,u);

************************************/
#define mg_printlines 0
void make_graph(int *value,int **graph,int & u)/** undirected graph **/
{
    for(int i=0;i<u;i++)//initializing matrix to 0
      for(int j=0;j<u;j++)
        graph[i][j]=0;
    #if mg_printlines
    cout<<"enter adjacent vertices pair (u,v): u is pointing v,-1 to exit\n";
    #endif
    while(1)
    {
        int n,m;
        cin>>n;
        if(n==-1)
          break;
        cin>>m;
        graph[n][m]=1;//directed u to v
        graph[m][n]=1;/** delete this for directed **/
    }
    #if mg_printlines
    cout<<"The matrix formed is:\n";

    for(int i=0;i<u;i++)//initializing matrix to 0
      {
       for(int j=0;j<u;j++)
        cout<<graph[i][j]<<" ";
       cout<<endl;
      }
    #endif
}
