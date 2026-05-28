class Solution {
public:
    typedef uint64_t ull;
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) { 
        unordered_map<ull,pair<int,int>>mpp;

        ull base = 313;

        int len = 1e9;
        int ind = 0;

        for(int i=0;i<wordsContainer.size();i++){

            if(wordsContainer[i].size() < len){
                len = wordsContainer[i].size();
                ind = i;
            }
        }

        for(int i=0;i<wordsContainer.size();i++){

            reverse(wordsContainer[i].begin(),wordsContainer[i].end());

            ull hash = 0;
            ull p = 1;

            for(auto c : wordsContainer[i]){

                hash += (ull)(c-'a'+1) * p;

                p *= base;

                if(!mpp.count(hash) || 
                   wordsContainer[i].size() < mpp[hash].first){

                    mpp[hash] = {wordsContainer[i].size(),i};
                }
            }
        }

        vector<int>ans;

        for(auto it : wordsQuery){

            reverse(it.begin(),it.end());

            ull hash = 0;
            ull p = 1;

            int best = ind;

            for(auto c : it){

                hash += (ull)(c-'a'+1) * p;

                p *= base;

                if(mpp.count(hash)){
                    best = mpp[hash].second;
                }
                else{
                    break;
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};