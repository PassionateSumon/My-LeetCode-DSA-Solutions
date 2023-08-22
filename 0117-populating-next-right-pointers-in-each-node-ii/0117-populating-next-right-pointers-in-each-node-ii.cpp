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
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                Node* ver = q.front();
                q.pop();
                if(!q.empty()) ver->next = q.front();
                if(size == 0) ver->next = NULL;
                if(ver->left) q.push(ver->left);
                if(ver->right) q.push(ver->right);
            }
        }
        return root;
    }
};