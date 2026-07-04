#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int value){
        this->left = this->right  = nullptr;
        this->value = value;
    }
};

Node* insert(Node* root, int value){
    if(root == nullptr)
        return new Node(value);

    if(value < root->value)
        root->left = insert(root->left, value);

    else root->right = insert(root->right, value);

    return root;
}

string BFS(Node* root){
    string result = "";

    queue<Node*> pq; 
    pq.push(root);

    while(!pq.empty()){
        Node* top = pq.front();
        pq.pop();

        result += to_string(top->value);
        result += " ";
        
        if(top->left != nullptr) pq.push(top->left);
        if(top->right != nullptr) pq.push(top->right);
    }

    result.pop_back();
    return result;
}

int main(){
    int n;
    cin >> n;

    for(int q = 1; q <= n; q++){
        Node* root = nullptr;

        int amount;
        cin >> amount;

        int newValue;
        for(int i = 0; i < amount; i++){
            cin >> newValue;
            root = insert(root, newValue);
        }

        cout << "Case " << q << ":\n" << BFS(root) << "\n\n";
    }
    
    return 0;
}