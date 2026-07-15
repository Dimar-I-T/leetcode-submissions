/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // dimar's solution
    bool hasCycle(ListNode *head) {
        int maks = 1e5 + 1;
        while (head != NULL) {
            if (head->val == maks) {
                return true;
            }

            head->val = maks;
            head = head->next;
        }

        return false;
    }
};