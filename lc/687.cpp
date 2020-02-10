//lc 687
//use curr pt to link left and right, i.e. check son of curr
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int max_len = 0;
        dfs(root,max_len);
        return max_len;
    }
private:
    int dfs(TreeNode *curr, int &max_len) {
        if(!curr)
            return 0;
        int left_sub = dfs(curr->left,max_len);
        int right_sub = dfs(curr->right,max_len);
        int left = 0, right = 0;
        if(curr->left && curr->left->val == curr->val)
            left += left_sub+1;
        if(curr->right && curr->right->val == curr->val)
            right += right_sub+1;
        max_len = max(max_len,left+right);
        return max(left,right);
    }
};