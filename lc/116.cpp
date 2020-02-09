//lc 116-117
//also can use list travesal
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node *> queue;
        queue.push(root);
        while(!queue.empty()) {
            Node *prev = nullptr;
            int level_len = queue.size();
            for(int i = 0; i < level_len; ++i) {
                Node *curr = queue.front();
                if(prev != nullptr)
                    prev->next = curr;
                queue.pop();
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
                prev = curr;
            }
        }
        return root;
    }
};