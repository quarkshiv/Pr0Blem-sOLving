class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0;
        int i = 0;
        vector<string>res;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1')
                count++;
            else
                count--;
            if (count == 0) {
                string inner = makeLargestSpecial(s.substr(i + 1, j - i - 1));
                res.push_back("1" + inner + "0");
                i = j + 1;
            }
        }
        sort(res.begin(), res.end(), greater<string>());
        string result;
        for (auto &str:res)
            result +=str;

        return result;
    }
};