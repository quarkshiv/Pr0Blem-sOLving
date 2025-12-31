class Solution {
public:
    int countCollisions(string directions) {
        int l=0;
        int r = directions.size()-1;
        while(l<directions.size() && directions[l]=='L') l++;
        while(r>=0 && directions[r]=='R') r--;
        int ans=0;
        while(l<=r){
              if(directions[l]!='S') ans++;
              l++;
        }
        return ans;
    }
};