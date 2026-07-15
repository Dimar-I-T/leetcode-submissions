class Solution {
public:
    // dimar's solution
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> hasil(n);
        for (int x = 0; x < n; x++){
            hasil[x] = nums[nums[x]];
        }

        return hasil;
    }
};