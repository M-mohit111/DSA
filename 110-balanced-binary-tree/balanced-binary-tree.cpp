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
    int check(TreeNode*root){
        if(root == nullptr){
            return 0;
        }
        int a = check(root->left);
        if(a==-1){
            return -1;
        }
        
        int b = check(root->right);
        if(b==-1){
            return -1;
        }

        if(abs(a-b)>1)return -1;
        return max(a,b)+1;
    }

    bool isBalanced(TreeNode* root) {
        int a = check(root);
        if(a == -1){
            return false;
        }
        else{return true;}
    }
};