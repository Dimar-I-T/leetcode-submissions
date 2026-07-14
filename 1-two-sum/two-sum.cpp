class Solution {
public:
    template <typename T, typename U>
    T mapVal(unordered_map<U, T> &m, U key) {
        auto it = m.find(key);
        if (it != m.end()) {
            return it->second;
        } else {
            return -1;
        }
    } 

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ada;
        ada.reserve(nums.size());
        for (int x = 0; x < nums.size(); x++) {
            int idx = mapVal<int, int>(ada, target - nums[x]);
            if (idx != -1) {
                return {idx, x};
            }

            ada[nums[x]] = x;
        }

        return {};
    }
};