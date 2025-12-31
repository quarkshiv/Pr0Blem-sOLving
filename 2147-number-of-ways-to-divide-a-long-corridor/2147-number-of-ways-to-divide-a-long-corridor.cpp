class Solution {
public:
const int mod= 1e9+7;
    int numberOfWays(string corridor) {
           vector<int>s;
           for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S')
              s.push_back(i+1);
           }
            if(s.size()==0 || s.size()%2!=0) return 0;
            if(s.size()==2)return 1;
           long long ans=1;
           for(int i=1;i<s.size()-1;i+=2){
                int left=s[i];
                int right=s[i+1];
                int positions =(right-left-1)+1;
                ans = (ans * 1LL*positions)%mod;
           }
           return ans;
    }
};