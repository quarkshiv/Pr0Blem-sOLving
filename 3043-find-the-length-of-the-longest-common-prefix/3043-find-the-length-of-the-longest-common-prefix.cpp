class Trie{
    public:
    struct Node{
           Node* child[26];
           Node(){
               for(int i=0;i<26;i++){
                child[i]=NULL;
               }
           }
    };
    Node* root;
    Trie(){
        root= new Node();
    }
    void insert(string word){
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'0';
            if(curr->child[idx]==NULL){
                   curr->child[idx]=new Node();
            }
            curr=curr->child[idx];
        }
    }
    int longestcmpref(string word){
             Node* curr= root;
             int cnt=0;
            for(int i=0;i<word.size();i++){
                int idx = word[i]-'0';
                if(curr->child[idx]!=NULL){
                       cnt++;
                      curr = curr->child[idx];
                }
                else break;
            }
            return cnt;
    }

};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int i=0;i<arr1.size();i++){
              string s = to_string(arr1[i]);
               trie.insert(s);
        }
        int maxlen=0;
        for(int i=0;i<arr2.size();i++){
            string s = to_string(arr2[i]);
            int len=trie.longestcmpref(s);
            if(len>maxlen){
                maxlen=len;
            }
        }
        return maxlen;
    }
};