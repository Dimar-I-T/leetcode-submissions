/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // dimar's solution
    unordered_map<TreeNode*, int> b;
    int banyak(TreeNode* t){
        if (t == NULL || (t->left == NULL && t->right == NULL)){
            return 0;
        }

        return b[t] = 1 + max(banyak(t->left), banyak(t->right));
    }

    bool bisa = 1;
    void cek(TreeNode* t){
        if (t == NULL){
            return;
        }

        int kiri = 0, kanan = 0;
        if (t->left != NULL){
            kiri = 1;
        }

        if (t->right != NULL){
            kanan = 1;
        }

        if (abs((kiri + b[t->left]) - (kanan + b[t->right])) > 1){
            bisa = 0;
            return;
        }

        cek(t->left);
        cek(t->right);
    }
    
    bool isBalanced(TreeNode* root) {
        TreeNode* temp = root;
        int bb = banyak(temp);
        cek(root);
        return bisa;
    }
};