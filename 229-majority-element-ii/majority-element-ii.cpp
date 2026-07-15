class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n / 3;
        vector<int> res;
        res.reserve(n);
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int &x : nums) {
            freq[x]++;
            if (freq[x] > limit) {
                freq[x] = -INT_MAX;
                res.emplace_back(x);
            }
        }

        return res;
    }
};