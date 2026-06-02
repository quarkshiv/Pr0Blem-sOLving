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
    vector<TreeNode*>pre;
    void preorder(TreeNode* root){
           if(!root)return;
           pre.push_back(root);
           preorder(root->left);
             preorder(root->right);
    }
    void flatten(TreeNode* root) {
        preorder(root);
        for(int i=0;i+1<pre.size();i++){
               pre[i]->left = nullptr;
               pre[i]->right = pre[i+1];
        
        }
    }
};