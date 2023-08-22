/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1st step -->
        // Create a copy of curr node and make the connection to its neighbour node
        Node* temp = head;
        Node* copy;
        while(temp != NULL) {
            copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // 2nd step -->
        // Create a copy of curr node and make the connection to its Random node
        temp = head;
        while(temp != NULL) {
            if(temp->random != NULL) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // 3rd step --->>
        // -> Copy's next pointer --> curr next pointer(Delete path)
        // -> curr next pointer --> after.. ---> This is repeated work..
        Node* ans = new Node(0);
        copy = ans;
        temp = head;
        while(temp != NULL) {
            Node* after = temp->next->next;
            copy->next = temp->next;
            temp->next = after;
            copy = copy->next;
            temp = after;
        }
        return ans->next;
    }
};