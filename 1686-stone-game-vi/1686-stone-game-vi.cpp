class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
           pq.push({aliceValues[i]+bobValues[i],i});
        }
         int parity=1;
         long long alice=0;
         long long bob=0;
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
                if(parity){
                    alice+=aliceValues[ind];
                    parity=0;
                }
                else{
                    parity=1;
                    bob+=bobValues[ind];
                }
                
        }
        if(alice==bob) return 0;
        else if(alice>bob) return 1;
        else return -1;
    }
};