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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); 
        ListNode* headAwal = &dummy;
        ListNode* head = headAwal;
        while (list1 != NULL && list2 != NULL) {
            int v1 = list1->val;
            int v2 = list2->val;

            if (v1 <= v2) {
                head->next = list1;
                list1 = list1->next;
            }else {
                head->next = list2;
                list2 = list2->next;
            }

            head = head->next;
        }

        while (list1 != NULL) {
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }

        while (list2 != NULL) {
            head->next = list2;
            list2 = list2->next;
            head = head->next;
        }
        
        head->next = NULL;
        return dummy.next;
    }
};