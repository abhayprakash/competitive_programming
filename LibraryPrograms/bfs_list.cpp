/**bfs_list*********************
adj[]      : the list of graph
start      : starting node
n          : number of nodes in graph
d          : is the array having distance from starting node : inside this function BE CAREFUL
parent     : is the aray of parent of ith element by bfs traversal
Aleternate : define n(or if possible d and parent) above and pass d and parent by reference
********************************/
#define bl_printlines 1
void bfs(vector<int> adj[],int start,int n)
{
    int color[n];//these both constitute a node
    int d[n];//above one and this
    int parent[n]={0};
    SET(d,100000);//infinity set
    queue<int> q;
    q.push(start);

    #define white 0
    #define gray 1
    #define black 2

    for(int i=0;i<n;i++)
        color[i]=white;

    color[start]=gray;
    d[start]=0;
    #if bl_printlines
    cout<<"Printing according to bfs traversal: ";
    #endif
    while(!q.empty())
    {
        int extracted=q.front();
        q.pop();
        int num_adj=adj[extracted].size();
        for(int i=0;i<num_adj;i++)
        {
            int adjacent=adj[extracted][i];
            if(color[adjacent]==white)
            {
                color[adjacent]=gray;
                d[adjacent]=d[extracted]+1;
                parent[adjacent]=extracted;
                q.push(adjacent);
            }
        }
        color[extracted]=black;
    }
    #if bl_printlines
    cout<<"\nDistance from starting node are:\n";
    for(int i=0;i<n;i++)
     cout<<" node "<<i<<": "<<d[i]<<endl;
    #endif
}
