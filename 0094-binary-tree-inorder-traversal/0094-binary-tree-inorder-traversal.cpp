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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* curr = root;
        while(curr){
            if(curr->left==NULL){//{L,V,R}
                   res.push_back(curr->val);
                   curr= curr->right;
            }
            else{
                //left child ke right most pe jao aur uska connection bana do curr se
                TreeNode* leftchild = curr->left;
                 while(leftchild->right!=nullptr){
                     leftchild =  leftchild->right;
                 }
                 leftchild->right = curr;

                 //ab woh curr->left wala null mark kardo taaki revisit na ho
                 TreeNode* temp = curr;
                 curr= curr->left;
                 temp->left=nullptr;
            }
        }
        return res;
    }
};