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
   TreeNode* f(vector<int>& inorder, vector<int>& postorder,int start,int end,int &ind){
       if(start>end)return nullptr;
       int rootval = postorder[ind];
       ind--;
       int i=start;
       for(;i<=end;i++){
          if(inorder[i]==rootval)break;
       }
       TreeNode* root = new TreeNode(rootval);
     root->right = f(inorder,postorder,i+1,end,ind);
       root->left = f(inorder,postorder,start,i-1,ind);
        
          return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int ind=n-1;
        return f(inorder,postorder,0,n-1,ind);
    }
};