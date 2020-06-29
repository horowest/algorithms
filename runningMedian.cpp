#include<bits/stdc++.h>
using namespace std;


void addNumber(int num, priority_queue<int>& lower, priority_queue<int, vector<int>, greater<int>>& higher) {
    if(lower.size() == 0 || num < lower.top())
        lower.push(num);
    else 
        higher.push(num);
}


void rebalance(priority_queue<int>& lower, priority_queue<int, vector<int>, greater<int>>& higher) {
    int size_diff = lower.size() - higher.size();
    // rebance the heaps
    if(size_diff < -1) {
        lower.push(higher.top());
        higher.pop();
    }
    else if(size_diff > 1) {
        higher.push(lower.top());
        lower.pop();
    }
}


double getMedian(priority_queue<int>& lower, priority_queue<int, vector<int>, greater<int>>& higher) {
    if(lower.size() == higher.size())
        return ((float) lower.top() + higher.top()) / 2.0;
    else if(lower.size() > higher.size())
        return (float) lower.top();
    else 
        return (float) higher.top();
}


vector<double> runningMedians(vector<int>& arr) {
    vector<double> medians;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

    for(int x: arr) {
        addNumber(x, lower, higher);
        rebalance(lower, higher);
        medians.push_back(getMedian(lower, higher));
    }
    return medians;
}



int main() {
    vector<int> arr;
    int n, a;
    cin >> n;

    while(n--) {
        cin >> a;
        arr.push_back(a);
    }
     cout << std::fixed << std::setprecision(1);
    for(auto x: runningMedians(arr)) {
        cout << x << endl;
    }
}