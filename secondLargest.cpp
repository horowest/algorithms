/*
A O(n + logn - 2) time algorithm to find the 2nd largest num in an array
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, vector<int>> matches;

int find(vector<int>& arr, int p, int q) {
    if(p < q-1) {
        int mid = (p+q)/2;
        int x = find(arr, p, mid);
        int y = find(arr, mid, q);
        // return largest and push the match in hashmap
        if(x > y) {
            matches[x].push_back(y);
            return x;
        }
        else {
            matches[y].push_back(x);
            return y;
        }
    }
    return arr[p];
}


int main() {
    int n, val;
    vector<int> arr;
    // input
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> val;
        arr.push_back(val);
    }
    // solution
    int largest = find(arr, 0, n);
    // for(auto x: matches[largest])
    //     cout << x << " ";
    cout << find(matches[largest], 0, matches[largest].size()) << endl;
}