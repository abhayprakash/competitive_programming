#include<iostream>
#include<vector>
#include<queue>
#define white 0
#define gray 1
#define black 2
using namespace std;
/******** complete bfs **********/
/****** using nodes number 1 to n ***********/
int bfs(vector<int> *adj,int n,int start, int & farthest)//n is number of nodes in the graph
{//start is the index of the starting node//farthest is the index of the farthest node//adj is actually the graph record
    int color[n+1];//these both constitute a node
    int d[n+1];//above one and this
    queue<int> q;
    q.push(start);

    for(int i=0;i<=n;i++)//initializing
        color[i]=white;

    color[start]=black;
    d[start]=0;
    int count = 0;
    farthest = start;

    while(!q.empty())
    {
        int extracted=q.front();
        q.pop();
        //color[extracted]=black;
        int num_adjacent=adj[extracted].size();
        for(int i=0;i<num_adjacent;i++)
        {
            int adjacent=adj[extracted][i];

            if(color[adjacent]==white)
            {
                q.push(adjacent);
                color[adjacent]=black;//actually can ignore gray and replace it with black only ( thinking : black as gray and the extracted ones are black )
                d[adjacent]=d[extracted]+1;
                count=d[adjacent];
                farthest=adjacent;
            }
        }
    }
  return count;
}
/********** end bfs *************/
int main()
{
    int n,u,v,farthest;
    cin>>n;

    vector<int> adj[10001];
    for(int i=0;i<n-1;i++)
      {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
    bfs(adj,n,1,farthest);
    //cout<<farthest<<"*"<<endl;
    cout<<bfs(adj,n,farthest,farthest);
}
