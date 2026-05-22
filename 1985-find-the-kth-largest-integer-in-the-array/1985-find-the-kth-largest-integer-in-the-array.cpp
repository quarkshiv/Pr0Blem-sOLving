class Solution {
public:
  static bool cmp(string &a,string &b){
        if(a.size()==b.size()){
               return a>b;  //if same lexo
        }
        return a.size()>b.size(); //dec
  }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
          return nums[k-1];
    }
};