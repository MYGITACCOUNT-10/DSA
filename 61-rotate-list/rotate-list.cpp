class Solution {
private:
    int length(ListNode* head) {   
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        int n = length(head);
        k = k % n; 
        if (k == 0) return head; 

        int x = n - k; 
        ListNode* temp1 = head;
        while (--x) {
            temp1 = temp1->next;//if x=3  loop ek baar hi chalega
        }

        ListNode* newhead = temp1->next;
        temp1->next = NULL;

        ListNode* temp2 = newhead;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = head;

        return newhead;
    }
};
