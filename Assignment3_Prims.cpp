#include <bits/stdc++.h>
using namespace std;

// STP:  It calculates a loop-free, minimum-cost spanning tree, enabling redundancy without causing broadcast storms.
void primsAlgo(vector<vector<pair<int, int>>> adjList, int start)
{
    //{weight, {to, parent}}
    priority_queue<
        pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
        pq;
    int V = adjList.size();
    vector<vector<pair<int, int>>> MST(V);
    vector<bool> vis(V, false);

    pq.push({-1, {0, start}}); // weight node
    vis[start] = true;
    while (!pq.empty())
    {
        // cout << "\ninside while";
        auto top = pq.top();
        pq.pop();
        int w = top.first;
        int node = top.second.first;
        int parent = top.second.second;

        if ((!(w == -1)) && vis[node] == false)
        {
            MST[parent].push_back({node, w});
            vis[node] = true;
        }
        for (auto &p : adjList[node])
        {
            int n = p.first;
            int wei = p.second;

            if (!vis[n])
            {
                pq.push({wei, {n, node}});
            }
        }
    }

    cout << "\nOP: \n";
    for (int i = 0; i < MST.size(); i++)
    {
        for (auto &p : MST[i])
        {
            int n = p.first;
            int w = p.second;

            cout << "\n " << i << "---" << w << "--> " << n;
        }
    }
    cout<<"\n";
}
int main()
{
    int totalVertex;

    cout << "\nEnter total devices in the network :  ";
    cin >> totalVertex;
    vector<vector<pair<int, int>>> adjList(totalVertex);
    for (int i = 0; i < totalVertex; i++)
    {
        int totalCables;
        cout << "\nEnter total cables from " << i << "(if no cables then enter -1):";
        cin >> totalCables;
        while (totalCables > 0)
        {
            int device, cost;
            cout << "\nEnter cables and there costs for device " << i<< " :";
            cout << "\nTo device: ";
            cin >> device;
            cout << "Cost: ";
            cin >> cost;
            adjList[i].push_back({device, cost});
            adjList[device].push_back({i,cost});
            totalCables--;
        }
    }
    //  = {
    //     {{1,4}, {7,8}},                     // 0
    //     {{0,4}, {2,8}, {7,11}},              // 1
    //     {{1,8}, {3,7}, {8,2}, {5,4}},        // 2
    //     {{2,7}, {4,9}, {5,14}},              // 3
    //     {{3,9}, {5,10}},                     // 4
    //     {{2,4}, {3,14}, {4,10}, {6,2}},      // 5
    //     {{5,2}, {7,1}, {8,6}},               // 6
    //     {{0,8}, {1,11}, {6,1}, {8,7}},       // 7
    //     {{2,2}, {6,6}, {7,7}}                // 8
    // };
    int start = 0;
    cout<<"\nEnter starting node for STP protocol: ";
    cin>>start;
    
    primsAlgo(adjList, start);
    return 0;
}
