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

string preT = "", ordemT = "", posT = "";

Node* insert(Node* root, int value){
    if(root == nullptr)
        return new Node(value);

    if(value < root->value) {
        root->left = insert(root->left, value);
    
    }else {
        root->right = insert(root->right, value);
    }

    return root;
}

void pre(Node* root){
    if(root == nullptr)
        return;

    preT += to_string(root->value);
    preT += " ";

    pre(root->left);
    pre(root->right);
}

void ordem(Node* root){
    if(root == nullptr)
        return;

        
    ordem(root->left);

    ordemT += to_string(root->value);
    ordemT += " ";

    ordem(root->right);
}

void pos(Node* root){
    if(root == nullptr)
        return;

        
    pos(root->left);
    pos(root->right);

    posT += to_string(root->value);
    posT += " ";
    }

int main() {
    int n, amount;
    cin >> n;

    
    for(int i = 1; i <= n; i++){
        Node* root = nullptr;
        cin >> amount;

        preT = ""; ordemT = ""; posT = "";

        int v;
        for(int i = 0; i < amount; i++){
            cin >> v;
            root = insert(root,v);
        }

        pre(root);
        ordem(root);
        pos(root);
        printf("Case %d:\n", i);

        preT.pop_back(); ordemT.pop_back(); posT.pop_back();

        cout << "Pre.: " << preT << endl
        << "In..: " << ordemT << endl 
        << "Post: " << posT << "\n\n";

    }
    return 0;
}