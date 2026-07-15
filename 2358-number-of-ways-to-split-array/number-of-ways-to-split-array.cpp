class Solution {
public:
    // dimar's solution
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> s(n);
        s[0] = nums[0];
        for (int x = 1; x < n; x++){
            s[x] = s[x - 1] + nums[x];
        }

        long long hasil = 0;
        long long r = s[n - 1];
        for (int x = 0; x < n - 1; x++){
            if (s[x] >= r - s[x]){
                hasil++;
            }
        }

        return hasil;
    }
};