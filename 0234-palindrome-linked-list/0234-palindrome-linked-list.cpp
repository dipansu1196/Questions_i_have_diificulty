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
  ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //if the first and second parts are reverse of each other
         ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
   

    ListNode* newHead=reverseList(slow->next);
    ListNode* a= head;
    ListNode* b= newHead;
    while(b!=NULL){
        if(a->val!=b->val) return false;
        a=a->next;
        b=b->next;
    }
 return true;
    }
};