class Solution {
public:
    // dimar's solution
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> hasil;
        sort(nums.begin(), nums.end());
        for (int x = 1; x < n; x++){
            if (nums[x] == nums[x - 1]){
                hasil.push_back(nums[x]);
            }
        }

        return hasil;
    }
};