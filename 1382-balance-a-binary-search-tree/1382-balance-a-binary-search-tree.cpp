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
       TreeNode* build(vector<int>&arr,int l,int h){
              if(l>h){
                return NULL;
              }
              int mid = (l+h)/2;
              TreeNode* root=new TreeNode(arr[mid]);
              root->left= build(arr,l,mid-1);
              root->right = build(arr,mid+1,h);
              return root;

       }
       void inorder(TreeNode* root,vector<int>&arr){
            if(!root){
                return;
            }
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
       }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        return build(arr,0,arr.size()-1);
    }
};