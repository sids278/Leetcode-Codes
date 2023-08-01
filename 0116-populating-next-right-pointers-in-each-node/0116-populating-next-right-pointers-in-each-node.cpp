/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int x=q.size();
            while(x-1){
                Node*f=q.front();
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                f->next=q.front();
                x--;
                
            }
            Node*f=q.front();
            q.pop();
            f->next=NULL;
            if (f->left) q.push(f->left);
            if (f->right) q.push(f->right);
            
        }
        return root;
    }
};