class Solution {
public:
    // dimar's solution
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), t = 0;
        k %= n;
        vector<int> temp(n);
        for (int x = n - k; x < n; x++){
            temp[t] = nums[x];
            t++;
        }

        for (int x = 0; x < n - k; x++){
            temp[k + x] = nums[x];
        }

        for (int x = 0; x < n; x++){
            nums[x] = temp[x];
        }
    }
};