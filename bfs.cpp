#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// adjacency list repr of graph
vector<int> adj[10000]; 
bool visited[10000];
int parent[10000];


void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}


void print_path(int s, int d) {
    if(s == d) 
        cout <<  s << " ";
    else if(parent[d] == 0)
        cout << "no path";
    else {
        print_path(s, parent[d]);
        cout << d << " ";
    }
}

int main() {
    int n, m;       
    // n vertices and m edges
    cin >> n >> m; 

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    print_path(1, 7);
    cout << endl;
}