/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   vector<int>v1;
   vector<int>v2;
      bool f(TreeNode* root, TreeNode* p,vector<int>&v){
          if(!root){
            return false;
          }
          v.push_back(root->val);
          if(root==p){
            return true;
          }
          if(f(root->left,p,v)|| f(root->right,p,v)) return true;
          v.pop_back();
          return false;
      }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        f(root,p,v1);
        f(root,q,v2);
        int i=0;
        while(i<v1.size() && i<v2.size() &&v1[i]==v2[i]){
            i++;
        }
        return new TreeNode(v1[i-1]);
    }
};