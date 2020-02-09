//lc 113
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr_res;
        dfs(root,sum,curr_res,res);
        return res;
    }
private:
    static void dfs(TreeNode *root,int sum, vector<int> &curr_res, vector<vector<int>> &res) {
        if(!root)
            return;
        curr_res.push_back(root->val);
        if(root->val == sum && !root->left && !root->right)
            res.push_back(curr_res);
        dfs(root->left,sum-root->val,curr_res,res);
        dfs(root->right,sum-root->val,curr_res,res);
        curr_res.pop_back();
        return;
    }
};