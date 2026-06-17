class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1;
        string ans2;
        for(auto it : s){
              if(it=='#' && !ans1.empty())ans1.pop_back();
              else if(it!='#')ans1.push_back(it);
        }
        cout<<ans1<<endl;
         for(auto it : t){
              if(it=='#' && !ans2.empty())ans2.pop_back();
              else if(it!='#')ans2.push_back(it);
        }
        cout<<ans2<<endl;
        return ans1==ans2;  
    }
};