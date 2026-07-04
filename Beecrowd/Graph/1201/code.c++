#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    
    Node(int value){
        this->value = value;
        this->left = this->right = nullptr;
    }
};

Node* create(int value){
    Node* newValue = new Node(value);
    return newValue;
}

Node* insert(Node* root, int value){
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

    txt += to_string(root->value);
    txt += " ";

    PREFIXA(root->left, txt);
    PREFIXA(root->right, txt);
}

void POSFIXA(Node* root, string &txt){
    if(root == nullptr) return;

    POSFIXA(root->left, txt);
    POSFIXA(root->right, txt);

    txt += to_string(root->value);
    txt += " ";
}

void INFIXA(Node* root, string &txt){
    if(root == nullptr) return;

    INFIXA(root->left, txt);
    txt += to_string(root->value);
    txt += " ";
    INFIXA(root->right, txt);   
}

bool search(Node* root, int value){
    if(root == nullptr) return false;
    else if(root->value == value) return true;

    if(value < root->value) return search(root->left, value);
    else return search(root->right, value);
}

Node* remove(Node* root, int value){
    if(root == nullptr)
        return nullptr;

    if(value < root->value) root->left = remove(root->left, value);
    else if(value > root->value) root->right = remove(root->right, value);

    else {
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        
        }else if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        
        }else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        
        }else {
            Node* temp = root->left;
            while(temp && temp->right != nullptr) temp = temp->right;

            root->value = temp->value;
            root->left = remove(root->left, temp->value);
        }
    }

    return root;
}


int main(){
    string n;
    Node* root = nullptr;

    while(cin >> n){
        string txt;
        int word;
        
        if(n == "I"){
            cin >> word;
            root = insert(root, word); 

        } else if(n == "P"){
            cin >> word;
            cout << word << " ";
            cout << (search(root, word) ? "existe" : "nao existe") << endl;
        
        }else if(n == "R"){
            cin >> word;
            root = remove(root, word);

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