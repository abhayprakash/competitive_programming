/*****undirected****list******

copy paste this in main, graph is made in main

***************************/

int n,u,v;
    cout<<"Enter no. of vertices:";
    cin>>n;
    vector<int> adj[n];
    cout<<"Enter u,v -1 to end:\n";
    while(1)
    {
        cin>>u;
        if(u==-1)
          break;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);/** delete this for directed **/
    }
