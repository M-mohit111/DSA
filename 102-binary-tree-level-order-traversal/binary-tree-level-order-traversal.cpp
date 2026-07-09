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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if (root == nullptr) {
            return v; 
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int l = q.size();
            for(int i =0 ;i<l;i++){
                TreeNode* a = q.front();
                q.pop();
                temp.push_back(a->val);            
                if(a->left!=nullptr){
                    q.push(a->left);
                }
                if(a->right!=nullptr){
                    q.push(a->right);
                }
                
            }
            v.push_back(temp);
        }
        return v;
    }
};