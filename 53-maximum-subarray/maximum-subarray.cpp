class Solution {
public:
    // dimar's solution
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int currSum = -10000;
        int currMax = -10000;
        for (r = 0; r < n; r++) {
            currSum += nums[r];
            if (currSum < nums[r]) {
                currSum = nums[r];
            }

            currMax = max(currMax, currSum);
        }

        return currMax;
    }
};