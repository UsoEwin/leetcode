class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node *> queue;
        queue.push(root);
        while(!queue.empty()) {
            vector<int> level_res;
            int level_size = queue.size();
            for(int i = 0; i < level_size; ++i) {
                Node *curr = queue.front();
                queue.pop();
                for(int i = 0; i < curr->children.size(); ++i)
                    //if(curr->children[i])
                        queue.push(curr->children[i]);
                level_res.push_back(curr->val);
            }
            res.push_back(level_res);
        }
        return res;
    }
};