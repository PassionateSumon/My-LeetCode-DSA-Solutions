class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        // prev -- curr
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != NULL) {
            int gcd_value = __gcd(prev->val, curr->val);
            ListNode* gcd = new ListNode(gcd_value);
            gcd->next = curr;
            prev->next = gcd;

            prev = curr;
            curr = curr->next; 
        }
        return head;
    }
};