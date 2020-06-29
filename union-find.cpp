#include<iostream>
#include<vector>
using namespace std;

int set[100], rank_[100];

void create_set(vector<int> arr) {
    for(int i = 1; i <= arr.size(); i++) {
        set[i] = i;
        rank_[i] = 1;
    }
}

int find(int n) {
    while(n != set[n])
        n = set[n];
    return n;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void union_(int a, int b) {
    a = find(a);
    b = find(b);
    if(rank_[a] < rank_[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    rank_[a] += rank_[b];
    set[b] = a;

}

int main() {
    vector<int> arr;

    for(int i = 1; i < 5; i++) {
        arr.push_back(i);
    }
    create_set(arr);
    cout << same(arr[1], arr[2]) << endl;
    union_(arr[1], arr[2]);
    cout << same(arr[1], arr[2]) << endl;
}