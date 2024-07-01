class Solution {
public:
    int total = 0;
    map<TreeNode*, TreeNode*> parent;
    map<TreeNode*, int> visited;
    TreeNode* begin = nullptr;

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* f = q.front();
            total++;
            q.pop();
            if (f->left) {
                parent[f->left] = f;
                q.push(f->left);
            }
            if (f->right) {
                parent[f->right] = f;
                q.push(f->right);
            }
        }
    }

    void finder(TreeNode* root, int start) {
        if (!root) return;
        if (root->val == start) {
            begin = root;
            return;
        }
        finder(root->left, start);
        finder(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        bfs(root);
        finder(root, start);
        queue<TreeNode*> q;
        q.push(begin);
        visited[begin] = 1;
        int time = 0;
        total--;

        while (!q.empty()) {
            if (total == 0) return time;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* f = q.front();
                q.pop();
                if (f->left && !visited[f->left]) {
                    q.push(f->left);
                    visited[f->left] = 1;
                    total--;
                }
                if (f->right && !visited[f->right]) {
                    q.push(f->right);
                    visited[f->right] = 1;
                    total--;
                }
                if (parent.find(f) != parent.end() && !visited[parent[f]]) {
                    q.push(parent[f]);
                    visited[parent[f]] = 1;
                    total--;
                }
            }
            time++;
        }
        return time;
    }
};
