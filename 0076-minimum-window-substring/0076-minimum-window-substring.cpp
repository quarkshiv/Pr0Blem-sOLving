class Solution {
public:
    string minWindow(string s, string t) {
        int len = INT_MAX;
        int start = -1; 
        int l = 0; 
        int match=0;
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
           for(auto &c : t){
               mpp1[c]++;
           }

           for(int r=0;r<s.size();r++){
                 mpp2[s[r]]++;
                 if(mpp1.count(s[r]) && mpp1[s[r]]==mpp2[s[r]])match++;
                 if(match==mpp1.size()){
                       while(mpp1.count(s[l])==0 || mpp2[s[l]]>mpp1[s[l]]){
                             mpp2[s[l]]--;
                             if(mpp2[s[l]]==0){
                                   mpp2.erase(s[l]);
                             }
                             l++;
                       }
                       if(len>r-l+1){
                            start=l;
                              len =  r-l+1;
                       }
                 }
           }
           if(start==-1) return "";
           return s.substr(start,len);
    }
};