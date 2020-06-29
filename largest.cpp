#include<iostream>
#include<vector>
using namespace std;


int find(vector<int>& arr, int p, int q) {
    if(p < q-1) {
        int mid = (p+q)/2;
        int x = find(arr, p, mid);
        int y = find(arr, mid, q);
        // return largest
        return x > y ? x : y;
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
    cout << find(arr, 0, n) << endl;
}