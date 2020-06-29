/*
 * randomised quick sort
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


void display(vector<int>& arr) {
    for(int x : arr) 
        cout << x << " ";
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


void quicksort(vector<int>& arr, int p, int q) {
    if(p < q-1) {
        // display(arr);
        int l = choosePivot(arr, p, q);
        int mid = partition(arr, p, q, l);
        quicksort(arr, p, mid);
        quicksort(arr, mid+1, q);
    }
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
    quicksort(arr, 0, n);
    display(arr);
}