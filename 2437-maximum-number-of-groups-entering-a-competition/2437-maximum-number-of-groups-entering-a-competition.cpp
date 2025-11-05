class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int prevsum=grades[0];
        int prevsize=1;
        int currsum=0;
        int currsize=0;
        int cnt=1;
        for(int i=1;i<grades.size();i++){
             currsum+=grades[i];
             currsize++;
            if(prevsum<currsum && prevsize<currsize){
                prevsum=currsum;
                prevsize=currsize;
                currsize=0;
                currsum=0;
                cnt++;
            }
            
        }
        return cnt;
    }
};