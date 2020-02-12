//lc 250
class Solution {
    int count = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root)
            return count;
        dfs(root);
        return count;
    }
private:
    bool dfs(TreeNode *curr) {
        bool left_check = true, right_check = true;
        if(curr->left)
            left_check = dfs(curr->left) && curr->val == curr->left->val;
        if(curr->right)
            right_check = dfs(curr->right) && curr->val == curr->right->val;
        if(left_check && right_check)
            count++;
        return left_check && right_check;
    }
};