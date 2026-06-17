class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
         map<char,int>mpp1,mpp2;
         for(int i=0;i<s1.size();i++){
                 mpp1[s1[i]]++;
                 mpp2[s2[i]]++;
         }
         if(mpp1==mpp2){
            return true;
         }
         int window = s1.size();
         for(int i=window;i<s2.size();i++){
               mpp2[s2[i]]++;
               mpp2[s2[i-window]]--;
               if(mpp2[s2[i-window]] == 0) {
    mpp2.erase(s2[i-window]);
}
               if(mpp1==mpp2){
                return true;
               }
         }
         return false;
    }
};