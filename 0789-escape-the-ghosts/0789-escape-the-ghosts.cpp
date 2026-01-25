class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int fd=abs(target[0])+abs(target[1]);
        for(auto it : ghosts){
              if(abs(it[0]-target[0]) + abs(it[1]-target[1])<=fd){
                return false;
              }
        }
        return true;
    }
};