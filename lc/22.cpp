//lc 22
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n < 1)
            return res;
        string str = "";
        dfs(res,str,0,0,n);
        return res;
    }
private:
    static void dfs(vector<string> &res, string str, int left, int right, int n) {
        if(str.size() == 2*n) {
            res.push_back(str);
            return;
        }
        if(left < n)
            dfs(res,str+"(",left+1,right,n);
        if(right < left)
            dfs(res,str+")",left,right+1,n);
        return;
    }
};