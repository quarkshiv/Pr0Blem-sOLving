class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto it : s){
              if(it=='*'){
                 ans.pop_back();
              }
              else ans.push_back(it);
        }
        return ans;
    }
};