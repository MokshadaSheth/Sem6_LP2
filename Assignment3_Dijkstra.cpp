#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(vector<vector<pair<int,int>>> adjList, int src)
{
    int V= adjList.size();
    //Min-heap priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int>dist(V, INT_MAX);

    pq.push({src,0});
    dist[src] = 0;
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();
        int toNodeDist = top.first;  // 0
        int node = top.second;      // 0

        if(toNodeDist > dist[node]) continue;  //0>0

        for(auto &neigh : adjList[node])
        {
            int n = neigh.first;  //1
            int w = neigh.second;  //4
            cout<<"n: "<<n<<" w:"<<w<<endl;
            if(dist[node]+w < dist[n])  //0+4 < infi
            {
                cout<<"\ninside if  dist[node]:"<<dist[node]<<endl;
                dist[n] = dist[node]+w;
                pq.push({dist[n], n});
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<pair<int,int>>> adjList{{{1,4},{2,8}},{{0,4},{4,6}},{{0,8},{3,2}},{{2,2},{4,10}},{{1,6},{3,10}}};
   int start = 0;
   vector<int> ans;
   ans = dijkstraAlgo(adjList,start);
   for(int i=0; i<ans.size(); i++)
   {
    cout<<" "<<ans[i];
   }
}