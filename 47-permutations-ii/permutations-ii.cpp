class Solution {
public:
    void backtrack(vector<int> sek, vector<int>& nums, vector<vector<int>>& hasil, vector<bool> visited) {
        int n = nums.size();
        if (n == sek.size()) {
            hasil.push_back(sek);
            return;
        }

        int seb = -100;
        for (int x = 0; x < n; x++) {
            if (visited[x] || (nums[x] == seb && x > 0 && nums[x] == nums[x - 1])) {
                continue;
            }

            seb = -100;
            visited[x] = 1;
            sek.push_back(nums[x]);
            backtrack(sek, nums, hasil, visited);
            visited[x] = 0;
            seb = nums[x];
            sek.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> hasil;
        backtrack({}, nums, hasil, vector<bool>(nums.size()));
        return hasil;
    }
};