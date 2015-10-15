/******** matrix type **
int **path;

path=new int[n];
for(int i=0;i<n;i++)
  path[i]=new int[n];
SET(path,0);
for(int i=0;i<n;i++)
  if(parent[i])
    {
      path[parent[i]][i]=1;
      path[i][parent[i]]=1;// delete this if directed
    }
***********************/

/** list type **/
vector<int> path[n];
for(int i=0;i<n;i++)
  if(parent[i])
    {
        path[parent[i]].push_back(i);
        path[i].push_back(parent[i]);// delete this if directed
    }

/** print this ** path from start to upto_here **/
print_path(int ** graph,int start,int upto_here)
{
    if(upto_here==start)
      cout<<upto_here;
    else if(parent[upto_here]==0)
      cout<<"No path from start to 'this'\n";
    else{
        print_path(graph,start,parent[upto_here]);
        cout<<upto_here<<" ";
        }
}
