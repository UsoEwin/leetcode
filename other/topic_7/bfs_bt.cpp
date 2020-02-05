class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            vector<int> level_res;
            int level_size = nodes.size();
            for(int i = 0; i < level_size; ++i) {
                TreeNode *curr = nodes.front();
                nodes.pop();
                if(curr->left)
                    nodes.push(curr->left);
                if(curr->right)
                    nodes.push(curr->right);
                level_res.push_back(curr->val);
            }
            res.push_back(level_res);
        }
        return res;
    }
};