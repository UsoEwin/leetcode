class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root)
            return res;
        queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()) {
            long long sum = 0, level_len = queue.size();
            for(int i = 0; i < level_len; ++i) {
                TreeNode *curr = queue.front();
                queue.pop();
                sum += curr->val;
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
            res.push_back(sum/((double)level_len));
        }
        return res;
    }
};