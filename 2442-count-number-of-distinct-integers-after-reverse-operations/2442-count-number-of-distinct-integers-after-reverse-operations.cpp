class Solution {
public:
   string rev(int n){
         string s= to_string(n);
         reverse(s.begin(),s.end());
         int i=0;
         while(s[i]=='0'){ 
            i++;
         }
         s = s.substr(i,s.size()-i);
         return s;
   }
    int countDistinctIntegers(vector<int>& nums) {
        set<int>st;
        for(auto it : nums){
            st.insert(it);
            string s = rev(it);
            int val = stoi(s);
            st.insert(val);
        }
        return st.size();
    }
};