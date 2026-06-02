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
  int getlh(TreeNode* root){
    int h=0;
    while(root){
          h++;
         root=root->left;
    }
    return h;
  }
   int getrh(TreeNode* root){
    int h=0;
    while(root){
          h++;
          root=root->right;
    }
    return h;
  }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int h1 = getlh(root);
         int h2 = getrh(root);
         if(h1==h2){
            return (1 << h1)-1;
         }

         return 1 + countNodes(root->right) + countNodes(root->left);
    }
};