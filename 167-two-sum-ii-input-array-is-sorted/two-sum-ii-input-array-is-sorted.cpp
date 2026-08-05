class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int right = numbers[r];
            int left = numbers[l];
            int sum = left + right;
            if (sum == target) {
                break;
            }

            if (sum > target) {
                r--;
            } else {
                l++;
            }
        }

        return {l + 1, r + 1};
    }
};