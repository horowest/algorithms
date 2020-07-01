#include<bits/stdc++.h>
using namespace std;

struct Node {
    /*
        Nodes for huffman tree
    */
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
    
    // for testing purpose
    friend ostream& operator<<(ostream& out, const Node *n) {
        out << n->data;
        return out;
    }
};

struct compare {
    // custom compare opeator for heap
    bool operator() (Node *left, Node *right) {
        return left->freq > right->freq;
    }
};

void encode(Node* root, string str) {
    /*
        traverse the tree and print codes for each character
    */
    if(!root)
        return;
    if(root->data != '*')
        cout << root->data << ": " << str << endl;

    encode(root->left, str + "0");
    encode(root->right, str + "1");
}

void Huffman(vector<char>& data, vector<int>& freq) {
    /* 
    *    Build the huffman tree for a give array for char s
    */
    Node *left, *right, *root;
    priority_queue<Node*, vector<Node*>, compare> heap;

    for(int i = 0; i < data.size(); i++) {
        heap.push(new Node(data[i], freq[i]));
    }
    while(heap.size() > 1) {
        left = heap.top(); heap.pop();
        right = heap.top(); heap.pop();
        root = new Node('*', left->freq + right->freq);
        root->left = left;
        root->right = right;
        heap.push(root);
    }
    encode(heap.top(), "");
}

int main() {
    vector<char> data;
    vector<int> freq;
    int n, f;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        data.push_back(c);
    }

    for(int i = 0; i < n; i++) {
        cin >> f;
        freq.push_back(f);
    }

    Huffman(data, freq);
}