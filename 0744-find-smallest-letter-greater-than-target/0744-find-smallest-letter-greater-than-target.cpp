class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ind = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(ind>=0 && ind<letters.size()){
            return letters[ind];
        }
        return letters[0];
    }
};