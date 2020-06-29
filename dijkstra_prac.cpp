#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[10001];
bool visited[10001];
int parent[10001];
int dist[10001];

void dijkstra(int s, int n) {
    // init
    for(int i = 1; i <= n; i++) {
        dist[i] = INFINITY;
        parent[i] = 0;
    }

    // min heap {dist, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if(visited[u]) continue;
        visited[u] = true;

        for(auto x: adj[u]) {
            int v = x.first, w = x.second;
            // relax
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                q.push({dist[v], v});
            }
        }
    }
    
}

void print_path(int s, int d) {
    if(s == d) 
        cout << s;
    else if(parent[d] == 0)
        cout << "no path";
    else {
        print_path(s, parent[d]);
        cout << "->" << d;
    }
}


int main() {
    int n, m, a, b, w;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    // solve
    int s;
    cin >> s;
    dijkstra(s, n);

    // while(a > 0) {
    //     cout << "print path (s d): ";
    //     cin >> a >> b;
    //     print_path(a, b);
    //     cout << endl;
    // }

    for(int i = 1; i <= n; i++) 
        cout << i << ": " << dist[i] << endl;    
}