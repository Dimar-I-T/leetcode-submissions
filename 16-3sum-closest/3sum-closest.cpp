class Solution {
public:
    // dimar's solution
    int threeSumClosest(vector<int>& nums, int target) {
        int hasil = 0;
        int currDiff = INT_MAX;
        int n = nums.size();
        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) {
                for (int z = y + 1; z < n; z++) {
                    int sum = nums[x] + nums[y] + nums[z];
                    int diff = abs(sum - target);
                    if (diff < currDiff) {
                        hasil = sum;
                        currDiff = diff;
                    }
                }
            }
        }

        return hasil;
    }
};