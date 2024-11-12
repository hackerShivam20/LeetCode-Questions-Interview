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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;  // Edge cases: empty list, single node, or no rotation needed.
        }
        
        // Step 1: Compute the length of the list and get the last node.
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Step 2: Find the effective number of rotations.
        k = k % length;
        if (k == 0) {
            return head;  // No rotation needed if k is 0 after mod.
        }
        
        // Step 3: Make the list circular by connecting the tail to the head.
        tail->next = head;
        
        // Step 4: Find the new tail, which will be (length - k - 1) nodes from the head.
        for (int i = 0; i < length - k - 1; i++) {
            head = head->next;
        }
        
        // Step 5: The new head is the next node, and the current head becomes the new tail.
        ListNode* newHead = head->next;
        head->next = nullptr;
        
        return newHead;
    }
};
