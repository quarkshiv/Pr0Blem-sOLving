class Solution {
public:
     int rev(int n ){
          string s = to_string(n);
         reverse(s.begin(),s.end());
         int ind =0;
         while(ind<s.size() && s[ind]=='0') ind++;
         s =s.substr(ind);
         if(s.size()==0) return 0;
         return stoi(s);
     }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};