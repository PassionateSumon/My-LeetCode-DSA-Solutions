class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* lesser = new ListNode();
        ListNode* greater = new ListNode();
        ListNode* temp = head;
        ListNode* temp1 = lesser;
        ListNode* temp2 = greater;
        while(temp != NULL) {
            if(temp->val >= x) {
                greater->next = new ListNode(temp->val);
                greater = greater->next;
            }
            else {
                lesser->next = new ListNode(temp->val);
                lesser = lesser->next;
            }
            temp = temp->next; 
        }
        lesser->next = temp2->next;
        return temp1->next;
    }
};