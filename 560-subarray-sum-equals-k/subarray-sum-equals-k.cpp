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
            //cout << "curr: " << curr << "\n";
            int f = curr - k;
            //cout << "f = curr - k = " << f << "\n";
            //cout << "freq[f] = " << freq[f] << "\n\n";
            if (freq[f] >= 1) {
                res += freq[f];
            }

            freq[curr]++;
        }

        return res;
    }
};