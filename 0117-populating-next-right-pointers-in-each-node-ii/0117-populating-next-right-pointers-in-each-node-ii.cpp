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
    void bfs(Node*root){
        Node*prev=NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            prev=q.front();
            
            for(int i=0;i<s;i++){
                if(i>0){
                    prev->next=q.front();
                    prev=q.front();
                }
                if(i==s-1){
                    prev->next=NULL;
                }
                Node*f=q.front();
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
        }
        
    }
    Node* connect(Node* root) {
        if(!root)return NULL;
        bfs(root);
        return root;
    }
};