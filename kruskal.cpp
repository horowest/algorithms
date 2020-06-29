#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> kruskal(vector<tuple<int,int,int>> edges) {

}

int main() {
    int n, m, a, b, w;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    while(m--) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    vector<tuple<int,int,int>> mst = kruskal(int n, edges);
    // for(auto edge: mst) 
    //     cout << edge.
}