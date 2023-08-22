class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        // Node* ver;
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