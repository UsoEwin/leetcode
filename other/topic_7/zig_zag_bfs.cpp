class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> queue;
        queue.push(root);
        bool left_to_right = true;
        while(!queue.empty()) {
            int level_len = queue.size();
            vector<int> level_res(level_len);
            for(int i = 0; i < level_len; ++i) {
                TreeNode *curr = queue.front();
                queue.pop();
                if(left_to_right)
                    level_res[i] = curr->val;
                else
                    level_res[level_len-i-1] = curr->val;
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
            res.push_back(level_res);
            left_to_right = !left_to_right;
        }
        return res;
    }
};