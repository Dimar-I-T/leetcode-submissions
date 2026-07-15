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
    // dimar's solution
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* copy = head;
        int n = 0;
        while (head != nullptr) {
            n++;
            head = head->next;
        }

        if (n > 0) {
            k %= n;
        }else {
            return head;
        }

        ListNode* depan = copy;
        ListNode* ubahDepan = depan;
        ListNode* setelah;
        int x = 0;
        while (ubahDepan->next != nullptr) {
            if (x == n - k - 1) {
                setelah = ubahDepan->next;
                ubahDepan->next = nullptr;
                break;
            }

            ubahDepan = ubahDepan->next;
            x++;
        }

        ListNode* ubahSetelah = setelah;
        while (ubahSetelah != nullptr) {
            if (ubahSetelah->next == nullptr) {
                ubahSetelah->next = depan;
                break;
            }

            ubahSetelah = ubahSetelah->next;
        }

        if (k == 0) {
            return depan;
        }else {
            return setelah;
        }
    }
};