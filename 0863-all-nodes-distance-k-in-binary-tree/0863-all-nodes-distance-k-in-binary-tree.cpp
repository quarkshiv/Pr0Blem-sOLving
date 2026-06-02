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
    void build(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(!root)return;
        if(root->left){
              mpp[root->left]=root;
              build(root->left,mpp);
        }
         if(root->right){
              mpp[root->right]=root;
              build(root->right,mpp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        vector<int>ans;
        build(root,mpp);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        unordered_set<TreeNode*>vis;
        vis.insert(target);
        while(!q.empty()){
              int sz = q.size();
            while(sz--){
                TreeNode* node = q.front().first;
                int steps=q.front().second;
                q.pop();
                if(steps==k){
                       ans.push_back(node->val);
                       continue;
                }
                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push({node->left,steps+1});
                }
                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push({node->right,steps+1});
                }
                if(mpp.count(node) && !vis.count(mpp[node])){
                      vis.insert(mpp[node]);
                      q.push({mpp[node],steps+1});
                }
            }
        }
        return ans;
    }
};