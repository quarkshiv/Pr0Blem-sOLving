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
  int getheight(TreeNode* root){
      if(!root){
        return 0;
      }
      int lh = getheight(root->left);
      int rh = getheight(root->right);
      return max(lh,rh)+1;
  }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int lh= getheight(root->left);
        int rh = getheight(root->right);
        return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
    }
};