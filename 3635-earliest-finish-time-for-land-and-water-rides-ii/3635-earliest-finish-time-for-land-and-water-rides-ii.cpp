class Solution {
public:
    int f(vector<int>& first, vector<int>& firsttime, vector<int>& second, vector<int>& secondtime){
        int mini = INT_MAX;
        for(int i=0;i<first.size();i++){
               mini =  min(mini,first[i]+firsttime[i]);
        }
        int ans= INT_MAX;
        for(int i=0;i<second.size();i++){
               ans = min(ans,max(mini,second[i])+secondtime[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int val1 = f(lst,ld,wst,wd);
        int val2=f(wst,wd,lst,ld);
        return min(val1,val2);
    }
};