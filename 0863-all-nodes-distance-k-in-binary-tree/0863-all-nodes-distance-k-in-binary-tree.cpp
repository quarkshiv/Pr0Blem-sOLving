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
   vector<int>bfs(TreeNode* target, int k, unordered_map<TreeNode*,TreeNode*>&parentMap){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>vis;
        vis.insert(target);
        q.push(target);
        int currlevel=0;
        while(!q.empty()){
            int size=q.size();
            if(currlevel==k) break;
            for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !vis.count(node->left)){
                vis.insert(node->left);
                q.push(node->left);
            }
             if(node->right && !vis.count(node->right)){
                vis.insert(node->right);
                q.push(node->right);
            }
            if(parentMap.count(node) && !vis.count(parentMap[node])){
                   vis.insert(parentMap[node]);
                   q.push(parentMap[node]);
            }
             
        }
        currlevel++;
   }
    vector<int>ans;
   while(!q.empty()){
       ans.push_back(q.front()->val);
       q.pop();
   }
   return ans;
   }
    void mapParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap){
         queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
              TreeNode* node= q.front();
              q.pop();
              if(node->left){
                  parentMap[node->left]=node;
                  q.push(node->left);
              }
                if(node->right){
                  parentMap[node->right]=node;
                  q.push(node->right);
              }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*,TreeNode*>parentMap;
        mapParentMap(root,parentMap); 
        return bfs(target,k,parentMap);
    }

};