class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        if(n==1){
            return stoi(operations[0]);
        }
        vector<int>ans;
        int prev1 = 0;
       int prev2=0;
        for(int i=0;i<n;i++){
              if(operations[i]=="+"){
                   int val = prev1 + prev2;
                ans.push_back(val);
                prev2 = prev1;
                prev1 = val;
              }
              else if(operations[i]=="D"){
                ans.push_back(prev1 * 2);
                prev2 = prev1;
                prev1  = prev1 * 2;
              }
              else if(operations[i]=="C"){
                 if (!ans.empty()) {
                    ans.pop_back();
                    int sz = ans.size();
                    prev1 = (sz >= 1 ? ans[sz - 1] : 0);
                    prev2 = (sz >= 2 ? ans[sz - 2] : 0);
              }
              }
              else{
                ans.push_back(stoi(operations[i]));
                 prev2 = prev1;
                prev1 = stoi(operations[i]);
                
              }
        }
        int sum=0;
         for(int i=0;i<ans.size();i++){
            sum+=ans[i];
         }
         return sum;
    }
};