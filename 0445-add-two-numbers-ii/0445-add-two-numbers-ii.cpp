class Solution {
private:
ListNode* reverse(ListNode* head) {
    if(!head) return NULL;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1st step --> Reverse the LL(given)
        // 2nd step --> Normal add with prev and curr Nodes........
        
        ListNode* revL1 = reverse(l1);
        ListNode* revL2 = reverse(l2);

        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int carry = 0, rem = 0;

        while(revL1 != NULL || revL2 != NULL || carry == 1) {
            int sum = 0;
            if(revL1 != NULL) {
                sum += revL1->val;
                revL1 = revL1->next;
            }
            if(revL2 != NULL) {
                sum += revL2->val;
                revL2 = revL2->next;
            }

            rem = (sum+carry)%10;
            carry = (sum+carry)/10;
            temp->next = new ListNode(rem);
            temp = temp->next;
        }
        return reverse(ans->next);
    }
};