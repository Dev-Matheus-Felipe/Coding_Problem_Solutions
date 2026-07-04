#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    char value;
    
    Node(char value){
        this->value = value;
        this->left = this->right = nullptr;
    }
};

Node* create(char value){
    Node* newValue = new Node(value);
    return newValue;
}

Node* insert(Node* root, char value){
    if(root == nullptr)
        return create(value);

    if(value < root->value)
        root->left = insert(root->left, value);
    
    else
        root->right = insert(root->right, value);

    return root; 
}

void PREFIXA(Node* root, string &txt){
    if(root == nullptr) return;

    txt += root->value;
    txt += " ";

    PREFIXA(root->left, txt);
    PREFIXA(root->right, txt);
}

void POSFIXA(Node* root, string &txt){
    if(root == nullptr) return;

    POSFIXA(root->left, txt);
    POSFIXA(root->right, txt);

    txt += root->value;
    txt += " ";
}

void INFIXA(Node* root, string &txt){
    if(root == nullptr) return;

    INFIXA(root->left, txt);
    txt += root->value;
    txt += " ";
    INFIXA(root->right, txt);   
}

bool search(Node* root, char value){
    if(root == nullptr) return false;
    else if(root->value == value) return true;

    if(value < root->value) return search(root->left, value);
    else return search(root->right, value);
}


int main(){
    string n;
    Node* root = nullptr;

    while(cin >> n){
        string txt;
        char word;
        
        if(n == "I"){
            cin >> word;
            root = insert(root, word); 

        } else if(n == "P"){
            cin >> word;
            cout << word << " ";
            cout << (search(root, word) ? "existe" : "nao existe") << endl;
        
        }else{
            txt = "";
            if(n == "INFIXA")
                INFIXA(root, txt);
            
            else if(n == "PREFIXA")
                PREFIXA(root, txt);
            
            else 
                POSFIXA(root, txt);     
            
            txt.pop_back();
            cout << txt << endl;
        }
    }
    return 0;
}