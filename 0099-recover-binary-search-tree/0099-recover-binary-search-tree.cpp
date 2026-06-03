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
vector<TreeNode*>nodes;
void inorder(TreeNode* root){
    if(!root)return;
    if(root->left)inorder(root->left);
      nodes.push_back(root);
     if(root->right)inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int>vals;
        for(auto it : nodes){
              vals.push_back(it->val);
        }
        sort(vals.begin(),vals.end());
        for(int i=0;i<vals.size();i++){
              nodes[i]->val = vals[i];
        }
    }
};