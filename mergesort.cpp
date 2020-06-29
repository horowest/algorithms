#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int p, int mid, int q) {
    vector<int> B, C;
    int i, j, k;

    for(i = p; i < mid; i++) 
        B.push_back(arr[i]);
    for(j = mid; j < q; j++) 
        C.push_back(arr[j]);

    // merge
    i = j = 0, k = p;
    while(i < B.size() && j < C.size()) {
        if(B[i] < C[j]) {
            arr[k++] = B[i++];
        }
        else {
            arr[k++] = C[j++];
        }
    }
    // edge cases
    while(i < B.size()) {
        arr[k++] = B[i++];
    }
    while( j < C.size()) {
        arr[k++] = C[j++];
    }
}

void mergesort(vector<int>& arr, int p, int q) {
    if(p < q-1) {
        int mid = (p+q)/2;
        mergesort(arr, p, mid);
        mergesort(arr, mid, q);
        merge(arr, p, mid, q);
    }
}

void display(vector<int>& arr) {
    for(int x : arr) 
        cout << x << " ";
    cout << endl;
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
    mergesort(arr, 0, n);
    display(arr);
}