//lc 129
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
private:
    int dfs(TreeNode *curr, long long sum) {
        if(!curr)
            return 0;
        sum = 10*sum + curr->val;
        if(!curr->left && !curr->right)
            return sum;
        return dfs(curr->left,sum) + dfs(curr->right,sum);
    }
};