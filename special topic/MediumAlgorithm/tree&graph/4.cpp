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
    class levelNode {
        public:
            int level;
            Node* data;
    };
    
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<levelNode*> q;
        levelNode* t = new levelNode();
        t->level = 1;
        t->data = root;
        q.push(t);
        levelNode* top;
        while(!q.empty()){
            top = q.front();
            q.pop();
            if(q.empty() || top->level != q.front()->level) top->data->next = NULL;
            else top->data->next = q.front()->data;
            if(top->data->left){
                levelNode* l = new levelNode();
                l->level = top->level + 1;
                l->data = top->data->left;
                q.push(l);
            }
            if(top->data->right){
                levelNode* r = new levelNode();
                r->level = top->level + 1;
                r->data = top->data->right;
                q.push(r);
            }       
        }
        return root;
    }
};