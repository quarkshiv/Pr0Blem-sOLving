class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long tot = 0;
        for(auto &it : batteries){
            tot+=it;
        }
        for(int i=batteries.size()-1;i>=0;i--){
              if(batteries[i]<=(tot/n)) break;
              tot-=batteries[i];
              n--;
        }
        return tot/n;
    }
};