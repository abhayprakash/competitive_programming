map<int, map<int, int> > edgeWeight;
typedef pair<int,int> ii;

int n, m, u, v;

int searchPath()
{
    set<ii> Q;
    vector<int> dist(n+11, 100011);

    dist[1] = 0;
    Q.insert(ii(0, 1));

    fr(i,2,n+1)
        Q.insert(ii(100011, i));

    while(!Q.empty())
    {
        ii curr = *Q.begin();
        int prevDist = curr.first;
        int currNode = curr.second;
        /*if(currNode == n)
        {
            return prevDist;
        }*/
        Q.erase(curr);

        map<int, int>::iterator it = edgeWeight[currNode].begin();

        for(; it != edgeWeight[currNode].end(); ++it)
        {
            int childNode = it->first;
            int weight = it->second;
            if(dist[childNode] > prevDist + weight)
            {
                Q.erase(Q.find(make_pair(dist[childNode], childNode)));
                dist[childNode] = prevDist + weight;
                Q.insert(ii(dist[childNode], childNode));
            }
        }
    }
    return dist[n];
}
