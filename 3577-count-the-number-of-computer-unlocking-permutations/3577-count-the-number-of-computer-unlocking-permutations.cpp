class Solution {
public:
    const int mod = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        int mini = *min_element(complexity.begin(),complexity.end());

        if(complexity[0]!=mini || count(complexity.begin(),complexity.end(),mini)>1) return 0;
        long long ans=1;
        for(int i=1;i<complexity.size();i++){
               ans = (ans * i) % mod;
        }
        return (int)ans;
    }
};