class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
   // TODO: Write your code here
    if(root == nullptr)
      return nullptr;
    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()) {
        TreeNode *curr = queue.front();
        queue.pop();
        if(curr->left)
          queue.push(curr->left);
        if(curr->right)
          queue.push(curr->right);
        if(curr->val == key)
          break;
    }
    return queue.front();
  }
};