/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValid = true;
    void checkTree(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr){
            if(q != p) isValid = false;
            return;
        };
        
        if(!isValid) return;

        if(p->val != q->val){
            isValid = false;
            return;
        }


        checkTree(p->left, q->left);
        checkTree(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        checkTree(p, q);
        return isValid;
    }
};