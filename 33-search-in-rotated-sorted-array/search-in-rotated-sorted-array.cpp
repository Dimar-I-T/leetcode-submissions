class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int res = INT_MAX;
        int mostLeft = nums[n - 1];
        while (l <= r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            //cout << "l: " << l << "\n";
            //cout << "r: " << r << "\n";
            //cout << "mid: " << mid << "\n";
            //cout << "curr vs target = " << curr << " vs " << target << "\n";
            if (curr == target) {
                //cout << "SAMA!\n";
                return mid;
            }

            // l to mid
            bool bLeft1 = (curr <= target) && (curr <= mostLeft) && (target <= mostLeft);
            bool bLeft2 = (target <= mostLeft) && (target <= curr) && (mostLeft <= curr);
            bool bLeft3 = (mostLeft <= curr) && (mostLeft <= target) && (curr <= target);
            if (bLeft1 || bLeft2 || bLeft3) {
                if (bLeft1) {
                    //cout << "KE KANAN: (curr < target) && (curr < mostLeft) && (target < mostLeft)\n\n";
                }

                if (bLeft2) {
                    //cout << "KE KANAN: (target < mostLeft) && (target < curr) && (mostLeft < curr)\n\n";
                }

                if (bLeft3) {
                    //cout << "KE KANAN: (mostLeft < curr) && (mostLeft < target) && (curr < target)\n\n";
                }

                l = mid + 1;
                continue;
            }

            // r to mid
            bool bRight1 = (target <= curr) && (target <= mostLeft) && (curr <= mostLeft);
            bool bRight2 = (curr <= mostLeft) && (curr <= target) && (mostLeft <= target);
            bool bRight3 = (mostLeft <= target) && (mostLeft <= curr) && (target <= curr);
            if (bRight1 || bRight2 || bRight3) {
                if (bRight1) {
                    //cout << "KE KIRI: (target < curr) && (target < mostLeft) && (curr < mostLeft)\n\n";
                }

                if (bRight2) {
                    //cout << "KE KIRI: (curr < mostLeft) && (curr < target) && (mostLeft < target)\n\n";
                }

                if (bRight3) {
                    //cout << "KE KIRI: (mostLeft < target) && (mostLeft < curr) && (target < curr)\n\n";
                }

                r = mid - 1;
                continue;
            }
        }

        return -1;
    }
};
