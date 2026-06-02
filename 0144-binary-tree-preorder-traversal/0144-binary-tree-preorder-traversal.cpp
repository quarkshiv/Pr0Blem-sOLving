class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* next;
        while(curr) {
            ans.push_back(curr->val);
            if(curr->left == nullptr) {
                curr = curr->right;
            }
            else {
                next= curr->left;
                while(next->right){
                next = next->right;
                }
                TreeNode* nextroot = curr->left;
                next->right = curr->right;
                curr->right = nullptr;
                curr= nextroot;

            }
        }
        return ans;
    }
};