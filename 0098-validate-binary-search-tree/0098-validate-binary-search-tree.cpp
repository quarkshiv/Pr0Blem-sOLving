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
    bool f(TreeNode* root,long long l,long long r){
          if(root==nullptr){
            return true;
          }
          if(root->val>l && root->val<r){
              return f(root->left,l,root->val) && f(root->right,root->val,r);
          }
          else return false;
    }
    bool isValidBST(TreeNode* root) {
        long long mini=-1e18;
        long long maxi=1e18;
        return f(root,mini,maxi);
    }
};