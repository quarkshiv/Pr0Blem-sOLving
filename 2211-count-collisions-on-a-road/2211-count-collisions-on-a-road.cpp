class Solution {
public:
    int countCollisions(string directions) {
        int l=0;
        int n = directions.size();
        int r =n-1;
        while(l<n && directions[l]=='L') l++;
        while(r>=0 && directions[r]=='R') r--;
        int ans=0;
        while(l<=r){
              if(directions[l]!='S') ans++;
              l++;
        }
        return ans;
    }
};