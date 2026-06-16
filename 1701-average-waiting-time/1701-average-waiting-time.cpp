class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long busytime=0;
        long long idletime=0;
        for(auto it : customers){
            if(it[0]>busytime){
                   busytime=it[0]+ it[1];
            }
                 else   busytime+=it[1];
                   idletime+=(busytime-it[0]);
            }
        return (double)idletime/n;
    }
};