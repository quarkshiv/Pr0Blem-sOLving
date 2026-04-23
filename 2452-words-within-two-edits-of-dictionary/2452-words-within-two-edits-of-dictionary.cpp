class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto it : queries){
               for(int i=0;i<dictionary.size();i++){
                if(dictionary[i].size()!=it.size())break;
                int cnt=0;
                         for(int j=0;j<dictionary[i].size();j++){
                                 if(dictionary[i][j]!=it[j])cnt++;
                         }
                         if(cnt<=2){
                              ans.push_back(it);
                              break;
                         }
               }

        }
        return ans;
    }
};