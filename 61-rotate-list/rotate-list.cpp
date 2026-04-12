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
        if (!head || !head->next || k == 0) return head;
        // Step 1: find length and last node
        ListNode* cur = head;
        int len = 1;
        while (cur->next != NULL) {
            cur = cur->next;
            len++;
        }
        // Step 2: make it circular
        cur->next = head;
        // Step 3: adjust k
        k = k % len;
        k = len - k;
        // Step 4: move to new tail
        while (k > 0) {
            cur = cur->next;
            k--;
        }
        // Step 5: break circle
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};