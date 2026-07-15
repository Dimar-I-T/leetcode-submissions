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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0); 
        ListNode* headAwal = &dummy;
        ListNode* awal = headAwal;

        if (head != NULL) {
            awal->next = head;
            awal = awal->next;
            int seb = head->val;
            head = head->next;
            while (head != NULL) {
                int sek = head->val;
                if (seb != sek){
                    seb = sek;
                    awal->next = head;
                    awal = awal->next;
                }
                
                head = head->next;
            }

            awal->next = NULL;
        }

        return dummy.next;
    }
};