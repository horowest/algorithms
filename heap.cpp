#include<iostream>
#include<vector>
using namespace std;


class heap {
    int size;
    vector<int> arr;
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    public:
        heap():size(0){};
        int top() { return arr[0]; }
        void push(int);
        void pop(int);
        bool empty() { return size == 0; }
};


void heap::push(int n) {
    if(this->empty()) {
        arr.push_back(n);
    }
    else {
        arr.push_back(n);
        int iter = size;

        while(iter > 0) {
            if(arr[iter] < arr[iter/2]) {
                this->swap(arr[iter], arr[iter/2]);
                iter = iter/2;
            }
            else
                break;
        }
    }
    size++;
}


void heap::pop(int n=0) {
    arr[0] = arr[--size];
    arr.pop_back();
    int pos = 0;

    while(true) {
        int left = 2*pos + 1, right = left + 1;
        if(left <= size) {
            if(right <= size) {
                if(arr[pos] > arr[left] || arr[pos] > arr[right]) {
                    int index = arr[left] < arr[right] ? left : right;
                    this->swap(arr[pos], arr[index]);
                    pos = index;
                }
                else 
                    break;
            }
            else {
                if(arr[pos] > arr[left]) {
                        this->swap(arr[pos], arr[left]);
                        pos = left;
                } 
                else 
                    break;       
            }
        }
        else 
            break;
    }
}


int main() {
    heap hp;
    int n, a, val;
    cin >> n;

    while(n--) {
        cin >> a;
        
        if(a == 1) {
            cin >> val;
            hp.push(val);
        }
        else 
            cout << hp.top() << endl;
    }
}