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
        int carry = 0;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            if(sum < 10){
                ListNode* newNode = new ListNode(sum);
                temp->next = newNode;
                carry = 0;
            }
            else{
                ListNode* newNode = new ListNode(sum%10);
                temp->next = newNode;
                carry = sum/10;
            }
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while(l1 != NULL){
            int sum = l1->val + carry;
            if(sum < 10){
                ListNode* newNode = new ListNode(sum);
                temp->next = newNode;
                carry = 0;
            }
            else{
                ListNode* newNode = new ListNode(sum%10);
                temp->next = newNode;
                carry = sum/10;
            }
            l1 = l1->next;
            temp = temp->next;
        }

        while(l2 != NULL){
            int sum = l2->val + carry;
            if(sum < 10){
                ListNode* newNode = new ListNode(sum);
                temp->next = newNode;
                carry = 0;
            }
            else{
                ListNode* newNode = new ListNode(sum%10);
                temp->next = newNode;
                carry = sum/10;
            }
            l2 = l2->next;
            temp = temp->next;
        }

        if(carry != 0){
            temp->next = new ListNode(carry);
        }
        return dummyNode->next;
    }
};