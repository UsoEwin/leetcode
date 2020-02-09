//lc 199
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()) {
            int level_len = queue.size();
            for(int i = 0; i < level_len; ++i) {
                TreeNode *curr = queue.front();
                queue.pop();
                if(i == level_len-1)
                    res.push_back(curr->val);
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
        }
        return res;
    }
};