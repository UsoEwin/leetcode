//lc 784
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if(S.empty())
            return res;
        res.push_back(S);
        for(int i = 0; i < S.size(); ++i) {
            int n = res.size();
            if(isalpha(S[i])) {
                for(int j = 0; j < n; ++j) {
                    string curr_str = res[j];
                    if(islower(curr_str[i]))
                        curr_str[i] = toupper(curr_str[i]);
                    else
                        curr_str[i] = tolower(curr_str[i]);
                    res.push_back(curr_str);
                }
            }
        }
        return res;
    }
};