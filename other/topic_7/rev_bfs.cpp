class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> queue;
        vector<vector<int>> res;
        if(!root)
            return res;
        queue.push(root);
        while(!queue.empty()) {
            vector<int> level_res;
            int level_size = queue.size();
            for(int i = 0; i < level_size; ++i) {
                TreeNode *curr = queue.front();
                queue.pop();
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
                level_res.push_back(curr->val);
            }
            res.insert(res.begin(),level_res);
        }
        return res;
    }
};