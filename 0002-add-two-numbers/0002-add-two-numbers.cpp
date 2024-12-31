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
     ListNode* reverse(ListNode* head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2->val + carry;
            if(sum < 10){
                temp->next = new ListNode(sum);
                temp = temp->next;
                carry = 0;
            }
            else{
                temp->next = new ListNode(sum%10);
                temp = temp->next;
                carry = sum/10;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
              int sum = temp1->val + carry;
              if(sum < 10){
                temp->next = new ListNode(sum);
                temp = temp->next;
                temp1 = temp1->next;
                carry = 0;
              }
              else{
                temp->next = new ListNode(sum%10);
                temp = temp->next;
                temp1 = temp1->next;
                carry = sum/10;
              }
        }
        while(temp2 != NULL){
              int sum = temp2->val + carry;
              if(sum < 10){
                temp->next = new ListNode(sum);
                temp = temp->next;
                temp2 = temp2->next;
                carry = 0;
              }
              else{
                temp->next = new ListNode(sum%10);
                temp = temp->next;
                temp2 = temp2->next;
                carry = sum/10;
              }
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return dummy->next;
    }
};