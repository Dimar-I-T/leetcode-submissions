class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // dimar's solution
        int n = nums.size();
        unordered_set<int> s;
        s.reserve(n);
        for (int x = 0; x < n; x++) {
            s.insert(nums[x]);
        }

        int res = 0;
        for (int x = 0; x < n; x++) {
            int curr = nums[x];
            if (s.count(curr) == 0) {
                continue;
            }

            int f = 0;
            while (s.count(curr) != 0) {
                f++;
                s.erase(curr);
                curr++;
            }

            curr = nums[x] - 1;
            while (s.count(curr) != 0) {
                f++;
                s.erase(curr);
                curr--;
            }

            res = max(res, f);
        }

        return res;
    }
};