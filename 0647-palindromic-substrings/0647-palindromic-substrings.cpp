class Solution {
public:
    bool ispal(string s){
        int left=0;
        int right = s.size()-1;
        while(left<=right){
              if(s[left]!=s[right]){
                return false;
              }
              left++;
              right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
              string str="";
            for(int j=i;j<s.size();j++){
                  str+=s[j];
                  if(ispal(str)){
                cnt++;
            }
            }
            
        }
        return cnt;
    }
};