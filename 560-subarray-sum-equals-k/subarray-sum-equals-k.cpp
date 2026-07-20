class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for (int x = 1; x < n; x++) {
            nums[x] += nums[x - 1];
        }

        unordered_map<int, int> freq;
        freq.reserve(n);
        freq[0] = 1;
        int res = 0;
        for (int x = 0; x < n; x++) {
            int curr = nums[x];
            int f = curr - k;
            auto itr = freq.find(f);
            int fr = 0;
            if (itr != freq.end()) {
                fr = itr->second;
            }

            if (fr >= 1) {
                res += fr;
            }

            freq[curr]++;
        }

        return res;
    }
};