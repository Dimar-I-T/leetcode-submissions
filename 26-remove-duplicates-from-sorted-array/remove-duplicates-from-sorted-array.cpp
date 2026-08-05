class Solution {
public:
    // dimar's solution
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        int n = nums.size();
        int next = nums[0];
        int k = 0;
        for (int x = 1; x < n; x++) {
            if (l >= n) {
                break;
            }

            int curr = nums[x];
            int prev = nums[x - 1];
            if (prev != curr) {
                next = curr;
                nums[l] = next;
                l++;
                k++;
            }
        }

        return k + 1;
    }
};