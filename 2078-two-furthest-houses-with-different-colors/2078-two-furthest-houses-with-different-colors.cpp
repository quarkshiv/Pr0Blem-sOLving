class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=0;
        for(int i=0;i<colors.size();i++){
            for(int j=0;j<colors.size();j++){
                if(i!=j && colors[i]!=colors[j] && abs(j-i)>maxi){
                         maxi = abs(j-i);
                }
            }
        }
        return maxi;
    }
};