class Solution {
public:
    string lexSmallest(string s) {
        string best = s;
        for(int k=1;k<s.size();k++){
            string temp =s;
             reverse(temp.begin() + k, temp.end());
             best =  min(best,temp);
             temp = s;
           reverse(temp.begin(), temp.begin() + k +1);
           best = min(best,temp);
        
        }
        return best;
    }
};