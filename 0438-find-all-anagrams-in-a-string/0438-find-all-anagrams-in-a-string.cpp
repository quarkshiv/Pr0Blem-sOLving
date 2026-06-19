class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mpp1;
        vector<int>ans;
        for(auto it : p){
             mpp1[it]++;
        }
        unordered_map<char,int>mpp2;
        int window = p.size();
           for(int i=0;i<window;i++){
                 mpp2[s[i]]++;
           }    
           if(mpp1==mpp2){
                ans.push_back(0);
           }    
           for(int i=window;i<s.size();i++){
                mpp2[s[i]]++;
                mpp2[s[i-window]]--;
                if(mpp2[s[i-window]]==0){
                      mpp2.erase(s[i-window]);
                }
                if(mpp2==mpp1){
                    ans.push_back(i-window+1);
                }
           }
           return ans;
    }
};