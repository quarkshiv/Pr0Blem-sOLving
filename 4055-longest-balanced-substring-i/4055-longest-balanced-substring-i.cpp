class Solution {
public:
    int longestBalanced(string s) {
        int maxlen =0;
        for(int i=0;i<s.size();i++){
               vector<int>mpp(26,0);
            for(int j=i;j<s.size();j++){
                mpp[s[j]-'a']++;
                int val=0;
                bool vis=false;
                for(auto it : mpp){
                     if(it >0){
                     if(val==0){
                        val =it;
                     }
                     else if(val != it){
                        vis = true;
                        break;
                    }
                     }
                }
                if(!vis){
                    maxlen = max(maxlen,j-i+1);
                }
                }
        }
            
            return maxlen;
        }
    
};