//lc 543
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root,diameter);
        return diameter;
    }
private:
    static int dfs(TreeNode *curr, int &diameter) {
        if(!curr)
            return 0;
        int left_len = dfs(curr->left,diameter);
        int right_len = dfs(curr->right,diameter);
        diameter = max(diameter,left_len+right_len);
        return max(left_len,right_len)+1;
    }
};