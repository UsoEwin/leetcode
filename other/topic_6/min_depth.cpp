class Solution {
public:
    int minDepth(TreeNode* root) {
        int min_depth = 0;
        if(!root)
            return min_depth;
        queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()) {
            int level_len = queue.size();
            min_depth++;
            for(int i = 0; i < level_len; ++i) {
                TreeNode *curr = queue.front();
                queue.pop();
                if(!curr->left && !curr->right)
                    return min_depth;
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
        }
        return min_depth;
    }
};