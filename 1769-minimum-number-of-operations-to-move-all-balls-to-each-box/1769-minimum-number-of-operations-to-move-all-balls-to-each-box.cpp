class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n,0);
        for(int i=0;i<boxes.size();i++){
               for(int j=0;j<boxes.size();j++){
                  if(i!=j && boxes[j]=='1'){
                        ans[i]+=abs(i-j);
                  }
               }
        }
        return ans;
    }
};