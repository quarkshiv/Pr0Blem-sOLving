class Solution {
public:
    void f(int ind,int n,string s,vector<string>&ans){
           if(ind==n){
            ans.push_back(s);
            return;
           }
           if(s[ind-1]=='a'){
                f(ind+1,n,s+'b',ans);
                f(ind+1,n,s+'c',ans);
           }
            if(s[ind-1]=='b'){
                f(ind+1,n,s+'a',ans);
                f(ind+1,n,s+'c',ans);
           }
            if(s[ind-1]=='c'){
                f(ind+1,n,s+'b',ans);
                f(ind+1,n,s+'a',ans);
           }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string s="";
        f(1,n,s+'a',ans);
        f(1,n,s+'b',ans);
        f(1,n,s+'c',ans);
        if(ans.size()<k)return "";
        sort(ans.begin(),ans.end());
        return ans[k-1];

    }
};