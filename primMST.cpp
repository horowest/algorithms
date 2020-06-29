#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

vector<pair<int,int>> prim_mst(int s, vector<pair<int,int>> adj[], int n) {
    vector<pair<int,int>> mst;
    vector<int> distance(n+1, INF), parent(n+1, NULL), visited(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // init
    distance[s] = 0;

    // heapify
    for(int i = 1; i <= n; i++) 
        pq.push({distance[i], i});

    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        // if(parent[u] != NULL)  {
        //     mst.push_back({parent[u], u});
        //     visited[u] = true;
        //     cout << "visited: " << u << endl;
        // }
        visited[u] = true;

        for(auto x: adj[u]) {
            int v = x.second, w = x.first;

            if(!visited[v] && w < distance[v]) {
                parent[v] = u;
                distance[v] = w;
                pq.push({distance[v], v});
            }
        }
    }
    for(int i = 2; i <= n; i++)
        mst.push_back({parent[i], i});
    return mst;
}


int main() {
    int n, m, a, b, w;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    while (m--) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    // solve
    int s;
    cin >> s;
    vector<pair<int,int>> mst = prim_mst(s, adj, n);

    for(auto x: mst) {
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }    
}