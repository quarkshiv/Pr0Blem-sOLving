class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxlen=0;
        unordered_map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        if(mpp.count(1)){
            if(mpp[1]%2==0)mpp[1]--;
            maxlen=mpp[1];
        }
    for(auto curr  :  nums){
        int len=0;
         if (curr == 1) continue;
        while(mpp.count(curr) && mpp[curr]>1){
               len+=2;
               curr=1ll*curr*curr;
        }
        if(mpp.count(curr)){
            len+=1;
            maxlen = max(maxlen,len);
        }
        else{
                 len-=1;
                 maxlen=max(maxlen,len);
        } 
    }
    return maxlen;
    }
};