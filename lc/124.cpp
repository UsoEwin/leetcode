//lc 124
//good example of postorder traversal
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int max_val = root->val;
        dfs(root,max_val);
        return max_val;
    }
private:
    static int dfs(TreeNode *curr, int &max_val) {
        if(!curr)
            return 0;
        int left_sum = dfs(curr->left,max_val);
        int right_sum = dfs(curr->right,max_val);
        left_sum = max(left_sum,0);
        right_sum = max(right_sum,0);
        max_val = max(max_val,left_sum+right_sum+curr->val);
        return max(left_sum,right_sum)+curr->val;
    }
};