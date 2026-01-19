class Solution {
public:
    //  bool seq(int num){
    //       int prev=-1;
    //       while(num>0){
    //            int dig=num%10;
    //            num=num/10;
    //            if(prev==-1){
    //                 prev=dig;
    //                 continue;
    //            }
    //            else{
    //                 if(prev!=dig+1){
    //                     return false;
    //                 }
    //                 else{
    //                      prev=dig;
    //                 }
    //            }

    //       }
    //       return true;
    //  }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        // for(int i=low;i<=high;i++){
        //     if(seq(i)){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
           string s = "123456789";
           for(int i=0;i<s.size();i++){
             for(int j=i+1;j<=s.size();j++){
                  int num = stoi(s.substr(i,j-i));
                  if(num>=low && num<=high){
                      ans.push_back(num);
                  }
             }
           }
           sort(ans.begin(),ans.end());
           return ans;
    }
};