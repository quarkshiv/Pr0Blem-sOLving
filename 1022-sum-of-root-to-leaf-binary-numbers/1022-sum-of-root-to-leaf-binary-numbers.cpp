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
vector<string>v;
int ans;
   void decimal(){
    ans=0;
    for(int i=0;i<v.size();i++){
    string s=v[i];
       int res=0;
       for(int j=0;j<s.size();j++){
        res=res*2 + (s[j]-'0');
       }
       ans+=res;
    }
   }

    void dfs(TreeNode *node, string& t){
       if(!node){
            return;
       }
         t+=(node->val + '0');
         if(!node->left && !node->right){
                v.push_back(t);
                t.pop_back();
                return;
         }
           dfs(node->left,t);
           dfs(node->right,t);

           t.pop_back();

    }
  
    int sumRootToLeaf(TreeNode* root) {
          string s="";
          dfs(root,s);
          decimal();
   return ans;
    }
};