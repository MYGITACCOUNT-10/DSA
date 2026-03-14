/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* temp = dummyhead; 
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0; 

        while (head1 || head2 || carry) { // Loop until both lists and carry are exhausted
            int val1 = (head1 != nullptr) ? head1->val : 0; 
            int val2 = (head2 != nullptr) ? head2->val : 0;
            //jab el list lhtm ho jaye and ek nhi

            int x = val1 + val2 + carry; // Include carry in the sum
            carry = x / 10; // Calculate new carry

            temp->next = new ListNode(x % 10); // Create a new node 
            temp = temp->next;

            if (head1) head1 = head1->next; 
            if (head2) head2 = head2->next;
        }

        return dummyhead->next; 
    }
};
