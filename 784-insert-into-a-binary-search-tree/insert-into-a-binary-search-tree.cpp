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

    void find(TreeNode* root,int val){
        if(root == nullptr){
            return;
        }
        int a = root->val;
        if(a>val){
            if(!root->left){
                root->left = new TreeNode(val);
            }
            else{
                return find(root->left,val);
            }
        }
        if(a<val){
            if(!root->right){
                root->right = new TreeNode(val);
            }
            else{
                return find(root->right,val);
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * temp = root;
        if(!root){
            return new TreeNode(val);
        }
        find(temp,val);
        return temp;
    }
};