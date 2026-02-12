class Solution {
public:
    int longestBalanced(string s) {
        int maxlen=0;
        for(int i=0;i<s.size();i++){
              vector<int>mpp(26,0);
              for(int j=i;j<s.size();j++){
                    mpp[s[j]-'a']++;
                    bool valid=true;
                    int val=0;
                    for(auto it : mpp){
                          if(it>0){
                              if(val==0){
                                val=it;
                              }
                          }
                          if(it!=val && it>0)valid=false;
                    }
                    if(valid){
                        maxlen = max(maxlen,j-i+1);
                    }
              }
        }
        return maxlen;
    }
};