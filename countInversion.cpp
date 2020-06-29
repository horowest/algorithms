#include<iostream>
#include<vector>
using namespace std;


int countSplit(vector<int>& arr, int p, int mid, int q) {
    vector<int> B, C;
    int i, j, k, count  = 0;

    // split arr into B and C
    for(i = p; i < mid; i++) 
        B.push_back(arr[i]);
    for(j = mid; j < q; j++) 
        C.push_back(arr[j]);

    // merge and count
    i = j = 0, k = p;
    while(i < B.size() && j < C.size()) {
        if(B[i] <= C[j]) {
            arr[k++] = B[i++];
        }
        else {
            arr[k++] = C[j++];
            count += B.size() - i;
        }
    }
    // edge cases
    while(i < B.size())
        arr[k++] = B[i++];

    while( j < C.size()) 
        arr[k++] = C[j++];

    return count;
}


int countInversion(vector<int>& arr, int p, int q) {
    if(p < q-1) {
        int mid = (p+q)/2;
        int x = countInversion(arr, p, mid);
        int y = countInversion(arr, mid, q);
        int z = countSplit(arr, p, mid, q);
        return x + y + z;
    }
    else return 0;
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
    cout << countInversion(arr, 0, n) << endl;
}