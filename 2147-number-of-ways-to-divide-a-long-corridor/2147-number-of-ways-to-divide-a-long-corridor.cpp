class Solution {
public:
    const int mod=1e9+7;
    int numberOfWays(string corridor) {
        vector<int>pos;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                pos.push_back(i);
            }
        }
            if(pos.size()==0 || pos.size()%2!=0) return 0;
            if(pos.size()==2)return 1;
            long long ans=1;
            for(int i=1;i<pos.size()-1;i+=2){
                int left=pos[i];
                int right =pos[i+1];
                int cnt = (right-left-1)+1;
                ans= (ans * 1LL*cnt)%mod;
            }
        return (int)ans;
    }
};