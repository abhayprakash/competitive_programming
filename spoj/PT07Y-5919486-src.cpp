#include<iostream>
#include<vector>
#include<queue>
#define white 0
#define gray 1
#define black 2
using namespace std;
bool bfs(vector<int> adj[],int n,int start)//n is number of nodes in the graph
{//start is the index of the starting node//farthest is the index of the farthest node//adj is actually the graph record
    int color[n+1];//these both constitute a node
    //int d[n+1];//above one and this
    queue<int> q;
    q.push(start);
	int count=0;
    for(int i=0;i<=n;i++)//initializing
        color[i]=white;

    color[start]=black;

    while(!q.empty())
    {
        int extracted=q.front();
        q.pop();
        color[extracted]=black;
        count++;
        int num_adjacent=adj[extracted].size();
        for(int i=0;i<num_adjacent;i++)
        {
            int adjacent=adj[extracted][i];
            if(color[adjacent]==gray)
              return false;
            if(color[adjacent]==white)
            {
                q.push(adjacent);
                color[adjacent]=gray;//actually can ignore gray and replace it with black only ( thinking : black as gray and the extracted ones are black )
            }
        }
    }
    if(count!=n)
      return false;
  return true;
}
int main()
{
    int num_nodes,edges,u,v;
    cin>>num_nodes>>edges;
    vector<int> adj[num_nodes+1];
    for(int i=0;i<edges;i++)
      {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
    bool ans=true;
    if(num_nodes!=edges+1)
      ans=false;
    else
    {
        ans=bfs(adj,num_nodes,1);
    }
    if(ans==true)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
}

