class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n =arr.size();
        vector<int>ans(n);
        vector<int>temp =arr;
        sort(temp.begin(),temp.end());
        map<int,int>mpp;
        int rank=1;
        for(int i=1;i<=temp.size();i++){
            if(!mpp.count(temp[i-1])) mpp[temp[i-1]]=rank++;
        }
        for(int i=0;i<arr.size();i++){
                 ans[i]= mpp[arr[i]];
        }
        return ans;
    }
};