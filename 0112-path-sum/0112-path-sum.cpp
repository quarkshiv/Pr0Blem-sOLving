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
   bool check(TreeNode* root, int target){
    if(!root)return false;
         if(!root->left && !root->right)return root->val==target;
          return check(root->left,target-root->val) || check(root->right,target-root->val);
   }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return check(root,targetSum);
    }
};