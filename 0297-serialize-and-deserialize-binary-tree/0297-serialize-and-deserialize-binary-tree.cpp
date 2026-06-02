/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        string ans;
        q.push(root);
        while(!q.empty()){
              TreeNode* node = q.front();
              q.pop();
              if(node){ 
                   ans+=(to_string(node->val)+",");
                   q.push(node->left);
                   q.push(node->right);
              }
              else{
                  ans.append("N,");
              }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        stringstream ss(data);
        string str;
    getline(ss,str,',');
    TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
               TreeNode* node = q.front();
               q.pop();
               //left wala part
               getline(ss,str,',');
               if(str!="N"){
                   node->left = new TreeNode(stoi(str));
                   q.push(node->left);
               }
               //right wala part
               getline(ss,str,',');
               if(str!="N"){
                   node->right = new TreeNode(stoi(str));
                   q.push(node->right);
               }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));