#include<iostream>
#include<vector>
using namespace std;


// adjacency list repr of graph
vector<int> arr[10000]; 
bool visited[10000];
int parent[10000];


void dfs(int i) {
    visited[i] = true;

    for(auto x: arr[i]) {
        if(!visited[x]) { 
            parent[x] = i;
            dfs(x);
        }
    }
}


void dfs_loop(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dfs(i);
    }
}


void print_path(int s, int d) {
    if(s == d) 
        cout <<  s << " ";
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
        arr[a].push_back(b);
    }
    dfs_loop(n);
    print_path(1, 7);
    cout << endl;
}