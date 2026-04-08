class Solution {
public:
    void f(int ind,string digits,unordered_map<char,string>mpp,vector<string>
    &ans,string path){
        if(ind==digits.size()){
               ans.push_back(path);
               return;
        }
        string l = mpp[digits[ind]];
        for(auto it : l){
             path.push_back(it);
                 f(ind+1,digits,mpp,ans,path);
                 path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
         vector<string>ans;
         string path;
         f(0,digits,mpp,ans,path);
         return ans;
    }
};