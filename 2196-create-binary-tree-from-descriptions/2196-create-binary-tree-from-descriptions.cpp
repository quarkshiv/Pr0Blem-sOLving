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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>par;
        unordered_set<int>childs;
        for(auto &it : descriptions){
                if(par.find(it[0])==par.end()){
                        par[it[0]]=new TreeNode(it[0]); 
                }
                if(!par.count(it[1])){
                     par[it[1]]=new TreeNode(it[1]);
                }
                if(it[2]){
                       par[it[0]]->left = par[it[1]];
                }
                else{
                    par[it[0]]->right= par[it[1]];
                }
                childs.insert(it[1]);
        }
        for(auto &it : descriptions){
              if(!childs.count(it[0])){
                return par[it[0]];
              }
        }
        return nullptr;
    }
};