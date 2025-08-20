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
void insertAtTail(ListNode* &head,ListNode* &tail,int val){
    ListNode * temp= new ListNode(val);
    if(head==nullptr){
       head=temp;
       tail=temp;


    }else{
        tail->next=temp;
        tail=temp;
    }
}

 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ansHead= NULL;
        ListNode* ansTail=NULL;

        while(l1 ||l2||carry!=0){
            int val1= l1!=NULL?l1->val:0;
            int val2= l2!=NULL?l2->val:0;
            int sum= carry+val1+val2;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        return ansHead;
    }
};