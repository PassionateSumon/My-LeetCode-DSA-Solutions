class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // find the len
        // divide len with K(given)
        // Remender times blocks will be greater and appearing first.. (quotient+1) no elements
        // (k - rem) times block will be apperaing after them....(quotient) no elements
        vector<ListNode*> ans;
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        int quo = (len/k), rem = (len%k);
        int firstPart = rem, eleFirst = (quo+1), secondPart = (k-rem), eleSec = quo;

        temp = head;
        while(firstPart--) {
            ListNode* curr = new ListNode();
            ListNode* help = curr;
            while(eleFirst-- && temp) {
                help->next = new ListNode(temp->val);
                help = help->next;
                temp = temp->next;
            }
            ans.push_back(curr->next);
            eleFirst = (quo+1);
        }

        while(secondPart--) {
            ListNode* curr = new ListNode();
            ListNode* help = curr;
            while(eleSec-- && temp) {
                help->next = new ListNode(temp->val);
                help = help->next;
                temp = temp->next;
            }
            ans.push_back(curr->next);
            eleSec = quo;
        }
        return ans;
    }
};