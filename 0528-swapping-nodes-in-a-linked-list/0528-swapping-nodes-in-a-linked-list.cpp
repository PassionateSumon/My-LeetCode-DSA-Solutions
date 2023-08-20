class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        int firstK, lastK;
        ListNode* curr = head;
        ListNode* next = head;
        int i = 1;
        temp = head;
        while(temp != NULL && i < k) {
            temp = temp->next;
            i++;
        }
        firstK = temp->val;
        curr = temp;
        
        temp = head;
        i = 1;
        while(temp != NULL && i <= len-k) {
            temp = temp->next;
            i++;
        }
        lastK = temp->val;
        next = temp;
        swap(firstK, lastK);
        curr->val = firstK;
        next->val = lastK;
        return head;
    }
};