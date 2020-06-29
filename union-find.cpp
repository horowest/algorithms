#include<iostream>
#include<vector>
using namespace std;

int parent[10000];
int rank_[10000];

void create_set(vector<int>& arr, int n) {
    for(int x: arr) {
        parent[x] = x;
        rank_[x] = 0;
    }
}

int find(int x) {
    while(x != parent[x])
        x = parent[x];
    return x;
}

bool same(int x, int y) {
    int s1 = find(x), s2 = find(y);
    return s1 == s2;
}

void union_(int x, int y) {
    int s1 = find(x), s2 = find(y);

    if(rank_[s1] > rank_[s2]) {
        parent[s2] = s1;
    }
    else {
        parent[s1] = s2;
        if(rank_[s1] == rank_[s2])
            rank_[s2] += 1;
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> arr;
    for(int i = 1; i <= n; i++)
        arr.push_back(i);
    create_set(arr, n);

    // union
    while(m--) {
        cin >> a >> b;
        if(!same(a, b))
            union_(a, b);
    }
    for(int x: arr) 
        cout << x << ": " << find(x) << " rnk(" << rank_[x] << ")" << endl;
}