class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        ListNode* prev = dummy;

        int carry = ((head->val)*2)/10;
        int rem = ((head->val)*2)%10;
        if(carry > 0) {
            ListNode* help = new ListNode(carry);
            temp->next = new ListNode(rem);
            help->next = temp->next;

            temp = temp->next;
            prev = prev->next;

            head = head->next;
            while(head != NULL) {
                carry = ((head->val)*2)/10;
                rem = ((head->val)*2)%10;
                prev->val = (prev->val + carry);
                temp->next = new ListNode(rem);
                temp = temp->next;
                prev = prev->next;
                head = head->next;
            }
            return help;
        } else {
            temp->next = new ListNode(rem);
            temp = temp->next;
            prev = prev->next;

            head = head->next;
            while(head != NULL) {
                carry = ((head->val)*2)/10;
                rem = ((head->val)*2)%10;
                prev->val = (prev->val + carry);
                temp->next = new ListNode(rem);
                temp = temp->next;
                prev = prev->next;
                head = head->next;
            }
        }
        return dummy->next;
    }
};