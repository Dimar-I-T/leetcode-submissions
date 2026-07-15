class Solution {
public:
    // dimar's solution
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> hasil(2*n);
        for (int x = 0; x < n; x++){
            hasil[x] = nums[x];
        }

        for (int x = n; x < 2*n; x++){
            hasil[x] = nums[x - n];
        }

        return hasil;
    }
};