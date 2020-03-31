//lc 17
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        vector<string> lookup(10);
        vector<string> res;
        string curr = "";
        for(int i = 2; i <= 6; ++i) {
            char var = 3*(i-2)+'a';
            lookup[i] = lookup[i]+char(var);
            lookup[i] = lookup[i]+char(var+1);
            lookup[i] = lookup[i]+char(var+2); 
        }
        lookup[7] = "pqrs";
        lookup[8] = "tuv";
        lookup[9] = "wxyz";
        dfs(digits,lookup,res,0,curr);
        return res;
    }
private:
    void print_lookup(vector<string> &lookup) {
        for(int i = 1; i < 9; ++i)
            cout << lookup[i] <<" " << lookup[i].size() << endl;
        return;
    }
    void dfs(string &digits, vector<string> &lookup, vector<string> &res, int curr_pos, string curr) {
        if(curr_pos == digits.size()) {
            res.push_back(curr);
            return;
        }
        char idx = (digits[curr_pos]-'0');
        for(int i = 0; i < lookup[idx].size(); ++i) {
            curr.push_back(lookup[idx][i]);
            dfs(digits,lookup,res,curr_pos+1,curr);
            curr.pop_back();
        }
        return;
    }
};