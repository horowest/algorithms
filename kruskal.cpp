#include<bits/stdc++.h>
using namespace std;

class disjoint_set {
    int parent[10000];
    int rank_[10000];

    public:
        disjoint_set(int n) {
            create_set(n);
        }

        void create_set(int n) {
            for(int x=1; x <= n; x++) {
                parent[x] = x;
                rank_[x] = 0;
            }
        }

        int find(int x) {
            vector<int> nodes;
            // parent lookup
            while(x != parent[x]) {
                nodes.push_back(x);
                x = parent[x];
            }
            // path compression
            for(int node: nodes) 
                parent[node] = x;
            return x;
        }

        bool same(int x, int y) {
            int s1 = find(x), s2 = find(y);
            return s1 == s2;
        }

        void union_(int x, int y) {
            int s1 = find(x), s2 = find(y);
            // find the deeper subtree
            if(rank_[s1] > rank_[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s1] = s2;
                if(rank_[s1] == rank_[s2])
                    rank_[s2] += 1;
            }
        }
};

int kruskal(int n, vector<pair<int,pair<int,int>>>& edges) {
    int mst = 0;
    // make set
    disjoint_set ds(n);
    // sort edges in decreasing order
    sort(edges.begin(), edges.end());

    for(auto edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        if(!ds.same(u, v)) {
            // cout << u << " - " << v << endl;
            ds.union_(u, v);
            mst += w;
        }
    }
    return mst;
}

int main() {
    int n, m, a, b, w;
    cin >> n >> m;

    vector<pair<int,pair<int,int>>> edges;

    while(m--) {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    // solve
    int mst = kruskal(n, edges);
    // cout << "mst weight: " << mst << endl;
    cout << mst << endl;
}