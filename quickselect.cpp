/*
 * randomised algorithm to find the i-th order statistics
 * of an array of integers.
 */

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void display(vector<int>& arr, int p, int q) {
    for(int i = p; i < q; i++) 
        cout << arr[i] << " ";
    cout << endl;
}


int choosePivot(vector<int>& arr, int p, int q) {
    int l = (rand() % (q - p)) + p;
    swap(arr[l], arr[p]);
    return p;
}


int partition(vector<int>& arr, int p, int q, int l) {
    int i = p + 1;
    for(int j = p+1; j < q; j++) {
        if(arr[j] < arr[l]) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i-1], arr[l]);
    return i-1;
}


int quickselect(vector<int>& arr, int p, int q, int i) {
    if(p == q-1)
        return arr[p];
    int l = choosePivot(arr, p, q);
    int j = partition(arr, p, q, l);
    int k = j - p;          // ref for ith OS update
    if(i == k) 
        return arr[k];
    else if(i < k)
        quickselect(arr, p, j, i);
    else
        quickselect(arr, j+1, q, i-k-1); 
}


int main() {
    int n, val, i;
    vector<int> arr;
    // input
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> val;
        arr.push_back(val);
    }
    cin >> i;
    // solution
    cout << "6th order statistics: " << quickselect(arr, 0, n, i-1) << endl;
}