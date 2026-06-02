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
     bool f(TreeNode* root, TreeNode* p,vector<int>&v){
          if(!root)return false;
           v.push_back(root->val);
           if(root==p)return true;
                if(f(root->left,p,v) || f(root->right,p,v))return true;
              v.pop_back();
              return false;
      }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              vector<int>v;
               f(root,p,v);
              vector<int>u;
              f(root,q,u);
              int i=0;
              while(i<v.size() && i<u.size() && v[i]==u[i])i++;
              return new TreeNode(v[i-1]);
    }
};