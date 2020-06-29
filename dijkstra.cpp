#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

void dijkstra(int s, vector<pair<int,int>> adj[], vector<int>& distance, vector<bool>& visited, int n) {
    // init
    for(int i = 1; i <= n; i++)
        distance[i] = INF;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    distance[s] = 0;

    while(!q.empty()) {
        int u = q.top().second; q.pop();
        if(visited[u]) continue;
        visited[u] = true;

        for(auto x: adj[u]) {
            int v = x.first, w = x.second;
            // relax
            if(distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                q.push({distance[v], v});
            }
        }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {

        int n, m, a, b, w, s;
        cin >> n >> m;

        vector<pair<int,int>> adj[n+1];
        vector<int> distance(n+1);
        vector<bool> visisted(n+1);

        while(m--) {
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        // solve
        // cout << "source: ";
        cin >> s;
        dijkstra(s, adj, distance, visisted, n);

        for(int i = 1; i <= n; i++) {
            if(s == i) continue;
            if(distance[i] == INF)
                cout << "-1 ";
            else 
                cout << distance[i] << " ";
        }
        cout << endl;
    }
} 
