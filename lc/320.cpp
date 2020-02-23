//lc 320
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string str = "";
        dfs(res,word,str,0,0);
        return res;
    }
private:
    static void dfs(vector<string> &res, string &word, string curr_word, int start, int count) {
        if(start == word.size()) {
            if(count != 0)
                curr_word += to_string(count);
            res.push_back(curr_word);
            return;
        }
        dfs(res,word,curr_word,start+1,count+1);
        if(count != 0)
            curr_word += to_string(count);
        dfs(res,word,curr_word+word[start],start+1,0);
        return;
    }
};