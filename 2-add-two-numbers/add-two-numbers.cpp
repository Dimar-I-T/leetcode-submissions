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
    int panjangList(ListNode* ll) {
        int n = 0;
        while (ll->next != nullptr) {
            ll = ll->next;
            n++;
        }

        return n + 1;
    }

    void add(ListNode* l1, ListNode* l2) {
        int hasil = 0, carry = 0;
        ListNode* ubahL1 = l1;
        while (ubahL1 != nullptr) {
            ubahL1->val += carry;
            int kanan = 0;
            if (l2 != nullptr) {
                kanan = l2->val;
            }

            //cout << ubahL1->val << " + " << kanan << "\n";

            int jumlah = ubahL1->val + kanan;
            hasil = jumlah % 10;
            carry = jumlah / 10;
            ubahL1->val = hasil;
            ubahL1 = ubahL1->next;
            
            if (l2 != nullptr) {
                l2 = l2->next;
            }else {
                l2 = nullptr;
            }
        }

        if (carry) {
            ListNode* ubahHasil = l1;
            while (ubahHasil->next != nullptr) {
                ubahHasil = ubahHasil->next;
            }

            ListNode* baru = new ListNode(carry);
            ubahHasil->next = baru;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* copy1 = l1;
        ListNode* copy2 = l2;

        int n1 = panjangList(l1), n2 = panjangList(l2);
        ListNode* hasil;
        if (n1 > n2) {
            hasil = copy1;
            add(hasil, copy2);
        } else {
            hasil = copy2;
            add(hasil, copy1);
        }

        return hasil;
    }
};