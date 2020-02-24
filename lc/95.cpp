//lc 95
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)
            return vector<TreeNode *>();
        vector<TreeNode *> res = buildTrees(1,n);
        return res;
    }
private:
    static vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> res;
        if(start > end)
            res.push_back(nullptr);
        else {
            for(int i = start; i <= end; ++i) {
                vector<TreeNode*> left_subtrees = buildTrees(start,i-1);
                vector<TreeNode*> right_subtrees = buildTrees(i+1,end);
                for(auto x:left_subtrees) {
                    for(auto y:right_subtrees) {
                        TreeNode *root = new TreeNode(i);
                        root->left = x;
                        root->right = y;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};