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
private:
    // Helper function to insert a node at the tail of the linked list.
    void insertAtTail(ListNode*& head, ListNode*& tail, int val) {
        ListNode* temp = new ListNode(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    // Main function to add two numbers represented by linked lists.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // Initialize carry to handle sum overflow.
        ListNode* ansHead = NULL; // Head of the result list.
        ListNode* ansTail = NULL; // Tail of the result list.

        // Traverse both lists until the end of both and carry is zero.
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0; // Get value from list l1 or 0 if l1 is exhausted.
            int val2 = (l2 != NULL) ? l2->val : 0; // Get value from list l2 or 0 if l2 is exhausted.

            int sum = carry + val1 + val2; // Calculate the sum of current digits and carry.
            int digit = sum % 10; // Get the digit to be stored in the new node.

            insertAtTail(ansHead, ansTail, digit); // Insert the digit at the tail of the result list.

            carry = sum / 10; // Update carry for the next iteration.
            if (l1 != NULL) l1 = l1->next; // Move to the next node in l1 if available.
            if (l2 != NULL) l2 = l2->next; // Move to the next node in l2 if available.
        }

        return ansHead; // Return the head of the resultant linked list.
    }
};
