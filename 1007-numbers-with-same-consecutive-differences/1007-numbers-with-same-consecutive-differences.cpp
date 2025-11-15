class Solution {
public:
    void f(vector<int>& ans,int num,int left,int k){
        if(left==0){
            ans.push_back(num);
            return;
        }
        int last = num % 10;
        int d1 = last + k;
        int d2 = last - k;

        if (d1 >= 0 && d1 <= 9)
            f(ans,num * 10 + d1, left - 1, k);
        if (k != 0 && d2 >= 0 && d2 <= 9)
            f(ans,num * 10 + d2, left- 1, k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
        f(ans,i,n-1,k);
    }
    return ans;
    }
};