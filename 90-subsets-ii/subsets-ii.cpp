class Solution {
public:
    void backtrack(int i, vector<int> sek, vector<vector<int>>& hasil, vector<int>& nums) {
        hasil.push_back(sek);
        for (int i1 = i; i1 < nums.size(); i1++) {
            if (i1 > i && nums[i1 - 1] == nums[i1]) {
                continue;
            }

            sek.push_back(nums[i1]);
            backtrack(i1 + 1, sek, hasil, nums);
            sek.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> hasil;
        backtrack(0, {}, hasil, nums);
        return hasil;
    }
};